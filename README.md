## Gestore di Spese in C++
Un'applicazione gestionale da riga di comando sviluppata in C++ per il tracciamento delle spese e il monitoraggio del budget mensile.

## Funzionalità
* Impostazione e verifica dinamica del budget mensile.
* Inserimento continuo di nuove voci di spesa.
* **Memoria Persistente:** I dati vengono salvati in automatico su un file di testo locale (`spese.txt`) alla chiusura, e ricaricati in automatico al riavvio del programma.

## Competenze Tecniche e Struttura del Codice
* **Strutture Dati (`struct`):** Sostituzione dei classici array paralleli con un tipo di dato personalizzato (`Spesa`) per raggruppare nome e importo, garantendo maggiore sicurezza e coesione dei dati.
* **Gestione File (I/O):** Utilizzo della libreria `<fstream>` per operazioni di lettura (`ifstream`) e scrittura (`ofstream`) su disco.
* **Logica Procedurale:** Utilizzo di cicli `do-while` per l'interfaccia utente, cicli `for` per l'iterazione degli array e costrutti condizionali per la gestione degli errori.
