#include <stdbool.h>
#include "mips-runtime.h"

#define MAX_ELEMENTOS 10
int conjunto[MAX_ELEMENTOS];
int tam_conjunto = 0;
int total_primos;

int leer_elemento(int pos) {
    if (pos < 0 || pos >= tam_conjunto) {
        print_string("Error: Posición inválida\n");
        mips_exit(1);
    } else {
        return conjunto[pos];
    }
}

void escribir_elemento(int pos, int valor) {
    if (pos < 0 || pos >= MAX_ELEMENTOS) {
        print_string("Error: Posición inválida\n");
        mips_exit(1);
    }
    conjunto[pos] = valor;
    if (pos >= tam_conjunto) {
        tam_conjunto = pos + 1;
    }
}

/* Devuelve true si num es primo, false en otro caso */
bool es_primo(int num) {
  if (num < 2) {
    return false;
  } else if (num == 2) {
    return true;
  } else if (num % 2 == 0) {
    return false;
  } else {
    for (int i = 3; i < num; i += 2) {
      if (num % i == 0) {
        return false;
      }
    }
  }
  return true;
}



/* EJERCICIO 1. TRADUCIR. */
/* void ordenar(void);
 * Ordena un conjunto de números enteros.
 */
void ordenar(void) {
    for (int i = 0; i < tam_conjunto - 1; i++) {
        for (int j = 0; j < tam_conjunto - i - 1; j++) {
            int elemento = leer_elemento(j);
            int elemento_siguiente = leer_elemento(j + 1);
            if (elemento > elemento_siguiente) {
                escribir_elemento(j, elemento_siguiente);
                escribir_elemento(j + 1, elemento);
            }
        }
    }
}



/* EJERCICIO 2. IMPLEMENTAR */
/* void mostrar_y_contar_primos(int a, int b);
 * Muestra los primos entre a y b y los cuenta en la variable global «total_primos».
 * Usa la función «bool es_primo(int num)» ya implementada.
 */
void mostrar_y_contar_primos(int a, int b) {
  /* POR HACER */
}



int main(int argc, char* argv[]) {
  clear_screen();
  while (true) {
    print_string("\n\nExamen Parcial de ETC de ensamblador\n\n"
                 " 1. Ordena conjunto\n"
                 " 2. Cuenta primos\n"
                 " 0. Salir\n\n"
                 "Elige una opción: ");
    char opc = read_character();
    print_string("\n\n");
    if (opc == '1') {
      escribir_elemento(0,7);
      escribir_elemento(1,1);
      escribir_elemento(2,10);
      escribir_elemento(3,2);
      escribir_elemento(4,9);
      escribir_elemento(5,8);
      escribir_elemento(6,5);
      escribir_elemento(7,6);
      escribir_elemento(8,3);
      escribir_elemento(9,4);
      print_string("El conjunto de elementos a ordenar es:\n");
      print_character('{');
      for (int i = 0; i < tam_conjunto; i++) {
        print_integer(leer_elemento(i));
        if (i < tam_conjunto - 1) {
          print_string(", ");
        }
      }
      print_character('}');
      print_character('\n');
      ordenar();
      print_character('\n');
      print_string("El resultado de la ordenación es:\n");
      print_character('{');
      for (int i = 0; i < tam_conjunto; i++) {
        print_integer(leer_elemento(i));
        if (i < tam_conjunto - 1) {
          print_string(", ");
        }
      }
      print_character('}');
      print_character('\n');
    } else if (opc == '2') {
      print_string("Límite inferior de búsqueda de primos: ");
      int a = read_integer();
      print_string("Límite superior de búsqueda de primos: ");
      int b = read_integer();
      total_primos = 0;
      mostrar_y_contar_primos(a, b);
      print_string("Número total de primos encontrados: ");
      print_integer(total_primos);
      print_character('\n');
    } else if (opc == '0') {
      print_string("¡Adiós!\n");
      mips_exit(0);
    } else {
      print_string("Opción incorrecta. Pulse cualquier tecla para seguir.\n");
      read_character();
    }
  }
}
