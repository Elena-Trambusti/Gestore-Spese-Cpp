#ifndef GESTORE_SPESE_H
#define GESTORE_SPESE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// 1. LA TUA STRUTTURA DATI
struct spesa {
    string nome;
    float importo;
};
void mostraMenu();
void visualizzaSpese(vector<spesa>&listaSpese);
void aggiungiSpesa(vector<spesa>&listaSpese,float &totaleSpese);
void controlloSaldo(float budgetIniziale,float totaleSpese);
void salvaDati(vector<spesa> &listaSpese, float budgetIniziale);

#endif
