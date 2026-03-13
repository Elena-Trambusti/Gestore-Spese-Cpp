#include "gestore_spese.h"
#include<string>

// --- IL CUORE DEL PROGRAMMA ---
int main() {
    float budgetIniziale = 0.0;
    float totaleSpese = 0.0;
    int scelta = 0;
    
    vector<Spesa>listaSpese;
    
    // LETTURA DI MEMORIA ALL'AVVIO
    ifstream fileLettura("spese.csv");
    
    if(fileLettura.is_open()) {
        fileLettura >> budgetIniziale;

        fileLettura.ignore();
        
        Spesa spesaTemp;
        string importoStringa;
        float importoTemp;
        string nomeTemp;
        
        while(getline(fileLettura,nomeTemp,';')){
            getline(fileLettura,importoStringa,'\n');
            importoTemp=stof(importoStringa);
            //creo l'oggetto
            Spesa spesaCaricata(nomeTemp,importoTemp);
            //aggiungo l'oggetto alla lista
            listaSpese.push_back(spesaCaricata);
            totaleSpese=totaleSpese+importoTemp;
        
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

        //CONTROLLO
        if(cin.fail()){
            cin.clear();
            cin.ignore(10000,'\n');
            scelta=0;
            cout<<"ATTENZIONE!DEvi inserire un numero da 1 a 4!"<<endl;
            continue;
        }
        
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
