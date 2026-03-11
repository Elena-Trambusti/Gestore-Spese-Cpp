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
	while(fileLettura>>listaSpese[contatoreSpese].nome>>listaSpese[contatoreSpese].importo){
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
			//Controllo che il limite di 100 non sia superato
			if(contatoreSpese<100){
				cout<<"\nInserisci il nome della spesa (senza spazi): "<<endl;
				cin>>listaSpese[contatoreSpese].nome;
				
				cout<<"Inserisci l'importo (es. 45.50): "<<endl;
				cin>>listaSpese[contatoreSpese].importo;
				contatoreSpese++;
				cout<<"Spesa salvata con successo!"<<endl;
			}else{
				cout<<"\nERRORE! Memoria array piena."<<endl;
			}
		}
		else if(scelta==2){
			cout<<"\n--------LISTA DELLE SPESE---------"<<endl;
			//controllo se l'array e' vuoto
			if(contatoreSpese==0){
					cout<<"Nessuna spesa registrata al momento."<<endl;
						cout<<"--------------------------------"<<endl;
			}else{
				//Uso il ciclo for per scorrere i cassetti dell'array fino al numero esatto di spese inserite
				for(int i=0;i<contatoreSpese;i++){
					cout<<i+1<<"."<<listaSpese[i].nome<<"- Euro: "<<listaSpese[i].importo<<endl;
				}
			}
		}
		//calcolo saldo
		else if(scelta==3){
			//Calcolo la differenza tra budget e spese
			float saldoRimanente=budgetIniziale-totaleSpese;
			
				cout<<"\n--------RIEPILOGO SALDO--------"<<endl;
					cout<<"Budget iniziale: Euro "<<budgetIniziale<<endl;
						cout<<"Totale spese: Euro "<<totaleSpese<<endl;
							cout<<"Saldo rimanente: Euro "<<saldoRimanente<<endl;
								cout<<"----------------------------------"<<endl;
							//Avviso l'utente se e' in rosso
							if(saldoRimanente<0){
									cout<<"ATTENZIONE! Hai superato il limite mensile"<<endl;
							}
		}
		//uscita e scrittura file
		else if(scelta==4){
			ofstream fileScrittura("spese.txt");
			
			if(fileScrittura.is_open()){
				fileScrittura<<budgetIniziale<<endl;
				
				for(int i=0;i<contatoreSpese;i++){
					//scrive nome importo prendendoli dalla struct
					fileScrittura<<listaSpese[i].nome<<" "<<listaSpese[i].importo<<endl;
				}
				fileScrittura.close();
				cout<<"\n-> Dati salvati con successo sul disco rigido!"<<endl;
			}else{
				cout<<"\nERRORE CRITICO: Impossibile creare il file di salvataggio!"<<endl;
			}
			
			cout<<"\nUscita in corso. Arrivederci!"<<endl;
	}
		else{
			cout<<"ERRORE! Scelta non valida. Inserisci un numero da 1 a 4."<<endl;
		}
	}while(scelta!=4);//Il programma si ripete finche' l'utente non sceglie un opzione valida
	
	
	return 0;
}

