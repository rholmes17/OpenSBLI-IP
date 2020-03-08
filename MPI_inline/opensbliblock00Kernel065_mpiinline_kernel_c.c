//
// auto-generated by ops.py
//

int xdim0_opensbliblock00Kernel065;
int ydim0_opensbliblock00Kernel065;
int xdim1_opensbliblock00Kernel065;
int ydim1_opensbliblock00Kernel065;


//user function



void opensbliblock00Kernel065_c_wrapper(
  double * restrict T_B0_p,
  double * restrict wk12_B0_p,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        const ptr_double T_B0 = { T_B0_p + n_x*1 + n_y * xdim0_opensbliblock00Kernel065*1 + n_z * xdim0_opensbliblock00Kernel065 * ydim0_opensbliblock00Kernel065*1, xdim0_opensbliblock00Kernel065, ydim0_opensbliblock00Kernel065};
        ptr_double wk12_B0 = { wk12_B0_p + n_x*1 + n_y * xdim1_opensbliblock00Kernel065*1 + n_z * xdim1_opensbliblock00Kernel065 * ydim1_opensbliblock00Kernel065*1, xdim1_opensbliblock00Kernel065, ydim1_opensbliblock00Kernel065};
        
    OPS_ACC(wk12_B0, 0,0,0) = inv_5*(-rc13*OPS_ACC(T_B0, 0,0,-2) + (rc8)*OPS_ACC(T_B0, 0,0,-1) -
      rc13*OPS_ACC(T_B0, 0,0,2) + (rc8)*OPS_ACC(T_B0, 0,0,1) - rc14*OPS_ACC(T_B0, 0,0,0));


      }
    }
  }
}
