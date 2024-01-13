#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Student.h"
#include <algorithm>
#include <iomanip>

using namespace std;
void wyswietlStudentow(vector<Student> &s)
{
    cout<<setw(20)<<setfill('_')<<"Imie"<<setw(20)<<setfill('_')<<"Nazwisko"<<setw(20)<<setfill('_')<<"Plec"<<setw(20)<<setfill('_')<<"Ocena"<<setw(20)<<setfill('_')<<"Email"<<setw(20)<<setfill('_')<<endl;
    for_each(s.begin(),s.end(),[](Student &student){ cout<<student.getImie()<<setw(20)<<setfill('_')<<student.getNazwisko()<<setw(20)<<setfill('_')<<student.getPlec()<<setw(20)<<setfill('_')<<student.getOcena()<<setw(20)<<setfill('_')<<student.getEmail()<<setw(20)<<setfill('_')<<endl;});

}
void zapiszStudenta(const string& sciezka,vector<Student>&studenci)
{
        try{
                string imie;
                string nazwisko;
                string plec;
                int ocena;
                string email;

                ofstream ofstream1;

                ofstream1.open(sciezka,ios::app);
                if(ofstream1.is_open())
                {

                }
                else
                {
                    throw runtime_error( "Plik nie zostal otwarty poprawnie");
                }


            try{
                cout << "Podaj imie studenta: " << endl;
                cin >> imie;
                if(isupper(imie[0]))
                {

                }
                else
                {
                    throw runtime_error("Imie musi zaczynac sie wielka litera! Podaj poprawne imie. ");
                }
                bool ex = all_of(imie.begin() + 1, imie.end(),
                           [](char &el) { return el >= 'a' && el <= 'z';});
                if(ex)
                {

                }
                else
                {
                    throw runtime_error("W imieniu znajduja sie znaki nie bedace literami. Wprowadz poprawne imie");
                }
            }
            catch(runtime_error &r)
            {
                cout<<r.what()<<endl;
                cout << "Podaj imie studenta: " << endl;
                cin >> imie;
                while(!(isupper(imie[0])&&all_of(imie.begin()+1, imie.end(),
                                                 [](char el) { return el >= 'a' && el <= 'z';})))
                {
                    cout<<"Podano niepoprawne imie. Podaj poprawne imie: "<<endl;
                    cin >> imie;
                }

            }
            try {
                cout << "Podaj nazwisko studenta: " << endl;
                cin >> nazwisko;
                if (isupper(nazwisko[0])) {

                } else {
                    throw runtime_error("Nazwisko musi zaczynac sie wielka litera! Podaj poprawne nazwisko. ");
                }
                bool ex = all_of(nazwisko.begin()+1, nazwisko.end(),
                                [](char el) { return el >= 'a' && el <= 'z';});
                if (ex) {

                } else {
                    throw runtime_error("W nazwisku znajduja sie znaki nie bedace literami. Wprowadz poprawne imie");
                }
            }
            catch(runtime_error &r){
                cout<<r.what()<<endl;
                cout << "Podaj nazwisko studenta: " << endl;
                cin >> imie;
                while(!(isupper(nazwisko[0])&&all_of(nazwisko.begin()+1, nazwisko.end(),
                                                 [](char el) { return el >= 'a' && el <= 'z';})))
                {
                    cout<<"Podano niepoprawne nazwisko. Podaj poprawne nazwisko: "<<endl;
                    cin >> nazwisko;
                }
            }
            try {
                cout << "Podaj plec studenta(K lub M): " << endl;
                cin >> plec;
                if (plec != "K" && plec != "M") {
                    throw runtime_error ("Podano nieprawidlowa plec. Wprowadz litere K lub M.");
                }
            }
            catch(runtime_error &r)
            {
                cout<<r.what()<<endl;
                while (plec != "K" && plec != "M") {
                    cout << "Podaj K(kobieta) lub M(mezczyzna): " << endl;
                    cin >> plec;
                }

            }
            try {
                cout << "Podaj ocene studenta: " << endl;
                if (cin>>ocena && ocena>=2 && ocena <=5) {
                } else {
                    throw runtime_error("Podano niepoprawna wartosc. Podaj poprawna ocene ");
                }
            }
            catch(runtime_error &r){
                cout<<r.what()<<endl;
                int a = 0;
                while (a==0) {
                    if(cin>>ocena && ocena>=2 && ocena <=5){
                        a =1;
                    }
                    else
                    {
                        cin.clear();
                        cin.ignore();
                        cout<<"Podaj poprawna ocene:"<<endl;
                    }

                }

            }
            try {
                cout << "Podaj email studenta: " << endl;
                cin >> email;
                bool ex = any_of(email.begin(),email.end(),[](char el){return el=='@';});
                if (ex) {

                }
                else
                {
                    throw runtime_error("Email musi zawierac '@'. Podaj prawidlowy email. ");
                }
            }
            catch(runtime_error &r)
            {
                cout<<r.what()<<endl;
                while (!any_of(email.begin(),email.end(),[](char el){return el=='@';})){
                    cout<<"Email musi zawierac '@'. Podaj prawidlowy email. "<<endl;
                    cin >> email;
                }
            }

            ofstream1<<"\n"+imie+";"+nazwisko+";"+plec+";"+to_string(ocena)+";"+email;
            ofstream1.close();
            studenci.emplace_back(imie,nazwisko,plec,ocena,email);
            cout<<"Zapisano studenta do pliku"<<endl;

        }
        catch(runtime_error &r)
        {
            cout<<r.what()<<endl;
        }


}
void wyswietlenieStudentowONaziwsku(vector<Student>&studenci,const string& nazwisko){
    cout<<"\n\n\nStudenci o nazwisku "<<nazwisko<<":"<<endl;
    cout<<setw(20)<<setfill('_')<<"Imie"<<setw(20)<<setfill('_')<<"Nazwisko"<<setw(20)<<setfill('_')<<"Plec"<<setw(20)<<setfill('_')<<"Ocena"<<setw(20)<<setfill('_')<<"Email"<<setw(20)<<setfill('_')<<endl;
    for_each(studenci.begin(),studenci.end(),[nazwisko](Student &student){if(student.getNazwisko()==nazwisko) cout<<setw(20)<<setfill('_')<<student.getImie()<<setw(20)<<setfill('_')<<student.getNazwisko()<<setw(20)<<setfill('_')<<student.getPlec()<<setw(20)<<setfill('_')<<student.getOcena()<<setw(20)<<setfill('_')<<student.getEmail()<<setw(20)<<setfill('_')<<endl;});
}
void stworzeniePlikowKM(const vector<Student>&studenci)
{
    ofstream ofstreamK;
    ofstreamK.open("k.csv");
    try {
        if (ofstreamK.is_open()) {
            ofstreamK<<"imie;nazwisko;plec;ocena;email";
            for_each(studenci.begin(),studenci.end(),[&ofstreamK](const Student& s){if(s.getPlec()=="K")ofstreamK<<"\n"+s.getImie()+';'+s.getNazwisko()+';'+s.getPlec()+';'+
            to_string(s.getOcena())+';'+s.getEmail();});
            ofstreamK.close();
        }
        else{
            throw runtime_error("Blad przy otwieraniu pliku k.csv!");
        }

    }
    catch(runtime_error &r)
    {
        cout<<r.what()<<endl;
    }

    ofstream ofstreamM;
    ofstreamM.open("m.csv");
    try {
        if (ofstreamM.is_open()) {
            ofstreamM<<"imie;nazwisko;plec;ocena;email";
            for_each(studenci.begin(),studenci.end(),[&ofstreamM](const Student &s){if(s.getPlec()=="M")ofstreamM<<"\n"+s.getImie()+";"+s.getNazwisko()+";"+s.getPlec()+";"+
            to_string(s.getOcena())+";"+s.getEmail();});
            ofstreamM.close();
        } else {
            throw runtime_error("Blad przy otwieraniu pliku m.csv!");
        }
    }
    catch(runtime_error &r) {
        cout<<r.what()<<endl;
    }

}
void wyswietlPierwszeNStudentow(vector<Student>&studenci, int N)
{
    try {
        if (N <= int(studenci.size())) {
            cout << "Pierwsze " << N << " studentow" << endl;
            cout << setw(20) << setfill('_') << "Imie" << setw(20) << setfill('_') << "Nazwisko" << setw(20)
                 << setfill('_') << "Plec" << setw(20) << setfill('_') << "Ocena" << setw(20) << setfill('_') << "Email"
                 << setw(20) << setfill('_') << endl;
            int x = 0;
            for_each(studenci.begin(), studenci.end(), [N, &x](Student &student) {
                if (x < N)
                    cout << setw(20) << setfill('_') << student.getImie() << setw(20) << setfill('_')
                         << student.getNazwisko() << setw(20) << setfill('_') << student.getPlec() << setw(20)
                         << setfill('_') << student.getOcena() << setw(20) << setfill('_') << student.getEmail()
                         << setw(20) << setfill('_') << endl;
                x++;
            });
        } else {
            throw runtime_error(
                    "Liczba studentow, ktora chcesz wyswietlic jest wieksza, niz liczba studentow, ktorych dane znajduja sie w pliku");
        }
    }
    catch(runtime_error &r)
    {
        cout<<r.what()<<endl;
    }
}
void posortowanieStudentowRosnacoWgOceny(vector<Student>&studenci,const string& sciezka)
{

    try {
        sort(studenci.begin(),studenci.end(),[](Student &sA,Student &sB){return sA.getOcena()<sB.getOcena();});
        ofstream ofstream1;
        ofstream1.open(sciezka);
        if (ofstream1.is_open()) {
            ofstream1<<"imie;nazwisko;plec;ocena;email";
            for_each(studenci.begin(),studenci.end(),[&ofstream1](const Student& s){ofstream1<<"\n"+s.getImie()+';'+s.getNazwisko()+';'+s.getPlec()+';'+
                                                                                                                   to_string(s.getOcena())+';'+s.getEmail();});
            ofstream1.close();
        } else {
            throw runtime_error("Blad przy otwieraniu pliku");
        }
    }
    catch(runtime_error &r)
    {
        cout<<r.what()<<endl;
    }
}

int main() {
    //Zadanie9.1
    try {
        ifstream ifstream1;
        ifstream1.open("kod.txt");
        string line;
        if (ifstream1.is_open()) {
            while (!ifstream1.eof()) {
                getline(ifstream1, line, '/');
                cout << line << endl;
                getline(ifstream1, line, '\n');
            }

            ifstream1.close();
        } else {
            throw runtime_error("Plik nie istnieje");
        }
    }
    catch (runtime_error &e)
    {
       cout<<e.what()<<endl;
    }
    //Zadanie9.2
    int suma = 0;
    int liczba = 0;
    int poprzednia = 0;
    int proby_udane = 0;
    int proby_nieudane = 0;
    try {
        while (suma < 21) {


            cout << "Suma: " << suma << endl;
            cout << "Wprowadz liczbe calkowita: " << endl;
            if(cin >> liczba) {
                suma += liczba;
                poprzednia = liczba;
                proby_udane += 1;
            }
            else
            {
                cerr<<"Wprowadzono niepoprawna wartosc. Wprowadz liczbe. "<<endl;
                cin.clear();
                cin.ignore();
                proby_nieudane+=1;
            }

        }
        if (suma == 21) {
            cout << "Suma wynosi 21. Koniec programu" << endl;
            cout<<"Wynik udalo sie osiagnac po: "<<endl;
            cout<<proby_udane<<" probach udanych"<<endl;
            cout<<proby_nieudane<<" probach nieudanych"<<endl;
        } else {
            proby_udane -=1;
            cout<<"Suma: "<<suma<<endl;

            throw runtime_error("Suma przekracza 21");
        }
    }
    catch(runtime_error &x)
    {
        cout<<x.what()<<endl;
        while(suma!=21) {
            cout<<"Suma: "<<suma<<endl;
            cout<<"Podaj ponownie ostatnia liczbe: "<<endl;
            cout<<"Suma: "<<suma-poprzednia<<endl;
           if( cin >> liczba){
               suma -= poprzednia;
            poprzednia = liczba;
            suma += liczba;
            proby_nieudane+=1;
            }
           else{
                cerr<<"Wprowadzono niepoprawna wartosc. Wprowadz liczbe";
                cin.clear();
                cin.ignore();
                proby_nieudane+=1;
            }

        }
        cout<<"Suma jest rowna 21"<<endl;
        cout<<"Wynik udalo sie osiagnac po: "<<endl;
        cout<<proby_udane<<" probach udanych"<<endl;
        cout<<proby_nieudane<<" probach nieudanych"<<endl;


    }
    //Zadanie 9.3
    vector<Student>studenci;
    ifstream ifstreamA;
    try {
        cout << "Wprowadz sciezke pliku" << endl;
        string sciezka;
        cin >> sciezka;
        ifstreamA.open(sciezka);
        if (ifstreamA.is_open()) {
            string line;
            string imie;
            string nazwisko;
            string plec;
            int ocena;
            string email;
            getline(ifstreamA,line,'\n');
            while(!ifstreamA.eof())
            {
                getline(ifstreamA,line,';');
                imie = line;
                getline(ifstreamA,line,';');
                nazwisko = line;
                getline(ifstreamA,line,';');
                plec = line;
                getline(ifstreamA,line,';');
                ocena = stoi(line);
                //ocena = 5;
                getline(ifstreamA,line,'\n');
                email = line;
                //cout<<imie<<nazwisko<<plec<<ocena<<email<<endl;
                studenci.emplace_back(Student(imie,nazwisko,plec,ocena,email));
            }
            ifstreamA.close();


            int a = 1;
            while(a == 1) {
                cout<<"Co chcesz zrobic?\nWybierz jedna z opcji\n1-Wyswietl studentow\n2-Zapisz nowego studenta do pliku"
                      "\n3-Wyswietl studenta o wybranym nazwisku\n"
                      "4-Stworz oddzielne pliki dla kobiet i mezczyzn (k.csv i m.csv)\n5-Wyswietl pierwsze N studentow"
                      "\n6-Posortuj studentow rosnaco wg oceny\n7-Wyjdz z programu"<<endl;
                string wybor;
                cin>>wybor;
                if (wybor == "1") {
                    wyswietlStudentow(studenci);

                } else if (wybor == "2") {
                    zapiszStudenta(sciezka,studenci);

                } else if (wybor == "3") {
                    cout<<"Wprowadz nazwisko: "<<endl;
                    string n;
                    cin>>n;
                    wyswietlenieStudentowONaziwsku(studenci,n);

                } else if (wybor == "4") {
                    stworzeniePlikowKM(studenci);

                } else if (wybor == "5") {
                    try {
                        cout << "Ilu studentow chcesz wyswietlic?" << endl;

                        int n;
                        if (cin >> n) {
                            wyswietlPierwszeNStudentow(studenci, n);

                        } else {
                            throw runtime_error("Wprowadzono niepoprawna liczbe");
                        }
                    }
                    catch (runtime_error &r)
                    {
                        cout<<r.what()<<endl;

                    }

                } else if (wybor == "6") {
                    posortowanieStudentowRosnacoWgOceny(studenci, sciezka);

                }
                else if(wybor == "7")
                {
                    a = 0;
                }
                else {
                    cout
                            << "Wybrano nieprawidlowa opcje. \nWybierz jedna z opcji\n1-Wyswietl studentow\n2-Zapisz nowego studenta do pliku"
                               "\n3-Wyswietl studenta o wybranym nazwisku\n"
                               "4-Stworz oddzielne pliki dla kobiet i mezczyzn (k.csv i m.csv)\n5-Wyswietl pierwsze N studentow"
                               "\n6-Posortuj studentow rosnaco wg oceny\n7-Wyjdz z programu" << endl;
                }
            }
            cout<<"Koniec programu"<<endl;
            //wyswietlStudentow(studenci);
            //zapiszStudenta(sciezka);
            //wyswietlenieStudentowONaziwsku(studenci,"Olejarz");
            //stworzeniePlikowKM(studenci);
            //wyswietlPierwszeNStudentow(studenci,5);
            //posortowanieStudentowRosnacoWgOceny(studenci,sciezka);


        } else {
            throw runtime_error("Taki plik nie istnieje");
        }
    }
    catch (runtime_error &r)
    {
        cout<<r.what()<<endl;
    }



    return 0;
}
