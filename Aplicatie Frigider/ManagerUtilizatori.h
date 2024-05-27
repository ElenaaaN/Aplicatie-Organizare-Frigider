#ifndef MANAGERUTILIZATORI_H
#define MANAGERUTILIZATORI_H

#include "Utilizator.h"
#include <unordered_map>

class ManagerUtilizatori {
private:
    unordered_map<string, Utilizator> utilizatori;
    string filename = "utilizatori.txt";

    void incarcaUtilizatoriDinFisier();
    void salveazaUtilizatoriInFisier();

public:
    ManagerUtilizatori();
    bool autentificare(const string& numeUtilizator, const string& parola) const;
    void inregistrareUtilizator(const string& numeUtilizator, const string& parola, int rol, const string& nume, const string& prenume, const string& email, const string& adresa, const string& nrTelefon);
    int getRol(const string& numeUtilizator) const;
};

#endif
