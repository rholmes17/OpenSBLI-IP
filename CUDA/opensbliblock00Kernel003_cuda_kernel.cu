//
// auto-generated by ops.py
//
__constant__ int dims_opensbliblock00Kernel003 [3][2];
static int dims_opensbliblock00Kernel003_h [3][2] = {0};

//user function
__device__

void opensbliblock00Kernel003_gpu(const ACC<double> &rhou0_B0,
  const ACC<double> &rho_B0,
  ACC<double> &u0_B0)
{
   u0_B0(0,0,0) = rhou0_B0(0,0,0)/rho_B0(0,0,0);

}



__global__ void ops_opensbliblock00Kernel003(
double* __restrict arg0,
double* __restrict arg1,
double* __restrict arg2,
int size0,
int size1,
int size2 ){


  int idx_z = blockDim.z * blockIdx.z + threadIdx.z;
  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1*1 + idx_y * 1*1 * dims_opensbliblock00Kernel003[0][0] + idx_z * 1*1 * dims_opensbliblock00Kernel003[0][0] * dims_opensbliblock00Kernel003[0][1];
  arg1 += idx_x * 1*1 + idx_y * 1*1 * dims_opensbliblock00Kernel003[1][0] + idx_z * 1*1 * dims_opensbliblock00Kernel003[1][0] * dims_opensbliblock00Kernel003[1][1];
  arg2 += idx_x * 1*1 + idx_y * 1*1 * dims_opensbliblock00Kernel003[2][0] + idx_z * 1*1 * dims_opensbliblock00Kernel003[2][0] * dims_opensbliblock00Kernel003[2][1];

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    const ACC<double> argp0(dims_opensbliblock00Kernel003[0][0], dims_opensbliblock00Kernel003[0][1], arg0);
    const ACC<double> argp1(dims_opensbliblock00Kernel003[1][0], dims_opensbliblock00Kernel003[1][1], arg1);
    ACC<double> argp2(dims_opensbliblock00Kernel003[2][0], dims_opensbliblock00Kernel003[2][1], arg2);
    opensbliblock00Kernel003_gpu(argp0, argp1, argp2);
  }

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_opensbliblock00Kernel003(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2) {
#else
void ops_par_loop_opensbliblock00Kernel003_execute(ops_kernel_descriptor *desc) {
  int dim = desc->dim;
  #if OPS_MPI
  ops_block block = desc->block;
  #endif
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  #endif

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[3] = { arg0, arg1, arg2};


  #if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args,3,range,9)) return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(9,"opensbliblock00Kernel003");
    OPS_kernels[9].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];
  #if OPS_MPI && !OPS_LAZY
  sub_block_list sb = OPS_sub_block_list[block->index];
  #endif //OPS_MPI

  #ifdef OPS_MPI
  int arg_idx[3];
  #endif
  #ifdef OPS_MPI
  if (compute_ranges(args, 3,block, range, start, end, arg_idx) < 0) return;
  #else //OPS_MPI
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif
  int xdim0 = args[0].dat->size[0];
  int ydim0 = args[0].dat->size[1];
  int xdim1 = args[1].dat->size[0];
  int ydim1 = args[1].dat->size[1];
  int xdim2 = args[2].dat->size[0];
  int ydim2 = args[2].dat->size[1];

  if (xdim0 != dims_opensbliblock00Kernel003_h[0][0] || ydim0 != dims_opensbliblock00Kernel003_h[0][1] || xdim1 != dims_opensbliblock00Kernel003_h[1][0] || ydim1 != dims_opensbliblock00Kernel003_h[1][1] || xdim2 != dims_opensbliblock00Kernel003_h[2][0] || ydim2 != dims_opensbliblock00Kernel003_h[2][1]) {
    dims_opensbliblock00Kernel003_h[0][0] = xdim0;
    dims_opensbliblock00Kernel003_h[0][1] = ydim0;
    dims_opensbliblock00Kernel003_h[1][0] = xdim1;
    dims_opensbliblock00Kernel003_h[1][1] = ydim1;
    dims_opensbliblock00Kernel003_h[2][0] = xdim2;
    dims_opensbliblock00Kernel003_h[2][1] = ydim2;
    cutilSafeCall(cudaMemcpyToSymbol( dims_opensbliblock00Kernel003, dims_opensbliblock00Kernel003_h, sizeof(dims_opensbliblock00Kernel003)));
  }



  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);

  dim3 grid( (x_size-1)/OPS_block_size_x+ 1, (y_size-1)/OPS_block_size_y + 1, (z_size-1)/OPS_block_size_z +1);
  dim3 tblock(OPS_block_size_x,OPS_block_size_y,OPS_block_size_z);



  int dat0 = (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  int dat1 = (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);
  int dat2 = (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size);

  char *p_a[3];

  //set up initial pointers
  int base0 = args[0].dat->base_offset + 
           dat0 * 1 * (start[0] * args[0].stencil->stride[0]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    (start[1] * args[0].stencil->stride[1]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    args[0].dat->size[1] *
    (start[2] * args[0].stencil->stride[2]);
  p_a[0] = (char *)args[0].data_d + base0;

  int base1 = args[1].dat->base_offset + 
           dat1 * 1 * (start[0] * args[1].stencil->stride[0]);
  base1 = base1+ dat1 *
    args[1].dat->size[0] *
    (start[1] * args[1].stencil->stride[1]);
  base1 = base1+ dat1 *
    args[1].dat->size[0] *
    args[1].dat->size[1] *
    (start[2] * args[1].stencil->stride[2]);
  p_a[1] = (char *)args[1].data_d + base1;

  int base2 = args[2].dat->base_offset + 
           dat2 * 1 * (start[0] * args[2].stencil->stride[0]);
  base2 = base2+ dat2 *
    args[2].dat->size[0] *
    (start[1] * args[2].stencil->stride[1]);
  base2 = base2+ dat2 *
    args[2].dat->size[0] *
    args[2].dat->size[1] *
    (start[2] * args[2].stencil->stride[2]);
  p_a[2] = (char *)args[2].data_d + base2;


  #ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 3);
  ops_halo_exchanges(args,3,range);
  #endif

  if (OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_kernels[9].mpi_time += t2-t1;
  }


  //call kernel wrapper function, passing in pointers to data
  if (x_size > 0 && y_size > 0 && z_size > 0)
    ops_opensbliblock00Kernel003<<<grid, tblock >>> (  (double *)p_a[0], (double *)p_a[1],
         (double *)p_a[2],x_size, y_size, z_size);

  cutilSafeCall(cudaGetLastError());

  if (OPS_diags>1) {
    cutilSafeCall(cudaDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    OPS_kernels[9].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 3);
  ops_set_halo_dirtybit3(&args[2],range);
  #endif

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    OPS_kernels[9].mpi_time += t2-t1;
    OPS_kernels[9].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[9].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[9].transfer += ops_compute_transfer(dim, start, end, &arg2);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_opensbliblock00Kernel003(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 9;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 9;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 3;
  desc->args = (ops_arg*)malloc(3*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg2.dat->index;
  desc->function = ops_par_loop_opensbliblock00Kernel003_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(9,"opensbliblock00Kernel003");
  }
  ops_enqueue_kernel(desc);
}
#endif