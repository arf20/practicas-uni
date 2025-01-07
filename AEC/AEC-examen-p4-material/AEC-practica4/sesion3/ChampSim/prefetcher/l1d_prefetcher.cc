#include "cache.h"

void CACHE::l1d_prefetcher_initialize() 
{
  // Initialize yout L1D prefetcher here
}

void CACHE::l1d_prefetcher_operate(uint64_t addr, uint64_t pc, uint8_t cache_hit, uint8_t type)
{
  static uint64_t paddr;

  if (addr > paddr)
    prefetch_line(pc, addr, addr + (2 << LOG2_BLOCK_SIZE), FILL_L1);
  else
    prefetch_line(pc, addr, addr - (2 << LOG2_BLOCK_SIZE), FILL_L1);

  paddr = addr;
}

void CACHE::l1d_prefetcher_cache_fill(uint64_t addr, uint32_t set, uint32_t way, uint8_t prefetch, uint64_t evicted_addr, uint32_t metadata_in)
{
  // This function is called every time a new block is stores in cache
  // Not necesary to use it in the AEC lab.
}

void CACHE::l1d_prefetcher_final_stats()
{
  // Here you could add some prefetcher final stats
}

