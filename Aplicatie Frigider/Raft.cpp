#include "Raft.h"
#include <iostream>
#include <algorithm>

using namespace std;

Raft::Raft(string categorie) : categorie(categorie) {}

string Raft::getCategorie() const {
    return categorie;
}

void Raft::adaugaAliment(const Aliment& aliment) {
    alimente.push_back(aliment);
}

void Raft::eliminaAlimenteExpirate() {
    alimente.erase(
        remove_if(alimente.begin(), alimente.end(), [](const Aliment& aliment) {
            return aliment.esteExpirat();
            }),
        alimente.end()
    );
}

void Raft::afiseazaAlimente() const {
    for (const auto& aliment : alimente) {
        cout << "  Aliment: " << aliment.getNume() << " Data expirarii: " << ctime(&aliment.getDataExpirare());
        cout << "  Subcategorie: " << aliment.getSubcategorie() << endl;
        cout << "  Alergeni: ";
        for (const auto& alergen : aliment.getAlergeni()) {
            cout << alergen << " ";
        }
        cout << endl;
    }
}

bool Raft::cautaAliment(const string& nume) const {
    auto it = find_if(alimente.begin(), alimente.end(), [&nume](const Aliment& aliment) {
        return aliment.getNume() == nume;
        });

    if (it != alimente.end()) {
        cout << "Aliment gasit: " << it->getNume() << " Data expirarii: " << ctime(&it->getDataExpirare()) << endl;
        cout << "Subcategorie: " << it->getSubcategorie() << endl;
        cout << "Alergeni: ";
        for (const auto& alergen : it->getAlergeni()) {
            cout << alergen << " ";
        }
        cout << endl;
        return true;
    }
    else {
        return false;
    }
}

void Raft::eliminaAlimenteAlergenice(const Utilizator& utilizator) {
    auto alergeni = utilizator.getAlergeni();
    alimente.erase(
        remove_if(alimente.begin(), alimente.end(), [&alergeni](const Aliment& aliment) {
            for (const auto& alergen : aliment.getAlergeni()) {
                if (find(alergeni.begin(), alergeni.end(), alergen) != alergeni.end()) {
                    cout << "Eliminat aliment alergic: " << aliment.getNume() << endl;
                    return true;
                }
            }
            return false;
            }),
        alimente.end()
    );
}
