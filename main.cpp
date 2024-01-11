#include <iostream>
#include <fstream>
#include <string>


using namespace std;

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



    return 0;
}
