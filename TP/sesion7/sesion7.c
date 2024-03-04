#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "bombo.h"

#define TAM_B1 100000   /* numeros */
#define TAM_B2 1807     /* premios */

int error;

int main() {
    /* Comprar boleto */
    int numero;
    printf("Introduce el numero de 0 a 99999> ");
    scanf("%d", &numero);

    /* Sorteo */
    typedef struct {
        int numero;
        int premio;
    } numero_premio;

    numero_premio sorteo[TAM_B2];

    int premiado = 0, year = 0;
    while (!premiado) {
        /* Construir bombos */
        srand(time(NULL));
        Bombo b1, b2;
        if ((b1 = BomboCrea(TAM_B1)) == NULL) {
            fprintf(stderr, BomboMensajeError(b1, error));
            return 1;
        }
        if ((b2 = BomboCrea(TAM_B2)) == NULL) {
            fprintf(stderr, BomboMensajeError(b2, error));
            BomboLibera(b1);
            return 1;
        }

        /* Insertar bolas */
        for (int i = 0; i < TAM_B1; i++)
            BomboInserta(b1, i);

        BomboInserta(b2, 4000000);
        BomboInserta(b2, 1250000);
        BomboInserta(b2, 500000);
        BomboInserta(b2, 200000);
        BomboInserta(b2, 200000);
        for (int i = 0; i < 8; i++)
            BomboInserta(b2, 60000);
        for (int i = 0; i < 1794; i++)
            BomboInserta(b2, 1000);

        /* Sortear */
        for (int i = 0; i < TAM_B2; i++) {
            if ((sorteo[i].numero = BomboExtrae(b1)) < 0) {
                fprintf(stderr, BomboMensajeError(b1, error));
                BomboLibera(b1);
                BomboLibera(b2);
                return -1;
            }
            if ((sorteo[i].premio = BomboExtrae(b2)) < 0) {
                fprintf(stderr, BomboMensajeError(b2, error));
                BomboLibera(b1);
                BomboLibera(b2);
                return -1;
            }
        }

        BomboLibera(b1);
        BomboLibera(b2);
        
        for (int i = 0; i < TAM_B2; i++)
            if (sorteo[i].numero == numero) {
                printf("Año %d: Numero premiado con %d€\n", year, sorteo[i].premio);
                premiado = 1;
            }
        //if (!premiado) printf("Numero no premiado\n");

        year++;
    }
        

    /* Escribir fichero */
    FILE *fich = fopen("premios.txt", "w");
    fprintf(fich, "NUMERO,PREMIO\n");
    for (int i = 0; i < TAM_B2; i++)
        fprintf(fich, "%d,%d\n", sorteo[i].numero, sorteo[i].premio);
    fclose(fich);

    return 0;
}