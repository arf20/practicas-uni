#include <stdbool.h>
#include "mips-runtime.h"

/* Ejercicio 1. Traduccion */
int maxima_potencia = 0;

void factorizar_potencia_2(int n) {
  if (n <= 0) {
    print_string("El número ha de ser mayor que cero.\n");
    return;
  }
  
  print_string("Factorización de ");
  print_integer(n);
  print_string(":");
  
  int potencia = 1;
  
  while (n > 0) {
    if (n & 1) {
      print_character(' ');
      print_integer(potencia);
      maxima_potencia = potencia;
    }
    
    potencia = potencia << 1;
    n = n >> 1;
  }
  
  print_character('\n');
}

/* Ejercicio 2. Implementacion */
void generar_serie(int x0, int n, int y, char op) {
  // POR HACER.
}


int main(int argc, char* argv[]) {
  clear_screen();
  while (true) {
    print_string("\n\nExamen de ETC de ensamblador\n\n"
                 " 1. Factorizar en potencias de 2\n"
                 " 2. Generar serie numérica\n"
                 " 0. Salir\n\n"
                 "Elige una opción: ");
    char opc = read_character();
    print_string("\n\n");
    if (opc == '1') {
      print_string("Introduce el número a factorizar: ");
      int n = read_integer();   
      factorizar_potencia_2(n);
    } else if (opc == '2') {
      print_string("Introduce x0: ");
      int x0 = read_integer();
      print_string("Introduce n: ");
      int n = read_integer();
      print_string("Introduce y: ");
      int y = read_integer();
      print_string("Introduce la operación (+ o *): ");
     	char op = read_character();
      generar_serie(x0, n, y, op);
    } else if (opc == '0') {
      print_string("¡Adiós!\n");
      mips_exit(0);
    } else {
      print_string("Opción incorrecta. Pulse cualquier tecla para seguir.\n");
      read_character();
    }
  }
}
