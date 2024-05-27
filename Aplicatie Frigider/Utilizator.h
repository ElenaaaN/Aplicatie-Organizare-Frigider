#ifndef UTILIZATOR_H
#define UTILIZATOR_H

#include <string>
#include <vector>

using namespace std;

class Utilizator {
private:
    string parola;
    int rol;
    string nume;
    string prenume;
    string email;
    string adresa;
    string nrTelefon;
    vector<string> alergeni;

public:
    Utilizator(string parola, int rol, string nume, string prenume, string email, string adresa, string nrTelefon);
    string getParola() const;
    int getRol() const;
    string getNume() const;
    string getPrenume() const;
    string getEmail() const;
    string getAdresa() const;
    string getNrTelefon() const;
    vector<string> getAlergeni() const;
    void setAlergeni(const vector<string>& alergeni);
};

#endif
