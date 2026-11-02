#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // 1. Il processo padre inizializza le tre variabili
    int base = 10;
    int altezza = 5;
    int risultato = 0;

    // 2. Creazione del processo figlio
    pid_t pid = fork();

    if (pid < 0) {
        // Gestione errore nella creazione del processo
        perror("Errore durante la fork");
        return 1;
    } 
    else if (pid == 0) {
        // --- CODICE DEL PROCESSO FIGLIO ---
        // Il figlio eredita i valori di base e altezza
        risultato = 2 * (base + altezza);
        printf("[FIGLIO]  Il perimetro del rettangolo e': %d\n", risultato);
        exit(0);
    } 
    else {
        // --- CODICE DEL PROCESSO PADRE ---
        risultato = base * altezza;
        printf("[PADRE]   L'area del rettangolo e': %d\n", risultato);

        // Il padre attende la terminazione del figlio per evitare processi zombie
        wait(NULL);
    }

    return 0;
}
