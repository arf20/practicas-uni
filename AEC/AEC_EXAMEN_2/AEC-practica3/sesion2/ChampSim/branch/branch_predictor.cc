#include "ooo_cpu.h"

#define TAKEN true
#define NOT_TAKEN false

void O3_CPU::initialize_branch_predictor()
{
  // Initialize your branch predictor here
}

uint8_t O3_CPU::predict_branch(uint64_t pc)
{
  return NOT_TAKEN; // Always predict not taken
}

void O3_CPU::last_branch_result(uint64_t pc, uint8_t taken)
{
  // Update your branch predictor here
  // Last branch was taken or not taken?
}
