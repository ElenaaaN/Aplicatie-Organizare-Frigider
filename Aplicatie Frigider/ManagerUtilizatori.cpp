#include "ManagerUtilizatori.h"
#include <fstream>
#include <iostream>

ManagerUtilizatori::ManagerUtilizatori() {
    incarcaUtilizatoriDinFisier();
}

void ManagerUtilizatori::incarcaUtilizatoriDinFisier() {
    ifstream fisier(filename);
    if (fisier.is_open()) {
        string numeUtilizator, parola, nume, prenume, email, adresa, nrTelefon;
        int rol;
        while (fisier >> numeUtilizator >> parola >> rol >> nume >> prenume >> email >> adresa >> nrTelefon) {
            utilizatori[numeUtilizator] = Utilizator(parola, rol, nume, prenume, email, adresa, nrTelefon);
        }
        fisier.close();
    }
}

void ManagerUtilizatori::salveazaUtilizatoriInFisier() {
    ofstream fisier(filename);
    if (fisier.is_open()) {
        for (const auto& pair : utilizatori) {
            const Utilizator& utilizator = pair.second;
            fisier << pair.first << " "
                << utilizator.getParola() << " "
                << utilizator.getRol() << " "
                << utilizator.getNume() << " "
                << utilizator.getPrenume() << " "
                << utilizator.getEmail() << " "
                << utilizator.getAdresa() << " "
                << utilizator.getNrTelefon() << "\n";
        }
        fisier.close();
    }
}

bool ManagerUtilizatori::autentificare(const string& numeUtilizator, const string& parola) const {
    auto it = utilizatori.find(numeUtilizator);
    if (it != utilizatori.end() && it->second.getParola() == parola) {
        cout << "Autentificare reusita!\n";
        cout << "Cod: " << numeUtilizator << "\n";
        cout << "Nume: " << it->second.getNume() << "\n";
        cout << "Prenume: " << it->second.getPrenume() << "\n";
        cout << "Email: " << it->second.getEmail() << "\n";
        cout << "Adresa: " << it->second.getAdresa() << "\n";
        cout << "Telefon: " << it->second.getNrTelefon() << "\n";
        return true;
    }
    else {
        cout << "Nume utilizator sau parola gresita.\n";
        return false;
    }
}

void ManagerUtilizatori::inregistrareUtilizator(const string& numeUtilizator, const string& parola, int rol, const string& nume, const string& prenume, const string& email, const string& adresa, const string& nrTelefon) {
    if (utilizatori.find(numeUtilizator) == utilizatori.end()) {
        utilizatori[numeUtilizator] = Utilizator(parola, rol, nume, prenume, email, adresa, nrTelefon);
        salveazaUtilizatoriInFisier();
    }
    else {
        cout << "Utilizatorul deja exista.\n";
    }
}

int ManagerUtilizatori::getRol(const string& numeUtilizator) const {
    auto it = utilizatori.find(numeUtilizator);
    if (it != utilizatori.end()) {
        return it->second.getRol();
    }
    else {
        cout << "Utilizatorul nu a fost gasit.\n";
        return -1; // Return an invalid role to indicate the user was not found
    }
}
