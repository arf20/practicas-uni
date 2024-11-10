#include "ooo_cpu.h"

#define TAKEN true
#define NOT_TAKEN false
#define NUM_ENTRADAS 1024

int contador[NUM_ENTRADAS];
int historia_global;

void O3_CPU::initialize_branch_predictor()
{
	
	for (int i =0; i<NUM_ENTRADAS; i++)
		contador[i]=2;	
	historia_global=0;
}


uint8_t O3_CPU::predict_branch(uint64_t pc)
{
	//return NOT_TAKEN;

	int hash = (pc ^ historia_global) % NUM_ENTRADAS;
	if (contador[hash]<2)
  		return NOT_TAKEN; // Always predict not taken
	else
		return TAKEN;
}

void O3_CPU::last_branch_result(uint64_t pc, uint8_t taken)
{
	int hash = (pc ^historia_global) % NUM_ENTRADAS;
	if(taken)
	{
		if (contador[hash] <3)	
		contador[hash]++;	
	}
	//contador =min(3,contador+1)
	else 
	{
		if (contador[hash]>0)
			contador[hash]--;
		
	}
	historia_global= historia_global << 1;
	if (taken) 
		historia_global++;
	
  	// contador= min(0,contador-1) 
}
