#include "gestore_spese.h"

// --- IL CUORE DEL PROGRAMMA ---
int main() {
    float budgetIniziale = 0.0;
    float totaleSpese = 0.0;
    int scelta = 0;
    
    spesa listaSpese[100];
    int contatoreSpese = 0; 
    
    // LETTURA DI MEMORIA ALL'AVVIO
    ifstream fileLettura("spese.txt");
    
    if(fileLettura.is_open()) {
        fileLettura >> budgetIniziale;
        
        while(contatoreSpese < 100 && fileLettura >> listaSpese[contatoreSpese].nome >> listaSpese[contatoreSpese].importo) {
            totaleSpese = totaleSpese + listaSpese[contatoreSpese].importo;
            contatoreSpese++;
        }
        fileLettura.close();
        
        cout << "====MEMORIA CARICATA====" << endl;
        cout << "Trovate " << contatoreSpese << " spese salvate nel precedente utilizzo.\n" << endl;
    } else {
        cout << "Nessun salvataggio trovato. Inserisci il tuo budget mensile: " << endl;
        cin >> budgetIniziale;
    }
    
    // IL CICLO PRINCIPALE
    do {
        mostraMenu();
        cin >> scelta;
        
        if(scelta == 1) {
            aggiungiSpesa(listaSpese, contatoreSpese, totaleSpese);
        }
        else if(scelta == 2) {
            visualizzaSpese(listaSpese, contatoreSpese);
        }
        else if(scelta == 3) {
            controllaSaldo(budgetIniziale, totaleSpese);
        }
        else if(scelta == 4) {
            salvaDati(listaSpese, contatoreSpese, budgetIniziale);
        }
        else {
            cout << "ERRORE! Scelta non valida. Inserisci un numero da 1 a 4." << endl;
        }
        
    } while(scelta != 4);
    
    return 0;
}
