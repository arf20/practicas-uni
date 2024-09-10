/* Compilar con: gcc -Wall -g -oprogexamen progexamen.c mips-runtime.c keyio.c */

#include <stdbool.h>
#include "mips-runtime.h"

#define MAX_LEN_NOMBRE_MONTANA 18
#define MAX_MONTANAS 20

struct MontanaRep {                     //     24
  char nombre[MAX_LEN_NOMBRE_MONTANA];  // 0   18 + 2
  int altura;                           // 20  4
};                                      
typedef struct MontanaRep Montana;

Montana montanas[MAX_MONTANAS] = {
  { "Dhaulagiri", 8167 },
  { "Cho Oyu", 8188 },
  { "Lhotse", 8516 },
  { "Makalu", 8485 },
  { "Annapurna", 8091 },
  { "Nanga Parbat", 8126 },
  { "K2", 8611 },
  { "Everest", 8848 },
  { "Manaslu", 8163 },
  { "Kangchenjunga", 8586 },
};
int nmontanas = 10;

/* EJERCICIO 1 */ 

Montana* buscar_montana_mas_alta(void) {
  if (nmontanas <= 0) {
    return NULL; // NULL representa un puntero que apunta a la dirección 0
  } else {
    Montana *candidata = &montanas[0];
    for (int i = 1; i < nmontanas; ++i) {
      if (candidata->altura < montanas[i].altura) {
        print_string(montanas[i].nombre);
        print_string(" es más alta que ");
        print_string(candidata->nombre);
        print_character('\n');
        candidata = &montanas[i];
      }
    }
    return candidata;
  }
}

bool comparar_cadenas(char *a, char* b) {
  while (*a != '\0' && *b != '\0' && *b == *a) {
    ++b;
    ++a;
  }
  return *a == *b;
}

char* copiar_cadena(char* destino, char* origen, int max_size) {
  int i = 0;
  while (i < max_size - 1 && origen[i] != '\0') {
    destino[i] = origen[i];
    ++i;
  }
  destino[i] = '\0';
  return destino;
}

#define MAX_LEN_NOMBRE_PRODUCTO 25
#define MAX_LEN_PEDIDO 100
#define MAX_LEN_ALMACEN 100

struct ProductoAlmacenRep {             //      36
  char nombre[MAX_LEN_NOMBRE_PRODUCTO]; // 0    25 + 3
  int precio;                           // 28   4
  int stock;                            // 32   4
};
typedef struct ProductoAlmacenRep ProductoAlmacen;

ProductoAlmacen almacen[MAX_LEN_ALMACEN] = {
  {"Manzana" ,   10, 100},
  {"Pera",        8, 100},
  {"Sandía",     50,  17},
  {"Plátano",     7,  88},
  {"Fresa",      11, 124},
  {"Cereza",     10, 175},
  {"Melocotón",  13,  75},
};
int nproductos = 7;

void listar_almacen(void) {
  for (int i = 0; i < nproductos; ++i) {
    print_string("Producto: ");
    print_string(almacen[i].nombre);
    print_string("  Precio: ");
    print_integer(almacen[i].precio);
    print_string("  Stock: ");
    print_integer(almacen[i].stock);
    print_character('\n');
  }
}

struct LineaPedidoRep {                       //      32
  char nombre_item[MAX_LEN_NOMBRE_PRODUCTO];  // 0    25 + 3 = 28
  int cantidad;                               // 28   4
};
typedef struct LineaPedidoRep LineaPedido;

struct PedidoRep { 
  int num_items;                              // 0    4
  LineaPedido items[MAX_LEN_PEDIDO];          // 4    100*32
};
typedef struct PedidoRep Pedido;

/* EJERCICIO 2a */

/* argumentos, globales, locales */

ProductoAlmacen* buscar_producto(char* nombre) {
  for (int i = 0; i < nproductos; ++i) {
    if (comparar_cadenas(almacen[i].nombre, nombre)) {
      return &almacen[i];
    }
  }
  return NULL; // NULL representa un puntero que apunta a la dirección 0
}

/* EJERCICIO 2b */

int calcular_precio_pedido(Pedido* pedido) {
  int total = 0;
  for (int i = 0; i < pedido->num_items; ++i) {
    ProductoAlmacen* producto = buscar_producto(pedido->items[i].nombre_item);
    if (producto != NULL) {
      total = total + producto->precio * pedido->items[i].cantidad;
    } else {
      print_string("Aviso: producto no encontrado: " );
      print_string(pedido->items[i].nombre_item);
      print_character('\n');
    }
  }
  return total;
}

void listar_pedido(Pedido* pedido) {
  for (int i = 0; i < pedido->num_items; ++i) {
    print_string("Cantidad: ");
    print_integer(pedido->items[i].cantidad);
    print_string("  Producto: ");
    print_string(pedido->items[i].nombre_item);
    print_string("  Precio: ");
    ProductoAlmacen* p = buscar_producto(pedido->items[i].nombre_item);
    if (p != NULL) {
      print_integer(p->precio);
    } else {
      print_string("Desconocido");
    }
    print_character('\n');
  }
}

void anadir_producto_a_pedido(Pedido* pedido, char* nombre_producto, int cantidad) {
  copiar_cadena(pedido->items[pedido->num_items].nombre_item, nombre_producto, MAX_LEN_NOMBRE_PRODUCTO);
  pedido->items[pedido->num_items].cantidad = cantidad;
  ++pedido->num_items;
}

/* EJERCICIO 3 */

int crear_pedido_llenar_almacen_y_calcular_coste(int stock_minimo, Pedido* pedido) {
  /* POR HACER */
}

int main(int argc, char* argv[]) {
  clear_screen();
  while (true) {
    print_string("\n\nExamen de ETC de ensamblador\n\n"
                 " 1. Buscar la montaña más alta\n"
                 " 2. Calcular precio de pedidos\n"
                 " 3. Calcular coste y crear pedido para llenar el almacén\n"
                 " 0. Salir\n\n"
                 "Elige una opción: ");
    char opc = read_character();
    print_string("\n\n");
    if (opc == '1') {
      print_string("Buscando la montaña más alta…\n");
      Montana* alta = buscar_montana_mas_alta();
      print_string("La montaña más alta es: ");
      print_string(alta->nombre);
    } else if (opc == '2') {
      print_string("Productos en el almacén:\n");
      listar_almacen();
      print_character('\n');
      Pedido tests[] = {
        { 3, { { "Manzana", 4 }, { "Pera", 5 }, { "Sandía", 1 } } },
        { 2, { { "Fresa", 25 }, { "Cereza", 20 } } },
        { 4, { { "Plátano", 3 }, { "Coco", 20 }, { "Manzana", 5 }, { "Melocotón", 2 },  } },
      };
      for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
        print_string("Pedido ");
        print_integer(i);
        print_string(":\n");
        listar_pedido(&tests[i]);
        int p = calcular_precio_pedido(&tests[i]);
        print_string("Precio total: ");
        print_integer(p);
        print_character('\n');
        print_character('\n');
      }
    } else if (opc == '3') {
      print_string("Productos en el almacén:\n");
      listar_almacen();
      print_character('\n');
      struct { int sm; } tests[] = {
        { 100 },
        { 15 },
        { 1000 },
      };
      for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
        Pedido p = { 0 };
        print_string("El coste para tener al menos ");
        print_integer(tests[i].sm);
        print_string(" items de cada producto en el almacén es: ");
        print_integer(crear_pedido_llenar_almacen_y_calcular_coste(tests[i].sm, &p));
        print_character('\n');
        print_string("Hay que pedir los siguientes productos:\n");
        listar_pedido(&p);
        print_character('\n');
      }
    } else if (opc == '0') {
      print_string("¡Adiós!\n");
      mips_exit(0);
    } else {
      print_string("Opción incorrecta. Pulse cualquier tecla para seguir.\n");
      read_character();
    }
  }
}

