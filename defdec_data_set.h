ops_dat p_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
p_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "p_B0");
}
ops_dat Residual0_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
Residual0_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "Residual0_B0");
}
ops_dat Residual1_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
Residual1_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "Residual1_B0");
}
ops_dat Residual2_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
Residual2_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "Residual2_B0");
}
ops_dat Residual3_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
Residual3_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "Residual3_B0");
}
ops_dat Residual4_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
Residual4_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "Residual4_B0");
}
ops_dat rho_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
rho_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "rho_B0");
}
ops_dat rho_old_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
rho_old_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "rho_old_B0");
}
ops_dat rhoE_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
rhoE_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "rhoE_B0");
}
ops_dat rhoE_old_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
rhoE_old_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "rhoE_old_B0");
}
ops_dat rhou0_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
rhou0_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "rhou0_B0");
}
ops_dat rhou0_old_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
rhou0_old_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "rhou0_old_B0");
}
ops_dat rhou1_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
rhou1_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "rhou1_B0");
}
ops_dat rhou1_old_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
rhou1_old_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "rhou1_old_B0");
}
ops_dat rhou2_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
rhou2_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "rhou2_B0");
}
ops_dat rhou2_old_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
rhou2_old_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "rhou2_old_B0");
}
ops_dat T_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
T_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "T_B0");
}
ops_dat u0_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
u0_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "u0_B0");
}
ops_dat u1_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
u1_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "u1_B0");
}
ops_dat u2_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
u2_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "u2_B0");
}
ops_dat wk0_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk0_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk0_B0");
}
ops_dat wk10_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk10_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk10_B0");
}
ops_dat wk11_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk11_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk11_B0");
}
ops_dat wk12_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk12_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk12_B0");
}
ops_dat wk13_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk13_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk13_B0");
}
ops_dat wk14_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk14_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk14_B0");
}
ops_dat wk15_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk15_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk15_B0");
}
ops_dat wk16_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk16_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk16_B0");
}
ops_dat wk17_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk17_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk17_B0");
}
ops_dat wk18_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk18_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk18_B0");
}
ops_dat wk19_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk19_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk19_B0");
}
ops_dat wk1_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk1_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk1_B0");
}
ops_dat wk20_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk20_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk20_B0");
}
ops_dat wk21_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk21_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk21_B0");
}
ops_dat wk22_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk22_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk22_B0");
}
ops_dat wk23_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk23_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk23_B0");
}
ops_dat wk24_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk24_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk24_B0");
}
ops_dat wk25_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk25_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk25_B0");
}
ops_dat wk26_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk26_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk26_B0");
}
ops_dat wk27_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk27_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk27_B0");
}
ops_dat wk28_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk28_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk28_B0");
}
ops_dat wk29_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk29_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk29_B0");
}
ops_dat wk2_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk2_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk2_B0");
}
ops_dat wk30_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk30_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk30_B0");
}
ops_dat wk31_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk31_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk31_B0");
}
ops_dat wk32_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk32_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk32_B0");
}
ops_dat wk33_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk33_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk33_B0");
}
ops_dat wk34_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk34_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk34_B0");
}
ops_dat wk35_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk35_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk35_B0");
}
ops_dat wk36_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk36_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk36_B0");
}
ops_dat wk37_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk37_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk37_B0");
}
ops_dat wk38_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk38_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk38_B0");
}
ops_dat wk39_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk39_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk39_B0");
}
ops_dat wk3_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk3_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk3_B0");
}
ops_dat wk40_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk40_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk40_B0");
}
ops_dat wk41_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk41_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk41_B0");
}
ops_dat wk42_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk42_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk42_B0");
}
ops_dat wk43_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk43_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk43_B0");
}
ops_dat wk44_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk44_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk44_B0");
}
ops_dat wk4_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk4_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk4_B0");
}
ops_dat wk5_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk5_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk5_B0");
}
ops_dat wk6_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk6_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk6_B0");
}
ops_dat wk7_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk7_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk7_B0");
}
ops_dat wk8_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk8_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk8_B0");
}
ops_dat wk9_B0;
{
int halo_p[] = {20, 20, 20};
int halo_m[] = {-20, -20, -20};
int size[] = {block0np0, block0np1, block0np2};
int base[] = {0, 0, 0};
double* value = NULL;
wk9_B0 = ops_decl_dat(opensbliblock00, 1, size, base, halo_m, halo_p, value, "double", "wk9_B0");
}