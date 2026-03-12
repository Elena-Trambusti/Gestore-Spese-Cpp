#include "gestore_spese.h"

// FUNZIONE PER STAMPARE IL MENU
void mostraMenu() {
    cout << "\n----MENU PRINCIPALE----" << endl;
    cout << "1. Aggiungi una nuova spesa" << endl;
    cout << "2. Mostra la lista delle spese" << endl;
    cout << "3. Controlla il saldo rimanente" << endl;
    cout << "4. Esci e SALVA I DATI" << endl;
    cout << "Seleziona un'opzione (1-4): " << endl;
}

// FUNZIONE PER VISUALIZZARE L'ELENCO DELLE SPESE
void visualizzaSpese(vector<spesa>&listaSpese) {
    cout << "\n--------LISTA DELLE SPESE--------" << endl;
    if(listaSpese.size() == 0) {
        cout << "Nessuna spesa registrata al momento." << endl;
        cout << "---------------------------------" << endl;
    } else {
        for(int i = 0; i <listaSpese.size(); i++) {
            cout << i + 1 << ". " << listaSpese[i].nome << " - Euro: " << listaSpese[i].importo << endl;
        }
    }
}

// FUNZIONE PER AGGIUNGERE UNA NUOVA SPESA
void aggiungiSpesa(vector<spesa>&listaSpese,float &totaleSpese) {
    
      spesa nuovaSpesa;
      
        cout << "\nInserisci il nome della spesa (senza spazi): " << endl;
        cin >> nuovaSpesa.nome;
        
        cout << "Inserisci l'importo (es. 45.50): " << endl;
        cin >> nuovaSpesa.importo;
        
        listaSpese.push_back(nuovaSpesa);
        
        totaleSpese = totaleSpese +nuovaSpesa.importo;
        
        cout << "Spesa salvata con successo!" << endl;
}

// FUNZIONE PER CONTROLLARE IL SALDO
void controlloSaldo(float budgetIniziale, float totaleSpese) {
    float saldoRimanente = budgetIniziale - totaleSpese;
    
    cout << "\n--------RIEPILOGO SALDO--------" << endl;
    cout << "Budget iniziale: Euro " << budgetIniziale << endl;
    cout << "Totale spese: Euro " << totaleSpese << endl;
    cout << "Saldo rimanente: Euro " << saldoRimanente << endl;
    cout << "-------------------------------" << endl;
    
    if(saldoRimanente < 0) {
        cout << "ATTENZIONE! Hai superato il limite mensile!" << endl;
    }
}

// FUNZIONE PER SALVARE I DATI SU FILE
void salvaDati(vector<spesa>&listaSpese, float budgetIniziale) {
    ofstream fileScrittura("spese.txt");
    
    if(fileScrittura.is_open()) {
        fileScrittura << budgetIniziale << endl;
        
        for(int i = 0; i <listaSpese.size(); i++) {
            fileScrittura << listaSpese[i].nome << " " << listaSpese[i].importo << endl;
        }
        fileScrittura.close();
        cout << "\n-> Dati salvati con successo sul disco rigido!" << endl;
        cout << "\nUscita in corso. Arrivederci!" << endl;
    } else {
        cout << "\nERRORE CRITICO: Impossibile creare il file di salvataggio!" << endl;
    }
}
