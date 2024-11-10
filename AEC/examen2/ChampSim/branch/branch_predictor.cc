#include "ooo_cpu.h"

#define TAKEN true
#define NOT_TAKEN false

constexpr int N = 32;
static int counters[N];

void O3_CPU::initialize_branch_predictor() {
  // Initialize your branch predictor here
  for (int i = 0; i < N; i++)
    counters[i] = 8;
}

uint8_t O3_CPU::predict_branch(uint64_t pc) {
  return counters[pc%N] >= 8; // Always predict not taken
}

void O3_CPU::last_branch_result(uint64_t pc, uint8_t taken) {
  // Update your branch predictor here
  // Last branch was taken or not taken?
  if (taken && (counters[pc%N] < 15)) counters[pc%N]++;
  if (!taken && (counters[pc%N] > 0)) counters[pc%N]--;
}

