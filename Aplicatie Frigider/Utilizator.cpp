#include "Utilizator.h"

Utilizator::Utilizator(string parola, int rol, string nume, string prenume, string email, string adresa, string nrTelefon)
    : parola(parola), rol(rol), nume(nume), prenume(prenume), email(email), adresa(adresa), nrTelefon(nrTelefon) {}

string Utilizator::getParola() const {
    return parola;
}

int Utilizator::getRol() const {
    return rol;
}

string Utilizator::getNume() const {
    return nume;
}

string Utilizator::getPrenume() const {
    return prenume;
}

string Utilizator::getEmail() const {
    return email;
}

string Utilizator::getAdresa() const {
    return adresa;
}

string Utilizator::getNrTelefon() const {
    return nrTelefon;
}

vector<string> Utilizator::getAlergeni() const {
    return alergeni;
}

void Utilizator::setAlergeni(const vector<string>& alergeni) {
    this->alergeni = alergeni;
}
