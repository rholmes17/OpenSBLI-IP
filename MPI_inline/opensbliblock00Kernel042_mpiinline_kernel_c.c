//
// auto-generated by ops.py
//

int xdim0_opensbliblock00Kernel042;
int ydim0_opensbliblock00Kernel042;
int xdim1_opensbliblock00Kernel042;
int ydim1_opensbliblock00Kernel042;


//user function



void opensbliblock00Kernel042_c_wrapper(
  double * restrict wk39_B0_p,
  double * restrict wk29_B0_p,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        const ptr_double wk39_B0 = { wk39_B0_p + n_x*1 + n_y * xdim0_opensbliblock00Kernel042*1 + n_z * xdim0_opensbliblock00Kernel042 * ydim0_opensbliblock00Kernel042*1, xdim0_opensbliblock00Kernel042, ydim0_opensbliblock00Kernel042};
        ptr_double wk29_B0 = { wk29_B0_p + n_x*1 + n_y * xdim1_opensbliblock00Kernel042*1 + n_z * xdim1_opensbliblock00Kernel042 * ydim1_opensbliblock00Kernel042*1, xdim1_opensbliblock00Kernel042, ydim1_opensbliblock00Kernel042};
        
    OPS_ACC(wk29_B0, 0,0,0) = inv_2*((rc12)*OPS_ACC(wk39_B0, 0,0,1) - rc13*OPS_ACC(wk39_B0, 0,0,2) +
      (rc13)*OPS_ACC(wk39_B0, 0,0,-2) - rc12*OPS_ACC(wk39_B0, 0,0,-1));


      }
    }
  }
}
