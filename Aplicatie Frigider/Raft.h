#ifndef RAFT_H
#define RAFT_H

#include <string>
#include <vector>
#include "Aliment.h"
#include "Utilizator.h"

using namespace std;

class Raft {
private:
    string categorie;
    vector<Aliment> alimente;
public:
    Raft(string categorie);
    string getCategorie() const;
    void adaugaAliment(const Aliment& aliment);
    void eliminaAlimenteExpirate();
    void afiseazaAlimente() const;
    bool cautaAliment(const string& nume) const;
    void eliminaAlimenteAlergenice(const Utilizator& utilizator);
};

#endif
