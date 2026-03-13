#include "gestore_spese.h"
#include<string>

// --- IL CUORE DEL PROGRAMMA ---
int main() {
    float budgetIniziale = 0.0;
    float totaleSpese = 0.0;
    int scelta = 0;
    
    vector<spesa>listaSpese;
    
    // LETTURA DI MEMORIA ALL'AVVIO
    ifstream fileLettura("spese.csv");
    
    if(fileLettura.is_open()) {
        fileLettura >> budgetIniziale;

        fileLettura.ignore();
        
        spesa spesaTemp;
        string importoStringa;
        
        while(getline(fileLettura, spesaTemp.nome,';')){
            getline(fileLettura,importoStringa,'\n');
            spesaTemp.importo=stof(importoStringa);
            listaSpese.push_back(spesaTemp);
            totaleSpese=totaleSpese+spesaTemp.importo;
        }
        fileLettura.close();
        
        cout << "====MEMORIA CARICATA====" << endl;
        cout << "Trovate"<<listaSpese.size()<<" spese salvate nel precedente utilizzo."<<endl;
    } else {
        cout << "Nessun salvataggio trovato. Inserisci il tuo budget mensile: " << endl;
        cin >> budgetIniziale;
    }
    
    // IL CICLO PRINCIPALE
    do {
        mostraMenu();
        cin >> scelta;
        
        if(scelta == 1) {
            aggiungiSpesa(listaSpese, totaleSpese);
        }
        else if(scelta == 2) {
            visualizzaSpese(listaSpese);
        }
        else if(scelta == 3) {
            controlloSaldo(budgetIniziale, totaleSpese);
        }
        else if(scelta == 4) {
            salvaDati(listaSpese, budgetIniziale);
        }
        else {
            cout << "ERRORE! Scelta non valida. Inserisci un numero da 1 a 4." << endl;
        }
        
    } while(scelta != 4);
    
    return 0;
}
