#include <stdlib.h> 
#include <string.h> 
#include <math.h>
int block0np0;
int block0np1;
int block0np2;
double Delta0block0;
double Delta1block0;
double Delta2block0;
int niter;
double dt;
double Minf;
double gama;
double Pr;
double Re;
double inv_0;
double inv_1;
double inv_2;
double inv_3;
double inv_4;
double inv_5;
double rc6;
double rc7;
double rc8;
double rc9;
double rc10;
double rcinv11;
double rc12;
double rcinv13;
double rcinv14;
double rc15;
double rc16;
double rc17;
double rc18;
double rc19;
double rc20;
double rc21;
double rc22;
double rc23;
double rc24;
double rc25;
double rc26;
double rc27;
double rc28;
double rc29;
double rc30;
double rc31;
double rc32;
double rc33;
double rc34;
double rc35;
double rc36;
double rc37;
double rc38;
#define OPS_3D
#include "ops_seq.h"
#include "opensbliblock00_kernels.h"
int main(int argc, char **argv) 
{
block0np0 = 33;
block0np1 = 33;
block0np2 = 33;
Delta0block0 = M_PI/(block0np0-1);
Delta1block0 = M_PI/(block0np1-1);
Delta2block0 = M_PI/(block0np2-1);
niter = 213;
double rkold[] = {1.0/4.0, 3.0/20.0, 3.0/5.0};
double rknew[] = {2.0/3.0, 5.0/12.0, 3.0/5.0};
dt = 0.00467498906784;
Minf = 0.1;
gama = 1.4;
Pr = 0.71;
Re = 800.0;
inv_0 = 1.0/Delta0block0;
inv_1 = 1.0/Delta1block0;
inv_2 = 1.0/Delta2block0;
inv_3 = pow(Delta0block0, -2);
inv_4 = pow(Delta1block0, -2);
inv_5 = pow(Delta2block0, -2);
rc6 = 1.0/2.0;
rc7 = 1.0/12.0;
rc8 = 2.0/3.0;
rc9 = 4.0/3.0;
rc10 = 5.0/2.0;
rcinv11 = 1.0/Re;
rc12 = 1.0/3.0;
rcinv13 = pow(Minf, -2);
rcinv14 = 1.0/Pr;
rc15 = 3.0/20.0;
rc16 = 1.0/60.0;
rc17 = 3.0/4.0;
rc18 = 1.0/90.0;
rc19 = 49.0/18.0;
rc20 = 3.0/2.0;
rc21 = 1.0/5.0;
rc22 = 4.0/105.0;
rc23 = 1.0/280.0;
rc24 = 4.0/5.0;
rc25 = 8.0/5.0;
rc26 = 205.0/72.0;
rc27 = 8.0/315.0;
rc28 = 1.0/560.0;
rc29 = 5.0/21.0;
rc30 = 5.0/84.0;
rc31 = 5.0/504.0;
rc32 = 1.0/1260.0;
rc33 = 5.0/6.0;
rc34 = 5.0/3.0;
rc35 = 5269.0/1800.0;
rc36 = 5.0/126.0;
rc37 = 1.0/3150.0;
rc38 = 5.0/1008.0;
// Initializing OPS 
ops_init(argc,argv,1);
ops_decl_const("block0np0" , 1, "int", &block0np0);
ops_decl_const("block0np1" , 1, "int", &block0np1);
ops_decl_const("block0np2" , 1, "int", &block0np2);
ops_decl_const("Delta0block0" , 1, "double", &Delta0block0);
ops_decl_const("Delta1block0" , 1, "double", &Delta1block0);
ops_decl_const("Delta2block0" , 1, "double", &Delta2block0);
ops_decl_const("niter" , 1, "int", &niter);
ops_decl_const("dt" , 1, "double", &dt);
ops_decl_const("Minf" , 1, "double", &Minf);
ops_decl_const("gama" , 1, "double", &gama);
ops_decl_const("Pr" , 1, "double", &Pr);
ops_decl_const("Re" , 1, "double", &Re);
ops_decl_const("inv_0" , 1, "double", &inv_0);
ops_decl_const("inv_1" , 1, "double", &inv_1);
ops_decl_const("inv_2" , 1, "double", &inv_2);
ops_decl_const("inv_3" , 1, "double", &inv_3);
ops_decl_const("inv_4" , 1, "double", &inv_4);
ops_decl_const("inv_5" , 1, "double", &inv_5);
ops_decl_const("rc6" , 1, "double", &rc6);
ops_decl_const("rc7" , 1, "double", &rc7);
ops_decl_const("rc8" , 1, "double", &rc8);
ops_decl_const("rc9" , 1, "double", &rc9);
ops_decl_const("rc10" , 1, "double", &rc10);
ops_decl_const("rcinv11" , 1, "double", &rcinv11);
ops_decl_const("rc12" , 1, "double", &rc12);
ops_decl_const("rcinv13" , 1, "double", &rcinv13);
ops_decl_const("rcinv14" , 1, "double", &rcinv14);
ops_decl_const("rc15" , 1, "double", &rc15);
ops_decl_const("rc16" , 1, "double", &rc16);
ops_decl_const("rc17" , 1, "double", &rc17);
ops_decl_const("rc18" , 1, "double", &rc18);
ops_decl_const("rc19" , 1, "double", &rc19);
ops_decl_const("rc20" , 1, "double", &rc20);
ops_decl_const("rc21" , 1, "double", &rc21);
ops_decl_const("rc22" , 1, "double", &rc22);
ops_decl_const("rc23" , 1, "double", &rc23);
ops_decl_const("rc24" , 1, "double", &rc24);
ops_decl_const("rc25" , 1, "double", &rc25);
ops_decl_const("rc26" , 1, "double", &rc26);
ops_decl_const("rc27" , 1, "double", &rc27);
ops_decl_const("rc28" , 1, "double", &rc28);
ops_decl_const("rc29" , 1, "double", &rc29);
ops_decl_const("rc30" , 1, "double", &rc30);
ops_decl_const("rc31" , 1, "double", &rc31);
ops_decl_const("rc32" , 1, "double", &rc32);
ops_decl_const("rc33" , 1, "double", &rc33);
ops_decl_const("rc34" , 1, "double", &rc34);
ops_decl_const("rc35" , 1, "double", &rc35);
ops_decl_const("rc36" , 1, "double", &rc36);
ops_decl_const("rc37" , 1, "double", &rc37);
ops_decl_const("rc38" , 1, "double", &rc38);
// Define and Declare OPS Block
ops_block opensbliblock00 = ops_decl_block(3, "opensbliblock00");
#include "defdec_data_set.h"
// Define and declare stencils
int stencil_0_06temp[] = {0, 0, -5, 0, 0, -4, 0, 0, -3, 0, 0, -2, 0, 0, -1, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 3, 0, 0, 4, 0, 0, 5};
ops_stencil stencil_0_06 = ops_decl_stencil(3,11,stencil_0_06temp,"stencil_0_06temp");
int stencil_0_02temp[] = {0, -5, 0, 0, -4, 0, 0, -3, 0, 0, -2, 0, 0, -1, 0, 0, 1, 0, 0, 2, 0, 0, 3, 0, 0, 4, 0, 0, 5, 0};
ops_stencil stencil_0_02 = ops_decl_stencil(3,10,stencil_0_02temp,"stencil_0_02temp");
int stencil_0_04temp[] = {-5, 0, 0, -4, 0, 0, -3, 0, 0, -2, 0, 0, -1, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 3, 0, 0, 4, 0, 0, 5, 0, 0};
ops_stencil stencil_0_04 = ops_decl_stencil(3,11,stencil_0_04temp,"stencil_0_04temp");
int stencil_0_05temp[] = {0, -5, 0, 0, -4, 0, 0, -3, 0, 0, -2, 0, 0, -1, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 3, 0, 0, 4, 0, 0, 5, 0};
ops_stencil stencil_0_05 = ops_decl_stencil(3,11,stencil_0_05temp,"stencil_0_05temp");
int stencil_0_00temp[] = {0, 0, 0};
ops_stencil stencil_0_00 = ops_decl_stencil(3,1,stencil_0_00temp,"stencil_0_00temp");
int stencil_0_03temp[] = {0, 0, -5, 0, 0, -4, 0, 0, -3, 0, 0, -2, 0, 0, -1, 0, 0, 1, 0, 0, 2, 0, 0, 3, 0, 0, 4, 0, 0, 5};
ops_stencil stencil_0_03 = ops_decl_stencil(3,10,stencil_0_03temp,"stencil_0_03temp");
int stencil_0_01temp[] = {-5, 0, 0, -4, 0, 0, -3, 0, 0, -2, 0, 0, -1, 0, 0, 1, 0, 0, 2, 0, 0, 3, 0, 0, 4, 0, 0, 5, 0, 0};
ops_stencil stencil_0_01 = ops_decl_stencil(3,10,stencil_0_01temp,"stencil_0_01temp");
// Init OPS partition
ops_partition("");

int iteration_range_88_block0[] = {-5, block0np0 + 5, -5, block0np1 + 5, -5, block0np2 + 5};
ops_par_loop(opensbliblock00Kernel088, "Grid_based_initialisation0", opensbliblock00, 3, iteration_range_88_block0,
ops_arg_dat(rhou1_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(rhoE_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(rhou0_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(rho_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(rhou2_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_idx());


double cpu_start0, elapsed_start0;
ops_timers(&cpu_start0, &elapsed_start0);
for(int iter=0; iter<=niter - 1; iter++)
{
int iteration_range_82_block0[] = {0, 1, -5, block0np1 + 5, -5, block0np2 + 5};
ops_par_loop(opensbliblock00Kernel082, "Symmetry boundary dir0 side0", opensbliblock00, 3, iteration_range_82_block0,
ops_arg_dat(rhoE_B0, 1, stencil_0_01, "double", OPS_RW),
ops_arg_dat(rhou1_B0, 1, stencil_0_01, "double", OPS_RW),
ops_arg_dat(rhou0_B0, 1, stencil_0_01, "double", OPS_RW),
ops_arg_dat(rho_B0, 1, stencil_0_01, "double", OPS_RW),
ops_arg_dat(rhou2_B0, 1, stencil_0_01, "double", OPS_RW));


int iteration_range_83_block0[] = {block0np0 - 1, block0np0, -5, block0np1 + 5, -5, block0np2 + 5};
ops_par_loop(opensbliblock00Kernel083, "Symmetry boundary dir0 side1", opensbliblock00, 3, iteration_range_83_block0,
ops_arg_dat(rhoE_B0, 1, stencil_0_01, "double", OPS_RW),
ops_arg_dat(rhou1_B0, 1, stencil_0_01, "double", OPS_RW),
ops_arg_dat(rhou0_B0, 1, stencil_0_01, "double", OPS_RW),
ops_arg_dat(rho_B0, 1, stencil_0_01, "double", OPS_RW),
ops_arg_dat(rhou2_B0, 1, stencil_0_01, "double", OPS_RW));


int iteration_range_84_block0[] = {-5, block0np0 + 5, 0, 1, -5, block0np2 + 5};
ops_par_loop(opensbliblock00Kernel084, "Symmetry boundary dir1 side0", opensbliblock00, 3, iteration_range_84_block0,
ops_arg_dat(rhoE_B0, 1, stencil_0_02, "double", OPS_RW),
ops_arg_dat(rhou1_B0, 1, stencil_0_02, "double", OPS_RW),
ops_arg_dat(rhou0_B0, 1, stencil_0_02, "double", OPS_RW),
ops_arg_dat(rho_B0, 1, stencil_0_02, "double", OPS_RW),
ops_arg_dat(rhou2_B0, 1, stencil_0_02, "double", OPS_RW));


int iteration_range_85_block0[] = {-5, block0np0 + 5, block0np1 - 1, block0np1, -5, block0np2 + 5};
ops_par_loop(opensbliblock00Kernel085, "Symmetry boundary dir1 side1", opensbliblock00, 3, iteration_range_85_block0,
ops_arg_dat(rhoE_B0, 1, stencil_0_02, "double", OPS_RW),
ops_arg_dat(rhou1_B0, 1, stencil_0_02, "double", OPS_RW),
ops_arg_dat(rhou0_B0, 1, stencil_0_02, "double", OPS_RW),
ops_arg_dat(rho_B0, 1, stencil_0_02, "double", OPS_RW),
ops_arg_dat(rhou2_B0, 1, stencil_0_02, "double", OPS_RW));


int iteration_range_86_block0[] = {-5, block0np0 + 5, -5, block0np1 + 5, 0, 1};
ops_par_loop(opensbliblock00Kernel086, "Symmetry boundary dir2 side0", opensbliblock00, 3, iteration_range_86_block0,
ops_arg_dat(rhoE_B0, 1, stencil_0_03, "double", OPS_RW),
ops_arg_dat(rhou1_B0, 1, stencil_0_03, "double", OPS_RW),
ops_arg_dat(rhou0_B0, 1, stencil_0_03, "double", OPS_RW),
ops_arg_dat(rho_B0, 1, stencil_0_03, "double", OPS_RW),
ops_arg_dat(rhou2_B0, 1, stencil_0_03, "double", OPS_RW));


int iteration_range_87_block0[] = {-5, block0np0 + 5, -5, block0np1 + 5, block0np2 - 1, block0np2};
ops_par_loop(opensbliblock00Kernel087, "Symmetry boundary dir2 side1", opensbliblock00, 3, iteration_range_87_block0,
ops_arg_dat(rhoE_B0, 1, stencil_0_03, "double", OPS_RW),
ops_arg_dat(rhou1_B0, 1, stencil_0_03, "double", OPS_RW),
ops_arg_dat(rhou0_B0, 1, stencil_0_03, "double", OPS_RW),
ops_arg_dat(rho_B0, 1, stencil_0_03, "double", OPS_RW),
ops_arg_dat(rhou2_B0, 1, stencil_0_03, "double", OPS_RW));


int iteration_range_89_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel089, "Save equations", opensbliblock00, 3, iteration_range_89_block0,
ops_arg_dat(rhou1_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rhoE_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rhou0_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rho_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rhou2_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rhou1_old_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(rhou2_old_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(rhou0_old_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(rho_old_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(rhoE_old_B0, 1, stencil_0_00, "double", OPS_WRITE));


for(int stage=0; stage<=2; stage++)
{
int iteration_range_41_block0[] = {-5, block0np0 + 5, -5, block0np1 + 5, -5, block0np2 + 5};
ops_par_loop(opensbliblock00Kernel041, "CRu2_B0", opensbliblock00, 3, iteration_range_41_block0,
ops_arg_dat(rho_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rhou2_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(u2_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_3_block0[] = {-5, block0np0 + 5, -5, block0np1 + 5, -5, block0np2 + 5};
ops_par_loop(opensbliblock00Kernel003, "CRu0_B0", opensbliblock00, 3, iteration_range_3_block0,
ops_arg_dat(rhou0_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rho_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(u0_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_23_block0[] = {-5, block0np0 + 5, -5, block0np1 + 5, -5, block0np2 + 5};
ops_par_loop(opensbliblock00Kernel023, "CRu1_B0", opensbliblock00, 3, iteration_range_23_block0,
ops_arg_dat(rhou1_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rho_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(u1_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_7_block0[] = {-5, block0np0 + 5, -5, block0np1 + 5, -5, block0np2 + 5};
ops_par_loop(opensbliblock00Kernel007, "CRp_B0", opensbliblock00, 3, iteration_range_7_block0,
ops_arg_dat(rhoE_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rho_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(u0_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(u1_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(u2_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(p_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_80_block0[] = {-5, block0np0 + 5, -5, block0np1 + 5, -5, block0np2 + 5};
ops_par_loop(opensbliblock00Kernel080, "CRT_B0", opensbliblock00, 3, iteration_range_80_block0,
ops_arg_dat(rho_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(p_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(T_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_0_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel000, "Zeroing residuals", opensbliblock00, 3, iteration_range_0_block0,
ops_arg_dat(Residual4_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(Residual3_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(Residual0_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(Residual2_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(Residual1_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_1_block0[] = {-5, block0np0 + 5, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel001, "Convective terms group 0", opensbliblock00, 3, iteration_range_1_block0,
ops_arg_dat(rhou2_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rhoE_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rho_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(p_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rhou1_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rhou0_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(u0_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk40_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(wk43_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(wk41_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(wk39_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(wk42_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(wk44_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_4_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel004, "Convective CD rhou1_B0*u0_B0 x0 ", opensbliblock00, 3, iteration_range_4_block0,
ops_arg_dat(wk39_B0, 1, stencil_0_01, "double", OPS_READ),
ops_arg_dat(wk0_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_6_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel006, "Convective CD rhou2_B0*u0_B0 x0 ", opensbliblock00, 3, iteration_range_6_block0,
ops_arg_dat(wk40_B0, 1, stencil_0_01, "double", OPS_READ),
ops_arg_dat(wk1_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_8_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel008, "Convective CD p_B0 x0 ", opensbliblock00, 3, iteration_range_8_block0,
ops_arg_dat(p_B0, 1, stencil_0_01, "double", OPS_READ),
ops_arg_dat(wk2_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_9_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel009, "Convective CD rhou2_B0 x0 ", opensbliblock00, 3, iteration_range_9_block0,
ops_arg_dat(rhou2_B0, 1, stencil_0_01, "double", OPS_READ),
ops_arg_dat(wk3_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_11_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel011, "Convective CD rho_B0*u0_B0 x0 ", opensbliblock00, 3, iteration_range_11_block0,
ops_arg_dat(wk41_B0, 1, stencil_0_01, "double", OPS_READ),
ops_arg_dat(wk4_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_13_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel013, "Convective CD rhoE_B0*u0_B0 x0 ", opensbliblock00, 3, iteration_range_13_block0,
ops_arg_dat(wk42_B0, 1, stencil_0_01, "double", OPS_READ),
ops_arg_dat(wk5_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_14_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel014, "Convective CD rho_B0 x0 ", opensbliblock00, 3, iteration_range_14_block0,
ops_arg_dat(rho_B0, 1, stencil_0_01, "double", OPS_READ),
ops_arg_dat(wk6_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_15_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel015, "Convective CD u0_B0 x0 ", opensbliblock00, 3, iteration_range_15_block0,
ops_arg_dat(u0_B0, 1, stencil_0_01, "double", OPS_READ),
ops_arg_dat(wk7_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_16_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel016, "Convective CD rhou1_B0 x0 ", opensbliblock00, 3, iteration_range_16_block0,
ops_arg_dat(rhou1_B0, 1, stencil_0_01, "double", OPS_READ),
ops_arg_dat(wk8_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_18_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel018, "Convective CD rhou0_B0*u0_B0 x0 ", opensbliblock00, 3, iteration_range_18_block0,
ops_arg_dat(wk43_B0, 1, stencil_0_01, "double", OPS_READ),
ops_arg_dat(wk9_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_19_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel019, "Convective CD rhou0_B0 x0 ", opensbliblock00, 3, iteration_range_19_block0,
ops_arg_dat(rhou0_B0, 1, stencil_0_01, "double", OPS_READ),
ops_arg_dat(wk10_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_20_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel020, "Convective CD rhoE_B0 x0 ", opensbliblock00, 3, iteration_range_20_block0,
ops_arg_dat(rhoE_B0, 1, stencil_0_01, "double", OPS_READ),
ops_arg_dat(wk11_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_21_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel021, "Convective CD p_B0*u0_B0 x0 ", opensbliblock00, 3, iteration_range_21_block0,
ops_arg_dat(wk44_B0, 1, stencil_0_01, "double", OPS_READ),
ops_arg_dat(wk12_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_22_block0[] = {0, block0np0, -5, block0np1 + 5, 0, block0np2};
ops_par_loop(opensbliblock00Kernel022, "Convective terms group 1", opensbliblock00, 3, iteration_range_22_block0,
ops_arg_dat(rhoE_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rho_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(p_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rhou1_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rhou0_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rhou2_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(u1_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk40_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(wk43_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(wk41_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(wk39_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(wk42_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(wk44_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_24_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel024, "Convective CD u1_B0 x1 ", opensbliblock00, 3, iteration_range_24_block0,
ops_arg_dat(u1_B0, 1, stencil_0_02, "double", OPS_READ),
ops_arg_dat(wk13_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_25_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel025, "Convective CD rhoE_B0 x1 ", opensbliblock00, 3, iteration_range_25_block0,
ops_arg_dat(rhoE_B0, 1, stencil_0_02, "double", OPS_READ),
ops_arg_dat(wk14_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_26_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel026, "Convective CD p_B0*u1_B0 x1 ", opensbliblock00, 3, iteration_range_26_block0,
ops_arg_dat(wk39_B0, 1, stencil_0_02, "double", OPS_READ),
ops_arg_dat(wk15_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_27_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel027, "Convective CD rhou2_B0 x1 ", opensbliblock00, 3, iteration_range_27_block0,
ops_arg_dat(rhou2_B0, 1, stencil_0_02, "double", OPS_READ),
ops_arg_dat(wk16_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_28_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel028, "Convective CD rho_B0*u1_B0 x1 ", opensbliblock00, 3, iteration_range_28_block0,
ops_arg_dat(wk40_B0, 1, stencil_0_02, "double", OPS_READ),
ops_arg_dat(wk17_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_29_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel029, "Convective CD rhou0_B0*u1_B0 x1 ", opensbliblock00, 3, iteration_range_29_block0,
ops_arg_dat(wk41_B0, 1, stencil_0_02, "double", OPS_READ),
ops_arg_dat(wk18_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_30_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel030, "Convective CD rhoE_B0*u1_B0 x1 ", opensbliblock00, 3, iteration_range_30_block0,
ops_arg_dat(wk42_B0, 1, stencil_0_02, "double", OPS_READ),
ops_arg_dat(wk19_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_31_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel031, "Convective CD p_B0 x1 ", opensbliblock00, 3, iteration_range_31_block0,
ops_arg_dat(p_B0, 1, stencil_0_02, "double", OPS_READ),
ops_arg_dat(wk20_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_32_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel032, "Convective CD rhou1_B0 x1 ", opensbliblock00, 3, iteration_range_32_block0,
ops_arg_dat(rhou1_B0, 1, stencil_0_02, "double", OPS_READ),
ops_arg_dat(wk21_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_33_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel033, "Convective CD rhou0_B0 x1 ", opensbliblock00, 3, iteration_range_33_block0,
ops_arg_dat(rhou0_B0, 1, stencil_0_02, "double", OPS_READ),
ops_arg_dat(wk22_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_34_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel034, "Convective CD rho_B0 x1 ", opensbliblock00, 3, iteration_range_34_block0,
ops_arg_dat(rho_B0, 1, stencil_0_02, "double", OPS_READ),
ops_arg_dat(wk23_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_35_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel035, "Convective CD rhou1_B0*u1_B0 x1 ", opensbliblock00, 3, iteration_range_35_block0,
ops_arg_dat(wk43_B0, 1, stencil_0_02, "double", OPS_READ),
ops_arg_dat(wk24_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_36_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel036, "Convective CD rhou2_B0*u1_B0 x1 ", opensbliblock00, 3, iteration_range_36_block0,
ops_arg_dat(wk44_B0, 1, stencil_0_02, "double", OPS_READ),
ops_arg_dat(wk25_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_37_block0[] = {0, block0np0, 0, block0np1, -5, block0np2 + 5};
ops_par_loop(opensbliblock00Kernel037, "Convective terms group 2", opensbliblock00, 3, iteration_range_37_block0,
ops_arg_dat(u2_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rhoE_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rho_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(p_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rhou1_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rhou0_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rhou2_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk40_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(wk43_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(wk41_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(wk39_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(wk42_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(wk44_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_38_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel038, "Convective CD rhou1_B0 x2 ", opensbliblock00, 3, iteration_range_38_block0,
ops_arg_dat(rhou1_B0, 1, stencil_0_03, "double", OPS_READ),
ops_arg_dat(wk26_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_39_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel039, "Convective CD p_B0 x2 ", opensbliblock00, 3, iteration_range_39_block0,
ops_arg_dat(p_B0, 1, stencil_0_03, "double", OPS_READ),
ops_arg_dat(wk27_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_40_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel040, "Convective CD rho_B0 x2 ", opensbliblock00, 3, iteration_range_40_block0,
ops_arg_dat(rho_B0, 1, stencil_0_03, "double", OPS_READ),
ops_arg_dat(wk28_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_42_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel042, "Convective CD rhou0_B0*u2_B0 x2 ", opensbliblock00, 3, iteration_range_42_block0,
ops_arg_dat(wk39_B0, 1, stencil_0_03, "double", OPS_READ),
ops_arg_dat(wk29_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_43_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel043, "Convective CD rhoE_B0 x2 ", opensbliblock00, 3, iteration_range_43_block0,
ops_arg_dat(rhoE_B0, 1, stencil_0_03, "double", OPS_READ),
ops_arg_dat(wk30_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_44_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel044, "Convective CD rhou2_B0 x2 ", opensbliblock00, 3, iteration_range_44_block0,
ops_arg_dat(rhou2_B0, 1, stencil_0_03, "double", OPS_READ),
ops_arg_dat(wk31_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_45_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel045, "Convective CD rhou1_B0*u2_B0 x2 ", opensbliblock00, 3, iteration_range_45_block0,
ops_arg_dat(wk40_B0, 1, stencil_0_03, "double", OPS_READ),
ops_arg_dat(wk32_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_46_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel046, "Convective CD rho_B0*u2_B0 x2 ", opensbliblock00, 3, iteration_range_46_block0,
ops_arg_dat(wk41_B0, 1, stencil_0_03, "double", OPS_READ),
ops_arg_dat(wk33_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_47_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel047, "Convective CD rhoE_B0*u2_B0 x2 ", opensbliblock00, 3, iteration_range_47_block0,
ops_arg_dat(wk42_B0, 1, stencil_0_03, "double", OPS_READ),
ops_arg_dat(wk34_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_48_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel048, "Convective CD rhou0_B0 x2 ", opensbliblock00, 3, iteration_range_48_block0,
ops_arg_dat(rhou0_B0, 1, stencil_0_03, "double", OPS_READ),
ops_arg_dat(wk35_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_49_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel049, "Convective CD p_B0*u2_B0 x2 ", opensbliblock00, 3, iteration_range_49_block0,
ops_arg_dat(wk43_B0, 1, stencil_0_03, "double", OPS_READ),
ops_arg_dat(wk36_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_50_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel050, "Convective CD rhou2_B0*u2_B0 x2 ", opensbliblock00, 3, iteration_range_50_block0,
ops_arg_dat(wk44_B0, 1, stencil_0_03, "double", OPS_READ),
ops_arg_dat(wk37_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_51_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel051, "Convective CD u2_B0 x2 ", opensbliblock00, 3, iteration_range_51_block0,
ops_arg_dat(u2_B0, 1, stencil_0_03, "double", OPS_READ),
ops_arg_dat(wk38_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_52_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel052, "Convective residual ", opensbliblock00, 3, iteration_range_52_block0,
ops_arg_dat(wk8_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk37_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk35_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk19_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(u2_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(u0_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk23_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk17_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk16_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk13_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk36_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk33_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rhoE_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk9_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk34_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk22_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk21_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk1_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk28_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk29_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk10_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk12_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(u1_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk14_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk24_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk38_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk26_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk3_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk0_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk30_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk5_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rhou1_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk25_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk20_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk18_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk11_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk6_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk4_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk27_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk31_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk32_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk15_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rho_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rhou0_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk7_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rhou2_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk2_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(Residual4_B0, 1, stencil_0_00, "double", OPS_RW),
ops_arg_dat(Residual3_B0, 1, stencil_0_00, "double", OPS_RW),
ops_arg_dat(Residual0_B0, 1, stencil_0_00, "double", OPS_RW),
ops_arg_dat(Residual2_B0, 1, stencil_0_00, "double", OPS_RW),
ops_arg_dat(Residual1_B0, 1, stencil_0_00, "double", OPS_RW));


int iteration_range_53_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel053, "Viscous CD u1_B0 x0 x0 ", opensbliblock00, 3, iteration_range_53_block0,
ops_arg_dat(u1_B0, 1, stencil_0_04, "double", OPS_READ),
ops_arg_dat(wk0_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_54_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel054, "Viscous CD T_B0 x1 x1 ", opensbliblock00, 3, iteration_range_54_block0,
ops_arg_dat(T_B0, 1, stencil_0_05, "double", OPS_READ),
ops_arg_dat(wk1_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_55_block0[] = {0, block0np0, 0, block0np1, -5, block0np2 + 5};
ops_par_loop(opensbliblock00Kernel055, "Viscous CD u1_B0 x1 ", opensbliblock00, 3, iteration_range_55_block0,
ops_arg_dat(u1_B0, 1, stencil_0_02, "double", OPS_READ),
ops_arg_dat(wk2_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_57_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel057, "Viscous CD u1_B0 x2 x2 ", opensbliblock00, 3, iteration_range_57_block0,
ops_arg_dat(u1_B0, 1, stencil_0_06, "double", OPS_READ),
ops_arg_dat(wk4_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_58_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel058, "Viscous CD u0_B0 x2 ", opensbliblock00, 3, iteration_range_58_block0,
ops_arg_dat(u0_B0, 1, stencil_0_03, "double", OPS_READ),
ops_arg_dat(wk5_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_59_block0[] = {0, block0np0, 0, block0np1, -5, block0np2 + 5};
ops_par_loop(opensbliblock00Kernel059, "Viscous CD u2_B0 x0 ", opensbliblock00, 3, iteration_range_59_block0,
ops_arg_dat(u2_B0, 1, stencil_0_01, "double", OPS_READ),
ops_arg_dat(wk6_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_60_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel060, "Viscous CD u1_B0 x2 ", opensbliblock00, 3, iteration_range_60_block0,
ops_arg_dat(u1_B0, 1, stencil_0_03, "double", OPS_READ),
ops_arg_dat(wk7_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_61_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel061, "Viscous CD u0_B0 x1 x1 ", opensbliblock00, 3, iteration_range_61_block0,
ops_arg_dat(u0_B0, 1, stencil_0_05, "double", OPS_READ),
ops_arg_dat(wk8_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_63_block0[] = {0, block0np0, 0, block0np1, -5, block0np2 + 5};
ops_par_loop(opensbliblock00Kernel063, "Viscous CD u2_B0 x1 ", opensbliblock00, 3, iteration_range_63_block0,
ops_arg_dat(u2_B0, 1, stencil_0_02, "double", OPS_READ),
ops_arg_dat(wk10_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_64_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel064, "Viscous CD u2_B0 x1 x1 ", opensbliblock00, 3, iteration_range_64_block0,
ops_arg_dat(u2_B0, 1, stencil_0_05, "double", OPS_READ),
ops_arg_dat(wk11_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_66_block0[] = {0, block0np0, -5, block0np1 + 5, -5, block0np2 + 5};
ops_par_loop(opensbliblock00Kernel066, "Viscous CD u0_B0 x0 ", opensbliblock00, 3, iteration_range_66_block0,
ops_arg_dat(u0_B0, 1, stencil_0_01, "double", OPS_READ),
ops_arg_dat(wk13_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_67_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel067, "Viscous CD u2_B0 x2 x2 ", opensbliblock00, 3, iteration_range_67_block0,
ops_arg_dat(u2_B0, 1, stencil_0_06, "double", OPS_READ),
ops_arg_dat(wk14_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_68_block0[] = {0, block0np0, -5, block0np1 + 5, 0, block0np2};
ops_par_loop(opensbliblock00Kernel068, "Viscous CD u1_B0 x0 ", opensbliblock00, 3, iteration_range_68_block0,
ops_arg_dat(u1_B0, 1, stencil_0_01, "double", OPS_READ),
ops_arg_dat(wk15_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_70_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel070, "Viscous CD u0_B0 x0 x0 ", opensbliblock00, 3, iteration_range_70_block0,
ops_arg_dat(u0_B0, 1, stencil_0_04, "double", OPS_READ),
ops_arg_dat(wk17_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_71_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel071, "Viscous CD u2_B0 x0 x0 ", opensbliblock00, 3, iteration_range_71_block0,
ops_arg_dat(u2_B0, 1, stencil_0_04, "double", OPS_READ),
ops_arg_dat(wk18_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_72_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel072, "Viscous CD T_B0 x0 x0 ", opensbliblock00, 3, iteration_range_72_block0,
ops_arg_dat(T_B0, 1, stencil_0_04, "double", OPS_READ),
ops_arg_dat(wk19_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_73_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel073, "Viscous CD u1_B0 x1 x1 ", opensbliblock00, 3, iteration_range_73_block0,
ops_arg_dat(u1_B0, 1, stencil_0_05, "double", OPS_READ),
ops_arg_dat(wk20_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_75_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel075, "Viscous CD u0_B0 x1 ", opensbliblock00, 3, iteration_range_75_block0,
ops_arg_dat(u0_B0, 1, stencil_0_02, "double", OPS_READ),
ops_arg_dat(wk22_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_65_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel065, "Viscous CD T_B0 x2 x2 ", opensbliblock00, 3, iteration_range_65_block0,
ops_arg_dat(T_B0, 1, stencil_0_06, "double", OPS_READ),
ops_arg_dat(wk12_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_78_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel078, "Viscous CD u0_B0 x2 x2 ", opensbliblock00, 3, iteration_range_78_block0,
ops_arg_dat(u0_B0, 1, stencil_0_06, "double", OPS_READ),
ops_arg_dat(wk25_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_79_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel079, "Viscous CD u2_B0 x2 ", opensbliblock00, 3, iteration_range_79_block0,
ops_arg_dat(u2_B0, 1, stencil_0_03, "double", OPS_READ),
ops_arg_dat(wk26_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_56_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel056, "Viscous CD CD u1_B0 x0 x1 ", opensbliblock00, 3, iteration_range_56_block0,
ops_arg_dat(wk15_B0, 1, stencil_0_02, "double", OPS_READ),
ops_arg_dat(wk3_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_62_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel062, "Viscous CD CD u0_B0 x0 x1 ", opensbliblock00, 3, iteration_range_62_block0,
ops_arg_dat(wk13_B0, 1, stencil_0_02, "double", OPS_READ),
ops_arg_dat(wk9_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_69_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel069, "Viscous CD CD u0_B0 x0 x2 ", opensbliblock00, 3, iteration_range_69_block0,
ops_arg_dat(wk13_B0, 1, stencil_0_03, "double", OPS_READ),
ops_arg_dat(wk16_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_77_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel077, "Viscous CD CD u2_B0 x0 x2 ", opensbliblock00, 3, iteration_range_77_block0,
ops_arg_dat(wk6_B0, 1, stencil_0_03, "double", OPS_READ),
ops_arg_dat(wk24_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_74_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel074, "Viscous CD CD u2_B0 x1 x2 ", opensbliblock00, 3, iteration_range_74_block0,
ops_arg_dat(wk10_B0, 1, stencil_0_03, "double", OPS_READ),
ops_arg_dat(wk21_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_76_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel076, "Viscous CD CD u1_B0 x1 x2 ", opensbliblock00, 3, iteration_range_76_block0,
ops_arg_dat(wk2_B0, 1, stencil_0_03, "double", OPS_READ),
ops_arg_dat(wk23_B0, 1, stencil_0_00, "double", OPS_WRITE));


int iteration_range_81_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel081, "Viscous residual", opensbliblock00, 3, iteration_range_81_block0,
ops_arg_dat(wk8_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk5_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(u2_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk23_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk17_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk16_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk13_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(u0_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk9_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk22_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk21_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk1_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk10_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk12_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(u1_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk14_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk24_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk26_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk3_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk0_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk19_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk25_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk20_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk18_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk11_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk6_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk4_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk15_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk7_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(wk2_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(Residual4_B0, 1, stencil_0_00, "double", OPS_RW),
ops_arg_dat(Residual3_B0, 1, stencil_0_00, "double", OPS_RW),
ops_arg_dat(Residual2_B0, 1, stencil_0_00, "double", OPS_RW),
ops_arg_dat(Residual1_B0, 1, stencil_0_00, "double", OPS_RW));


int iteration_range_91_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel091, "Sub stage advancement", opensbliblock00, 3, iteration_range_91_block0,
ops_arg_dat(Residual3_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rhou1_old_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(Residual0_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(Residual1_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rho_old_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(Residual2_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(Residual4_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rhou0_old_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rhoE_old_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rhou2_old_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rhou1_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(rhoE_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(rhou0_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(rho_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_dat(rhou2_B0, 1, stencil_0_00, "double", OPS_WRITE),
ops_arg_gbl(&rknew[stage], 1, "double", OPS_READ));


int iteration_range_90_block0[] = {0, block0np0, 0, block0np1, 0, block0np2};
ops_par_loop(opensbliblock00Kernel090, "Temporal solution advancement", opensbliblock00, 3, iteration_range_90_block0,
ops_arg_dat(Residual4_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(Residual3_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(Residual0_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(Residual2_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(Residual1_B0, 1, stencil_0_00, "double", OPS_READ),
ops_arg_dat(rhou1_old_B0, 1, stencil_0_00, "double", OPS_RW),
ops_arg_dat(rhou2_old_B0, 1, stencil_0_00, "double", OPS_RW),
ops_arg_dat(rhou0_old_B0, 1, stencil_0_00, "double", OPS_RW),
ops_arg_dat(rho_old_B0, 1, stencil_0_00, "double", OPS_RW),
ops_arg_dat(rhoE_old_B0, 1, stencil_0_00, "double", OPS_RW),
ops_arg_gbl(&rkold[stage], 1, "double", OPS_READ));


int iteration_range_82_block0[] = {0, 1, -5, block0np1 + 5, -5, block0np2 + 5};
ops_par_loop(opensbliblock00Kernel082, "Symmetry boundary dir0 side0", opensbliblock00, 3, iteration_range_82_block0,
ops_arg_dat(rhoE_B0, 1, stencil_0_01, "double", OPS_RW),
ops_arg_dat(rhou1_B0, 1, stencil_0_01, "double", OPS_RW),
ops_arg_dat(rhou0_B0, 1, stencil_0_01, "double", OPS_RW),
ops_arg_dat(rho_B0, 1, stencil_0_01, "double", OPS_RW),
ops_arg_dat(rhou2_B0, 1, stencil_0_01, "double", OPS_RW));


int iteration_range_83_block0[] = {block0np0 - 1, block0np0, -5, block0np1 + 5, -5, block0np2 + 5};
ops_par_loop(opensbliblock00Kernel083, "Symmetry boundary dir0 side1", opensbliblock00, 3, iteration_range_83_block0,
ops_arg_dat(rhoE_B0, 1, stencil_0_01, "double", OPS_RW),
ops_arg_dat(rhou1_B0, 1, stencil_0_01, "double", OPS_RW),
ops_arg_dat(rhou0_B0, 1, stencil_0_01, "double", OPS_RW),
ops_arg_dat(rho_B0, 1, stencil_0_01, "double", OPS_RW),
ops_arg_dat(rhou2_B0, 1, stencil_0_01, "double", OPS_RW));


int iteration_range_84_block0[] = {-5, block0np0 + 5, 0, 1, -5, block0np2 + 5};
ops_par_loop(opensbliblock00Kernel084, "Symmetry boundary dir1 side0", opensbliblock00, 3, iteration_range_84_block0,
ops_arg_dat(rhoE_B0, 1, stencil_0_02, "double", OPS_RW),
ops_arg_dat(rhou1_B0, 1, stencil_0_02, "double", OPS_RW),
ops_arg_dat(rhou0_B0, 1, stencil_0_02, "double", OPS_RW),
ops_arg_dat(rho_B0, 1, stencil_0_02, "double", OPS_RW),
ops_arg_dat(rhou2_B0, 1, stencil_0_02, "double", OPS_RW));


int iteration_range_85_block0[] = {-5, block0np0 + 5, block0np1 - 1, block0np1, -5, block0np2 + 5};
ops_par_loop(opensbliblock00Kernel085, "Symmetry boundary dir1 side1", opensbliblock00, 3, iteration_range_85_block0,
ops_arg_dat(rhoE_B0, 1, stencil_0_02, "double", OPS_RW),
ops_arg_dat(rhou1_B0, 1, stencil_0_02, "double", OPS_RW),
ops_arg_dat(rhou0_B0, 1, stencil_0_02, "double", OPS_RW),
ops_arg_dat(rho_B0, 1, stencil_0_02, "double", OPS_RW),
ops_arg_dat(rhou2_B0, 1, stencil_0_02, "double", OPS_RW));


int iteration_range_86_block0[] = {-5, block0np0 + 5, -5, block0np1 + 5, 0, 1};
ops_par_loop(opensbliblock00Kernel086, "Symmetry boundary dir2 side0", opensbliblock00, 3, iteration_range_86_block0,
ops_arg_dat(rhoE_B0, 1, stencil_0_03, "double", OPS_RW),
ops_arg_dat(rhou1_B0, 1, stencil_0_03, "double", OPS_RW),
ops_arg_dat(rhou0_B0, 1, stencil_0_03, "double", OPS_RW),
ops_arg_dat(rho_B0, 1, stencil_0_03, "double", OPS_RW),
ops_arg_dat(rhou2_B0, 1, stencil_0_03, "double", OPS_RW));


int iteration_range_87_block0[] = {-5, block0np0 + 5, -5, block0np1 + 5, block0np2 - 1, block0np2};
ops_par_loop(opensbliblock00Kernel087, "Symmetry boundary dir2 side1", opensbliblock00, 3, iteration_range_87_block0,
ops_arg_dat(rhoE_B0, 1, stencil_0_03, "double", OPS_RW),
ops_arg_dat(rhou1_B0, 1, stencil_0_03, "double", OPS_RW),
ops_arg_dat(rhou0_B0, 1, stencil_0_03, "double", OPS_RW),
ops_arg_dat(rho_B0, 1, stencil_0_03, "double", OPS_RW),
ops_arg_dat(rhou2_B0, 1, stencil_0_03, "double", OPS_RW));


}
if (fmod(iter + 1,213) == 0){
char name[80];
sprintf(name, "opensbli_output_%06d.h5", iter + 1);
ops_fetch_block_hdf5_file(opensbliblock00, name);
ops_fetch_dat_hdf5_file(rho_B0, name);
ops_fetch_dat_hdf5_file(rhou0_B0, name);
ops_fetch_dat_hdf5_file(rhou1_B0, name);
ops_fetch_dat_hdf5_file(rhou2_B0, name);
ops_fetch_dat_hdf5_file(rhoE_B0, name);
}
}
double cpu_end0, elapsed_end0;
ops_timers(&cpu_end0, &elapsed_end0);
ops_printf("\nTimings are:\n");
ops_printf("-----------------------------------------\n");
ops_printf("Total Wall time %lf\n",elapsed_end0-elapsed_start0);
char name[80];
sprintf(name, "opensbli_output.h5");
ops_fetch_block_hdf5_file(opensbliblock00, name);
ops_fetch_dat_hdf5_file(rho_B0, name);
ops_fetch_dat_hdf5_file(rhou0_B0, name);
ops_fetch_dat_hdf5_file(rhou1_B0, name);
ops_fetch_dat_hdf5_file(rhou2_B0, name);
ops_fetch_dat_hdf5_file(rhoE_B0, name);
ops_exit();
//Main program end 
}