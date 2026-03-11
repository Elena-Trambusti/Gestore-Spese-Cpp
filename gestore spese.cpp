#include<iostream>
#include<string>
#include<fstream>

using namespace std;
//LA STRUTTURA
struct spesa{
	string nome;
	float importo;
};

//FUNZIONE PER STAMPARE IL MENU A SCHERMO
void mostraMenu(){
	    cout<<"\n-----MENU PRINCIPALE-----"<<endl;
		cout<<"1.Aggiungi una nuova spesa"<<endl;
		cout<<"2.Mostra la lista delle spese"<<endl;
		cout<<"3.Controlla il saldo rimanente"<<endl;
		cout<<"4.Esci e SALVA I DATI"<<endl;
		cout<<"Seleziona un opzione (1-4): "<<endl;
}

// 2. FUNZIONE PER AGGIUNGERE UNA NUOVA SPESA (Opzione 1)
void aggiungiSpesa(spesa listaSpese[], int &contatoreSpese, float &totaleSpese) {
    if(contatoreSpese < 100) {
        cout << "\nInserisci il nome della spesa (senza spazi): " << endl;
        cin >> listaSpese[contatoreSpese].nome;
        
        cout << "Inserisci l'importo (es. 45.50): " << endl;
        cin >> listaSpese[contatoreSpese].importo;
        
        totaleSpese = totaleSpese + listaSpese[contatoreSpese].importo;
        contatoreSpese++;
        
        cout << "Spesa salvata con successo!" << endl;
    } else {
        cout << "\nERRORE! Memoria array piena." << endl;
    }
}

// 3. FUNZIONE PER VISUALIZZARE L'ELENCO DELLE SPESE (Opzione 2)
void visualizzaSpese(spesa listaSpese[], int contatoreSpese) {
    cout << "\n--------LISTA DELLE SPESE--------" << endl;
    if(contatoreSpese == 0) {
        cout << "Nessuna spesa registrata al momento." << endl;
        cout << "---------------------------------" << endl;
    } else {
        for(int i = 0; i < contatoreSpese; i++) {
            cout << i + 1 << ". " << listaSpese[i].nome << " - Euro: " << listaSpese[i].importo << endl;
        }
    }
}

// 4. FUNZIONE PER CONTROLLARE IL SALDO (Opzione 3)
void controllaSaldo(float budgetIniziale, float totaleSpese) {
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

// 5. FUNZIONE PER SALVARE I DATI SU FILE (Opzione 4)
void salvaDati(spesa listaSpese[], int contatoreSpese, float budgetIniziale) {
    ofstream fileScrittura("spese.txt");
    
    if(fileScrittura.is_open()) {
        fileScrittura << budgetIniziale << endl;
        
        for(int i = 0; i < contatoreSpese; i++) {
            fileScrittura << listaSpese[i].nome << " " << listaSpese[i].importo << endl;
        }
        fileScrittura.close();
        cout << "\n-> Dati salvati con successo sul disco rigido!" << endl;
        cout << "\nUscita in corso. Arrivederci!" << endl;
    } else {
        cout << "\nERRORE CRITICO: Impossibile creare il file di salvataggio!" << endl;
    }
}

int main(){
	//Dichiaro le variabili principali
	float budgetIniziale = 0.0;
	float totaleSpese = 0.0;
	int scelta = 0;
	
	//array
	spesa listaSpese[100];
	int contatoreSpese = 0; //Tiene traccia delle spese inserite
	
	//LETTURA DI MEMORIA ALL'AVVIO
	ifstream fileLettura("spese.txt");
	
	if(fileLettura.is_open()){
		fileLettura>>budgetIniziale;

	//legge dal file e riempie la nostra struct
	while(contatoreSpese<100&&fileLettura>>listaSpese[contatoreSpese].nome>>listaSpese[contatoreSpese].importo){
		totaleSpese=totaleSpese+
		listaSpese[contatoreSpese].importo;
		contatoreSpese++;
	}
	fileLettura.close();
	
	cout<<"=====MEMORIA CARICATA====="<<endl;
	cout<<"Trovate "<<contatoreSpese<<"spese salvete nel precedente utilizzo.\n"<<endl;
   }else{
  cout<<"Nessun salvataggio trovato. Inserisci il tuo budget mensile: "<<endl;
  cin>>budgetIniziale;
  }
	
	//Il ciclo principale che gestisce il Menu
	do{
		mostraMenu();
		cin>>scelta;
		
		//Struttura condizionale per smistare le scelte
		if(scelta==1){
			            aggiungiSpesa(listaSpese, contatoreSpese, totaleSpese);
		}
		else if(scelta==2){
			visualizzaSpese(listaSpese, contatoreSpese);
        }
		else if(scelta==3){
			controllaSaldo(budgetIniziale, totaleSpese);
        }
		else if(scelta==4){
			   salvaDati(listaSpese, contatoreSpese, budgetIniziale);
		}
	}while(scelta!=4);//Il programma si ripete finche' l'utente non sceglie un opzione valida
	
	
	return 0;
}


