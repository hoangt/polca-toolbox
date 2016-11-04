// FUNC_ANALYZ: main BLOCK_ABS
// FEAT_VECTOR: [1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 2, 0, 2, 0, 0, 5, 1, 1]
// TEST_VECTOR: [1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 2, 0, 2, 0, 0, 5, 1, 1]
// TEST_LABEL: 0 (CPU)

//# maxForStmtDepth:             1
//# anyFuncCall:                 0
//# anyArrayWriteShifted:        0
//# numIrregularForLoops:        0
//# usesGlobalVars:              1
//# anyIfStmt:                   0
//# allForLoopWithStaticLimit:   1
//# anySIMDloop:                 0
//# anyLoop_Schedule:            0
//# numLoopInvVar:               1
//# numLoopHoistedVarMods:       0
//# numNon1Darray:               2
//# numAuxVarArrayIndex:         0
//# totalNumForLoops:            2
//# numNonNormalizedForLoops:    0
//# numStmtsRollUp:              0
//# numCompoundStmts:            5
//# anyTernaryOp:                1
//# anyUselessStmt:              1


#include "timer.h"
#include "params.h"
#include <stdlib.h>


int image[N][N];

int result[N][N];

int applyThreshold(int value, int threshold)
    {
    int _ret_val_0;
    _ret_val_0 = value > threshold ? 255 : 0;
    return _ret_val_0;
    }

void threshold(int input_image[N][N],
               int threshold,
               int output_image[N][N])
    {
    int c;
    int r;
    int aux;
    for (r = 0; r < N; r++)
        {
    for (c = 0; c < N; c++)
        {
    aux = applyThreshold(input_image[r][c], threshold);
    output_image[r][c] = aux;
    }
    }
    return;
    }

int main()
    {
      {
    char fileName[80];
    int _ret_val_0;
      }
    sprintf(fileName, "%s/%s", DATA_PATH, INPUT_FILE);
    input_dsp_arg(fileName, image, N * N, 1);
#pragma polca def BLOCK_ABS
    {
    int thresholdValue = T;
    {
    int c;
    int r;
    int aux;
    for (r = 0; r < N; r++)
        {
    for (c = 0; c < N; c++)
        {
    {
    int _ret_val_0;
    _ret_val_0 = image[r][c] > thresholdValue ? 255 : 0;
    aux = _ret_val_0;
    }
    result[r][c] = aux;
    }
    }
    0;
    }
    }
    sprintf(fileName, "%s/output.dsp", DATA_PATH);
    output_dsp_arg(fileName, result, N * N, 1);
    _ret_val_0 = 0;
    return _ret_val_0;
    }

void dummy(){
  int x = 0;

    x = x + 2;
}
