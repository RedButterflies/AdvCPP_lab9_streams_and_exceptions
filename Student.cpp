//
// Created by szyns on 11.01.2024.
//

#include "Student.h"


const string &Student::getImie() const {
    return imie;
}

void Student::setImie(const string &imie) {
    Student::imie = imie;
}

const string &Student::getNazwisko() const {
    return nazwisko;
}

void Student::setNazwisko(const string &nazwisko) {
    Student::nazwisko = nazwisko;
}

basic_string<char> Student::getPlec() const {
    return plec;
}

void Student::setPlec(char plec) {
    Student::plec = plec;
}

int Student::getOcena() const {
    return ocena;
}

void Student::setOcena(int ocena) {
    Student::ocena = ocena;
}

const string &Student::getEmail() const {
    return email;
}

void Student::setEmail(const string &email) {
    Student::email = email;
}

Student::Student(const string &imie, const string &nazwisko, const string &plec, int ocena, const string &email) : imie(
        imie), nazwisko(nazwisko), plec(plec), ocena(ocena), email(email) {}

