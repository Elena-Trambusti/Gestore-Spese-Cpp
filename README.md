# 💰 Gestore Spese Mensili in C++

## 🎯 Obiettivo del Progetto
Questo software nasce dalla necessità di unire la mia esperienza decennale nella gestione amministrativa e database CRM con la logica della programmazione C++. È un applicativo gestionale che permette il monitoraggio del budget mensile, garantendo ordine, precisione e persistenza dei dati.

## 🏗️ Architettura del Software (Refactoring Modulare)
Il progetto è stato sviluppato seguendo i canoni professionali della **Modularizzazione**, separando nettamente la logica di business dalla gestione dell'input utente:

* **`main.cpp`**: Punto di ingresso del programma e gestione del ciclo principale.
* **`gestore_spese.h`**: Header file contenente la definizione della `struct` e i prototipi delle funzioni (Header Guards inclusi).
* **`gestore_spese.cpp`**: Implementazione dettagliata di tutte le funzioni di calcolo e gestione.

## 🚀 Competenze Tecniche Implementate
* **Gestione Dinamica**: Utilizzo di `std::vector` per una gestione della memoria elastica e scalabile.
* **Persistenza dei Dati**: Integrazione della libreria `<fstream>` per il salvataggio e il caricamento automatico delle spese da file di testo (`spese.txt`).
* **Ottimizzazione della Memoria**: Utilizzo del **Passaggio per Riferimento (&)** per migliorare le prestazioni ed evitare copie inutili di oggetti complessi.
* **Clean Code**: Codice commentato e strutturato per facilitare la manutenzione futura.

## 🛠️ Come eseguirlo
1. Clona il repository.
2. Compila i tre file insieme: `g++ main.cpp gestore_spese.cpp -o gestore`.
3. Avvia l'eseguibile: `./gestore`.

---
*Progetto realizzato da Elena Trambusti nel percorso di re-skilling IT presso ITI Galileo Galilei.*
