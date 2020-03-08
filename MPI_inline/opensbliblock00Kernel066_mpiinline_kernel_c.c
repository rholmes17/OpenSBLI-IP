//
// auto-generated by ops.py
//

int xdim0_opensbliblock00Kernel066;
int ydim0_opensbliblock00Kernel066;
int xdim1_opensbliblock00Kernel066;
int ydim1_opensbliblock00Kernel066;


//user function



void opensbliblock00Kernel066_c_wrapper(
  double * restrict u0_B0_p,
  double * restrict wk13_B0_p,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        const ptr_double u0_B0 = { u0_B0_p + n_x*1 + n_y * xdim0_opensbliblock00Kernel066*1 + n_z * xdim0_opensbliblock00Kernel066 * ydim0_opensbliblock00Kernel066*1, xdim0_opensbliblock00Kernel066, ydim0_opensbliblock00Kernel066};
        ptr_double wk13_B0 = { wk13_B0_p + n_x*1 + n_y * xdim1_opensbliblock00Kernel066*1 + n_z * xdim1_opensbliblock00Kernel066 * ydim1_opensbliblock00Kernel066*1, xdim1_opensbliblock00Kernel066, ydim1_opensbliblock00Kernel066};
        
    OPS_ACC(wk13_B0, 0,0,0) = inv_0*(-rc13*OPS_ACC(u0_B0, 2,0,0) - rc12*OPS_ACC(u0_B0, -1,0,0) +
      (rc12)*OPS_ACC(u0_B0, 1,0,0) + (rc13)*OPS_ACC(u0_B0, -2,0,0));


      }
    }
  }
}
