#ifndef GESTORE_SPESE_H
#define GESTORE_SPESE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Spesa{
private:
string nome;
float importo;

public:
//costruttore vuoto
Spesa(){
nome="";
importo=0.0;
}
//costruttore con i dati
Spesa(string n, float i){
    nome=n;
    importo=i;
}
//I GETTER (per leggere in sicurezza)
string getNome()const{return nome;}
float getImporto()const{retunr importo;}

//I SETTER (per scrivere in sicurezza)
void setNome(string n){nome=n;}
void setImporto(float i){
if(i>0){
importo=i;
}else{
importo=0; //se c'e' un errore, forzo a zero
}
}
};

void mostraMenu();
void visualizzaSpese(vector<Spesa>&listaSpese);
void aggiungiSpesa(vector<Spesa>&listaSpese,float &totaleSpese);
void controlloSaldo(float budgetIniziale,float totaleSpese);
void salvaDati(vector<Spesa> &listaSpese, float budgetIniziale);

#endif
