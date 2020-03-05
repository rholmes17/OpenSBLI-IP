//
// auto-generated by ops.py
//

int xdim0_opensbliblock00Kernel032;
int ydim0_opensbliblock00Kernel032;
int xdim1_opensbliblock00Kernel032;
int ydim1_opensbliblock00Kernel032;


//user function



void opensbliblock00Kernel032_c_wrapper(
  double * restrict rhou1_B0_p,
  double * restrict wk21_B0_p,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        const ptr_double rhou1_B0 = { rhou1_B0_p + n_x*1 + n_y * xdim0_opensbliblock00Kernel032*1 + n_z * xdim0_opensbliblock00Kernel032 * ydim0_opensbliblock00Kernel032*1, xdim0_opensbliblock00Kernel032, ydim0_opensbliblock00Kernel032};
        ptr_double wk21_B0 = { wk21_B0_p + n_x*1 + n_y * xdim1_opensbliblock00Kernel032*1 + n_z * xdim1_opensbliblock00Kernel032 * ydim1_opensbliblock00Kernel032*1, xdim1_opensbliblock00Kernel032, ydim1_opensbliblock00Kernel032};
        
    OPS_ACC(wk21_B0, 0,0,0) = inv_1*(-rc7*OPS_ACC(rhou1_B0, 0,2,0) + (rc7)*OPS_ACC(rhou1_B0, 0,-2,0) -
      rc8*OPS_ACC(rhou1_B0, 0,-1,0) + (rc8)*OPS_ACC(rhou1_B0, 0,1,0));


      }
    }
  }
}