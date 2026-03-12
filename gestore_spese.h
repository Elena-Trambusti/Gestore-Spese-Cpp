#ifndef GESTORE_SPESE_H
#define GESTORE_SPESE_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// 1. LA TUA STRUTTURA DATI
struct spesa {
    string nome;
    float importo;
};

// 2. I "TITOLI" DELLE TUE FUNZIONI (Dichiarazioni)
void mostraMenu();
void visualizzaSpese(spesa listaSpese[], int contatoreSpese);
void aggiungiSpesa(spesa listaSpese[], int &contatoreSpese, float &totaleSpese);
void controllaSaldo(float budgetIniziale, float totaleSpese);
void salvaDati(spesa listaSpese[], int contatoreSpese, float budgetIniziale);

#endif
