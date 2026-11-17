#include <cmath>
#include <omp.h>
#include "util.h"

#include "binning.h"

#define SIMD_WIDTH  8

using namespace std;

void BinParticles(const InputDataType& inputData, BinsType& outputBins) {
  int *hist = (int*)&outputBins[0][0];

  // Loop through all particle coordinates
  int n = inputData.numDataPoints;
//#pragma omp parallel for simd reduction(+:hist[:nBinsX*nBinsY])
#pragma omp simd reduction(+:hist[:nBinsX*nBinsY])
  for (int i = 0; i < n; i++) {
    // Transforming from cylindrical to Cartesian coordinates:
    const FTYPE x = inputData.r[i]*COS(inputData.phi[i]);
    const FTYPE y = inputData.r[i]*SIN(inputData.phi[i]);

    // Calculating the bin numbers for these coordinates:
    const int iX = int((x - xMin)*binsPerUnitX);
    const int iY = int((y - yMin)*binsPerUnitY);

    // Incrementing the appropriate bin in the counter
    hist[iX * nBinsX + iY]++;
  }
}
