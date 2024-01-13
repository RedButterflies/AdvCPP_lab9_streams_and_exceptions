//
// Created by szyns on 11.01.2024.
//

#ifndef WYJATKI_STUDENT_H
#define WYJATKI_STUDENT_H
#include <string>
#include <iostream>
using namespace std;

class Student {
private:
    string imie;
    string nazwisko;
    string plec;
    int ocena;
    string email;
public:

    const string &getImie() const;

    void setImie(const string &imie);

    const string &getNazwisko() const;

    void setNazwisko(const string &nazwisko);

    basic_string<char> getPlec() const;

    void setPlec(char plec);

    int getOcena() const;

    void setOcena(int ocena);

    const string &getEmail() const;

    void setEmail(const string &email);

    Student(const string &imie, const string &nazwisko, const string &plec, int ocena, const string &email);

};


#endif //WYJATKI_STUDENT_H
