// ESERCIZIO 001 - data: 25/09/2020
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int Nalunni;
    float R;
    int a;
    int giorni;

    // chiedo all'utente di inseirire i valori delle varie variabili (Nalunni, R, giorni)
    printf("inserisci il numero di studenti della classe(es:21): ");
    scanf("%d", &Nalunni);
    printf("inserisci il numero di persone che contagia il contagiato(es:1.4): ");
    scanf("%f", &R);
    printf("iserisci il numero di giorni massimo(1 mese): ");
    scanf("%d", &giorni);

    float Ncontagi_gg[giorni];

    //inizializzazione e stampa del primo valore dell'array
    Ncontagi_gg[0] = 1; // cioe il contagiato
    printf("Giorno 0, numero contagi %.0f\n", Ncontagi_gg[0]);

    for (a = 1; a <= giorni; a++) {
        Ncontagi_gg[a] = R * Ncontagi_gg[a-1];

        //stampa numero di contagiati nella giornata
        printf("Giorno %d, numero contagi %.0f\n", a, Ncontagi_gg[a]);

        // controllo se ci sono pi� contagiati totali che sani totali e se � vero faccio terminare il ciclo
        if (Nalunni < Ncontagi_gg[a]) {
            printf("\n\tCon un fattore di rischio %.2f", R);
            printf("\n\tCi vogliono %d giorni per contagiare tutti\n", a);
            a = giorni;
        }
    }
    return 0;
}
