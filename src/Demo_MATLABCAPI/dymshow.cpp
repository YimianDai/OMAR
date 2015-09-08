#include "mex.h" 
#include "mex.h" 
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) 
{ 
double *data; 
int M,N; 
int i,j; 
data = mxGetPr(prhs[0]); //获得指向矩阵的指针 
M = mxGetM(prhs[0]); //获得矩阵的行数 
N = mxGetN(prhs[0]); //获得矩阵的列数 
for(i = 0; i < M; i++) 
{   for(j = 0; j < N; j++) 
     // mexPrintf("%4.3f  ",data[j*M+i]); 
	mexPrintf("%4.3f  ",data[1]); 
     mexPrintf("\n"); 
  }
} 
