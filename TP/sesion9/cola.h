#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

// Tipo de datos de los elementos de las colas, el cual
// representa pacientes de un consultorio.
typedef struct {
	char nombre[30];
	char DNI[10];
} data_t;

// Tipo de datos de las colas.
typedef struct queue_s queue_t;

// Devuelve una cola vacía.
queue_t *queue_create();

// Libera la memoria asignada a la cola c.
void queue_free(queue_t *c);

// Inserta el elemento e en el último lugar de la cola c.
queue_t *queue_insert(queue_t *c, data_t e);

// Devuelve el elemento situado en primer lugar de la cola c.
data_t queue_pop(queue_t *c);

// Devuelve 0 si la cola c no es vacía, y 1 en caso contrario.
int queue_empty(queue_t *c);

#endif // COLA_H_ INCLUDED

