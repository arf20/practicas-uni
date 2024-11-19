#include "ooo_cpu.h"

#define TAKEN true
#define NOT_TAKEN false

static int contador;

void O3_CPU::initialize_branch_predictor() {
        contador = 32;
}

uint8_t O3_CPU::predict_branch(uint64_t pc) {
  return contador >= 32;
}

void O3_CPU::last_branch_result(uint64_t pc, uint8_t taken) {
    if (taken && (contador < 63)) contador++;
    if (!taken && (contador > 0)) contador--;
}

