#include <iostream>
#include "ManagerUtilizatori.h"

enum Role {
    CLIENT = 0,
    ANGAJAT = 1
};

void meniuClient() {
    cout << "Meniu Client\n";
    // Operatiuni specifice clientului
}

void meniuAngajat() {
    cout << "Meniu Angajat\n";
    // Operatiuni specifice angajatului
}

int main() {
    ManagerUtilizatori manager;
    string numeUtilizator, parola;

    cout << "Nume utilizator: ";
    cin >> numeUtilizator;
    cout << "Parola: ";
    cin >> parola;

    if (manager.autentificare(numeUtilizator, parola)) {
        int rol = manager.getRol(numeUtilizator);
        if (rol == Role::CLIENT) {
            meniuClient();
        }
        else if (rol == Role::ANGAJAT) {
            meniuAngajat();
        }
        else {
            cout << "Rol necunoscut.\n";
        }
    }

    return 0;
}
