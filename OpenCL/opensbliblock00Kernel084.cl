//
// auto-generated by ops.py
//

#ifdef OCL_FMA
#pragma OPENCL FP_CONTRACT ON
#else
#pragma OPENCL FP_CONTRACT OFF
#endif
#pragma OPENCL EXTENSION cl_khr_fp64:enable

#define OPS_3D
#define OPS_API 2
#define OPS_NO_GLOBALS
#include "ops_macros.h"
#include "ops_opencl_reduction.h"

#ifndef MIN
#define MIN(a,b) ((a<b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a>b) ? (a) : (b))
#endif
#ifndef SIGN
#define SIGN(a,b) ((b<0.0) ? (a*(-1)) : (a))
#endif
#define OPS_READ 0
#define OPS_WRITE 1
#define OPS_RW 2
#define OPS_INC 3
#define OPS_MIN 4
#define OPS_MAX 5
#define ZERO_double 0.0;
#define INFINITY_double INFINITY;
#define ZERO_float 0.0f;
#define INFINITY_float INFINITY;
#define ZERO_int 0;
#define INFINITY_int INFINITY;
#define ZERO_uint 0;
#define INFINITY_uint INFINITY;
#define ZERO_ll 0;
#define INFINITY_ll INFINITY;
#define ZERO_ull 0;
#define INFINITY_ull INFINITY;
#define ZERO_bool 0;

//user function

void opensbliblock00Kernel084(ptr_double rhoE_B0,
  ptr_double rhou1_B0,
  ptr_double rhou0_B0,
  ptr_double rho_B0,
  ptr_double rhou2_B0)
{
   OPS_ACCS(rho_B0, 0,-1,0) = OPS_ACCS(rho_B0, 0,1,0);

   OPS_ACCS(rhou0_B0, 0,-1,0) = OPS_ACCS(rhou0_B0, 0,1,0);

   OPS_ACCS(rhou1_B0, 0,-1,0) = -1.0*OPS_ACCS(rhou1_B0, 0,1,0);

   OPS_ACCS(rhou2_B0, 0,-1,0) = OPS_ACCS(rhou2_B0, 0,1,0);

   OPS_ACCS(rhoE_B0, 0,-1,0) = OPS_ACCS(rhoE_B0, 0,1,0);

   OPS_ACCS(rho_B0, 0,-2,0) = OPS_ACCS(rho_B0, 0,2,0);

   OPS_ACCS(rhou0_B0, 0,-2,0) = OPS_ACCS(rhou0_B0, 0,2,0);

   OPS_ACCS(rhou1_B0, 0,-2,0) = -1.0*OPS_ACCS(rhou1_B0, 0,2,0);

   OPS_ACCS(rhou2_B0, 0,-2,0) = OPS_ACCS(rhou2_B0, 0,2,0);

   OPS_ACCS(rhoE_B0, 0,-2,0) = OPS_ACCS(rhoE_B0, 0,2,0);

}


__kernel void ops_opensbliblock00Kernel084(
__global double* restrict arg0,
__global double* restrict arg1,
__global double* restrict arg2,
__global double* restrict arg3,
__global double* restrict arg4,
const int base0,
const int base1,
const int base2,
const int base3,
const int base4,
const int size0,
const int size1,
const int size2 ){


  int idx_y = get_global_id(1);
  int idx_z = get_global_id(2);
  int idx_x = get_global_id(0);

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    ptr_double ptr0 = { &arg0[base0 + idx_x * 1*1 + idx_y * 1*1 * xdim0_opensbliblock00Kernel084 + idx_z * 1*1 * xdim0_opensbliblock00Kernel084 * ydim0_opensbliblock00Kernel084], xdim0_opensbliblock00Kernel084, ydim0_opensbliblock00Kernel084};
    ptr_double ptr1 = { &arg1[base1 + idx_x * 1*1 + idx_y * 1*1 * xdim1_opensbliblock00Kernel084 + idx_z * 1*1 * xdim1_opensbliblock00Kernel084 * ydim1_opensbliblock00Kernel084], xdim1_opensbliblock00Kernel084, ydim1_opensbliblock00Kernel084};
    ptr_double ptr2 = { &arg2[base2 + idx_x * 1*1 + idx_y * 1*1 * xdim2_opensbliblock00Kernel084 + idx_z * 1*1 * xdim2_opensbliblock00Kernel084 * ydim2_opensbliblock00Kernel084], xdim2_opensbliblock00Kernel084, ydim2_opensbliblock00Kernel084};
    ptr_double ptr3 = { &arg3[base3 + idx_x * 1*1 + idx_y * 1*1 * xdim3_opensbliblock00Kernel084 + idx_z * 1*1 * xdim3_opensbliblock00Kernel084 * ydim3_opensbliblock00Kernel084], xdim3_opensbliblock00Kernel084, ydim3_opensbliblock00Kernel084};
    ptr_double ptr4 = { &arg4[base4 + idx_x * 1*1 + idx_y * 1*1 * xdim4_opensbliblock00Kernel084 + idx_z * 1*1 * xdim4_opensbliblock00Kernel084 * ydim4_opensbliblock00Kernel084], xdim4_opensbliblock00Kernel084, ydim4_opensbliblock00Kernel084};
    opensbliblock00Kernel084(ptr0,
                                  ptr1,
                                  ptr2,
                                  ptr3,
                                  ptr4);
  }

}
