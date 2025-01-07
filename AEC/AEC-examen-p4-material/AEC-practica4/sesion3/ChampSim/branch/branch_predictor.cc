#include "ooo_cpu.h"

#define TAKEN true
#define NOT_TAKEN false

#define NUM_CONTADORES 1024

int contador[NUM_CONTADORES];
int historia_global;

void O3_CPU::initialize_branch_predictor()
{
  for (int i = 0; i < NUM_CONTADORES; i++)
    contador[i] = 2;
  historia_global = 0;
}

uint8_t O3_CPU::predict_branch(uint64_t ip)
{
  int index = (ip ^ historia_global) % NUM_CONTADORES;
  return (contador[index] >> 1) & 1;
}

void O3_CPU::last_branch_result(uint64_t ip, uint8_t taken)
{
  int index = (ip ^ historia_global) % NUM_CONTADORES;
  if (taken) {
    if (contador[index] < 3) contador[index]++;
  }
  else {
    if (contador[index] > 0) contador[index]--;
  }

  historia_global = historia_global << 1;
  if (taken) historia_global++;
}
