#ifndef OPENSBLIBLOCK00_KERNEL_H
#define OPENSBLIBLOCK00_KERNEL_H
 void opensbliblock00Kernel088(double *rhou1_B0, double *rhoE_B0, double *rhou0_B0, double *rho_B0, double *rhou2_B0,
const int *idx)
{
   double u0 = 0.0;
   double r = 0.0;
   double x0 = 0.0;
   double u2 = 0.0;
   double p = 0.0;
   double x2 = 0.0;
   double x1 = 0.0;
   double u1 = 0.0;
   x0 = Delta0block0*idx[0];

   x1 = Delta1block0*idx[1];

   x2 = Delta2block0*idx[2];

   u0 = sin(x0)*cos(x1)*cos(x2);

   u1 = -sin(x1)*cos(x0)*cos(x2);

   u2 = 0.0;

   p = (0.0625*cos(2.0*x0) + 0.0625*cos(2.0*x1))*(cos(2.0*x2) + 2.0) + 1.0/(pow(Minf, 2)*gama);

   r = pow(Minf, 2)*gama*p;

   rho_B0[OPS_ACC3(0,0,0)] = r;

   rhou0_B0[OPS_ACC2(0,0,0)] = r*u0;

   rhou1_B0[OPS_ACC0(0,0,0)] = r*u1;

   rhou2_B0[OPS_ACC4(0,0,0)] = r*u2;

   rhoE_B0[OPS_ACC1(0,0,0)] = p/(gama - 1) + 0.5*r*(pow(u0, 2) + pow(u1, 2) + pow(u2, 2));

}

void opensbliblock00Kernel082(double *rhoE_B0, double *rhou1_B0, double *rhou0_B0, double *rho_B0, double *rhou2_B0)
{
   rho_B0[OPS_ACC3(-1,0,0)] = rho_B0[OPS_ACC3(1,0,0)];

   rhou0_B0[OPS_ACC2(-1,0,0)] = -1.0*rhou0_B0[OPS_ACC2(1,0,0)];

   rhou1_B0[OPS_ACC1(-1,0,0)] = rhou1_B0[OPS_ACC1(1,0,0)];

   rhou2_B0[OPS_ACC4(-1,0,0)] = rhou2_B0[OPS_ACC4(1,0,0)];

   rhoE_B0[OPS_ACC0(-1,0,0)] = rhoE_B0[OPS_ACC0(1,0,0)];

   rho_B0[OPS_ACC3(-2,0,0)] = rho_B0[OPS_ACC3(2,0,0)];

   rhou0_B0[OPS_ACC2(-2,0,0)] = -1.0*rhou0_B0[OPS_ACC2(2,0,0)];

   rhou1_B0[OPS_ACC1(-2,0,0)] = rhou1_B0[OPS_ACC1(2,0,0)];

   rhou2_B0[OPS_ACC4(-2,0,0)] = rhou2_B0[OPS_ACC4(2,0,0)];

   rhoE_B0[OPS_ACC0(-2,0,0)] = rhoE_B0[OPS_ACC0(2,0,0)];

   rho_B0[OPS_ACC3(-3,0,0)] = rho_B0[OPS_ACC3(3,0,0)];

   rhou0_B0[OPS_ACC2(-3,0,0)] = -1.0*rhou0_B0[OPS_ACC2(3,0,0)];

   rhou1_B0[OPS_ACC1(-3,0,0)] = rhou1_B0[OPS_ACC1(3,0,0)];

   rhou2_B0[OPS_ACC4(-3,0,0)] = rhou2_B0[OPS_ACC4(3,0,0)];

   rhoE_B0[OPS_ACC0(-3,0,0)] = rhoE_B0[OPS_ACC0(3,0,0)];

   rho_B0[OPS_ACC3(-4,0,0)] = rho_B0[OPS_ACC3(4,0,0)];

   rhou0_B0[OPS_ACC2(-4,0,0)] = -1.0*rhou0_B0[OPS_ACC2(4,0,0)];

   rhou1_B0[OPS_ACC1(-4,0,0)] = rhou1_B0[OPS_ACC1(4,0,0)];

   rhou2_B0[OPS_ACC4(-4,0,0)] = rhou2_B0[OPS_ACC4(4,0,0)];

   rhoE_B0[OPS_ACC0(-4,0,0)] = rhoE_B0[OPS_ACC0(4,0,0)];

   rho_B0[OPS_ACC3(-5,0,0)] = rho_B0[OPS_ACC3(5,0,0)];

   rhou0_B0[OPS_ACC2(-5,0,0)] = -1.0*rhou0_B0[OPS_ACC2(5,0,0)];

   rhou1_B0[OPS_ACC1(-5,0,0)] = rhou1_B0[OPS_ACC1(5,0,0)];

   rhou2_B0[OPS_ACC4(-5,0,0)] = rhou2_B0[OPS_ACC4(5,0,0)];

   rhoE_B0[OPS_ACC0(-5,0,0)] = rhoE_B0[OPS_ACC0(5,0,0)];

}

void opensbliblock00Kernel083(double *rhoE_B0, double *rhou1_B0, double *rhou0_B0, double *rho_B0, double *rhou2_B0)
{
   rho_B0[OPS_ACC3(1,0,0)] = rho_B0[OPS_ACC3(-1,0,0)];

   rhou0_B0[OPS_ACC2(1,0,0)] = -1.0*rhou0_B0[OPS_ACC2(-1,0,0)];

   rhou1_B0[OPS_ACC1(1,0,0)] = rhou1_B0[OPS_ACC1(-1,0,0)];

   rhou2_B0[OPS_ACC4(1,0,0)] = rhou2_B0[OPS_ACC4(-1,0,0)];

   rhoE_B0[OPS_ACC0(1,0,0)] = rhoE_B0[OPS_ACC0(-1,0,0)];

   rho_B0[OPS_ACC3(2,0,0)] = rho_B0[OPS_ACC3(-2,0,0)];

   rhou0_B0[OPS_ACC2(2,0,0)] = -1.0*rhou0_B0[OPS_ACC2(-2,0,0)];

   rhou1_B0[OPS_ACC1(2,0,0)] = rhou1_B0[OPS_ACC1(-2,0,0)];

   rhou2_B0[OPS_ACC4(2,0,0)] = rhou2_B0[OPS_ACC4(-2,0,0)];

   rhoE_B0[OPS_ACC0(2,0,0)] = rhoE_B0[OPS_ACC0(-2,0,0)];

   rho_B0[OPS_ACC3(3,0,0)] = rho_B0[OPS_ACC3(-3,0,0)];

   rhou0_B0[OPS_ACC2(3,0,0)] = -1.0*rhou0_B0[OPS_ACC2(-3,0,0)];

   rhou1_B0[OPS_ACC1(3,0,0)] = rhou1_B0[OPS_ACC1(-3,0,0)];

   rhou2_B0[OPS_ACC4(3,0,0)] = rhou2_B0[OPS_ACC4(-3,0,0)];

   rhoE_B0[OPS_ACC0(3,0,0)] = rhoE_B0[OPS_ACC0(-3,0,0)];

   rho_B0[OPS_ACC3(4,0,0)] = rho_B0[OPS_ACC3(-4,0,0)];

   rhou0_B0[OPS_ACC2(4,0,0)] = -1.0*rhou0_B0[OPS_ACC2(-4,0,0)];

   rhou1_B0[OPS_ACC1(4,0,0)] = rhou1_B0[OPS_ACC1(-4,0,0)];

   rhou2_B0[OPS_ACC4(4,0,0)] = rhou2_B0[OPS_ACC4(-4,0,0)];

   rhoE_B0[OPS_ACC0(4,0,0)] = rhoE_B0[OPS_ACC0(-4,0,0)];

   rho_B0[OPS_ACC3(5,0,0)] = rho_B0[OPS_ACC3(-5,0,0)];

   rhou0_B0[OPS_ACC2(5,0,0)] = -1.0*rhou0_B0[OPS_ACC2(-5,0,0)];

   rhou1_B0[OPS_ACC1(5,0,0)] = rhou1_B0[OPS_ACC1(-5,0,0)];

   rhou2_B0[OPS_ACC4(5,0,0)] = rhou2_B0[OPS_ACC4(-5,0,0)];

   rhoE_B0[OPS_ACC0(5,0,0)] = rhoE_B0[OPS_ACC0(-5,0,0)];

}

void opensbliblock00Kernel084(double *rhoE_B0, double *rhou1_B0, double *rhou0_B0, double *rho_B0, double *rhou2_B0)
{
   rho_B0[OPS_ACC3(0,-1,0)] = rho_B0[OPS_ACC3(0,1,0)];

   rhou0_B0[OPS_ACC2(0,-1,0)] = rhou0_B0[OPS_ACC2(0,1,0)];

   rhou1_B0[OPS_ACC1(0,-1,0)] = -1.0*rhou1_B0[OPS_ACC1(0,1,0)];

   rhou2_B0[OPS_ACC4(0,-1,0)] = rhou2_B0[OPS_ACC4(0,1,0)];

   rhoE_B0[OPS_ACC0(0,-1,0)] = rhoE_B0[OPS_ACC0(0,1,0)];

   rho_B0[OPS_ACC3(0,-2,0)] = rho_B0[OPS_ACC3(0,2,0)];

   rhou0_B0[OPS_ACC2(0,-2,0)] = rhou0_B0[OPS_ACC2(0,2,0)];

   rhou1_B0[OPS_ACC1(0,-2,0)] = -1.0*rhou1_B0[OPS_ACC1(0,2,0)];

   rhou2_B0[OPS_ACC4(0,-2,0)] = rhou2_B0[OPS_ACC4(0,2,0)];

   rhoE_B0[OPS_ACC0(0,-2,0)] = rhoE_B0[OPS_ACC0(0,2,0)];

   rho_B0[OPS_ACC3(0,-3,0)] = rho_B0[OPS_ACC3(0,3,0)];

   rhou0_B0[OPS_ACC2(0,-3,0)] = rhou0_B0[OPS_ACC2(0,3,0)];

   rhou1_B0[OPS_ACC1(0,-3,0)] = -1.0*rhou1_B0[OPS_ACC1(0,3,0)];

   rhou2_B0[OPS_ACC4(0,-3,0)] = rhou2_B0[OPS_ACC4(0,3,0)];

   rhoE_B0[OPS_ACC0(0,-3,0)] = rhoE_B0[OPS_ACC0(0,3,0)];

   rho_B0[OPS_ACC3(0,-4,0)] = rho_B0[OPS_ACC3(0,4,0)];

   rhou0_B0[OPS_ACC2(0,-4,0)] = rhou0_B0[OPS_ACC2(0,4,0)];

   rhou1_B0[OPS_ACC1(0,-4,0)] = -1.0*rhou1_B0[OPS_ACC1(0,4,0)];

   rhou2_B0[OPS_ACC4(0,-4,0)] = rhou2_B0[OPS_ACC4(0,4,0)];

   rhoE_B0[OPS_ACC0(0,-4,0)] = rhoE_B0[OPS_ACC0(0,4,0)];

   rho_B0[OPS_ACC3(0,-5,0)] = rho_B0[OPS_ACC3(0,5,0)];

   rhou0_B0[OPS_ACC2(0,-5,0)] = rhou0_B0[OPS_ACC2(0,5,0)];

   rhou1_B0[OPS_ACC1(0,-5,0)] = -1.0*rhou1_B0[OPS_ACC1(0,5,0)];

   rhou2_B0[OPS_ACC4(0,-5,0)] = rhou2_B0[OPS_ACC4(0,5,0)];

   rhoE_B0[OPS_ACC0(0,-5,0)] = rhoE_B0[OPS_ACC0(0,5,0)];

}

void opensbliblock00Kernel085(double *rhoE_B0, double *rhou1_B0, double *rhou0_B0, double *rho_B0, double *rhou2_B0)
{
   rho_B0[OPS_ACC3(0,1,0)] = rho_B0[OPS_ACC3(0,-1,0)];

   rhou0_B0[OPS_ACC2(0,1,0)] = rhou0_B0[OPS_ACC2(0,-1,0)];

   rhou1_B0[OPS_ACC1(0,1,0)] = -1.0*rhou1_B0[OPS_ACC1(0,-1,0)];

   rhou2_B0[OPS_ACC4(0,1,0)] = rhou2_B0[OPS_ACC4(0,-1,0)];

   rhoE_B0[OPS_ACC0(0,1,0)] = rhoE_B0[OPS_ACC0(0,-1,0)];

   rho_B0[OPS_ACC3(0,2,0)] = rho_B0[OPS_ACC3(0,-2,0)];

   rhou0_B0[OPS_ACC2(0,2,0)] = rhou0_B0[OPS_ACC2(0,-2,0)];

   rhou1_B0[OPS_ACC1(0,2,0)] = -1.0*rhou1_B0[OPS_ACC1(0,-2,0)];

   rhou2_B0[OPS_ACC4(0,2,0)] = rhou2_B0[OPS_ACC4(0,-2,0)];

   rhoE_B0[OPS_ACC0(0,2,0)] = rhoE_B0[OPS_ACC0(0,-2,0)];

   rho_B0[OPS_ACC3(0,3,0)] = rho_B0[OPS_ACC3(0,-3,0)];

   rhou0_B0[OPS_ACC2(0,3,0)] = rhou0_B0[OPS_ACC2(0,-3,0)];

   rhou1_B0[OPS_ACC1(0,3,0)] = -1.0*rhou1_B0[OPS_ACC1(0,-3,0)];

   rhou2_B0[OPS_ACC4(0,3,0)] = rhou2_B0[OPS_ACC4(0,-3,0)];

   rhoE_B0[OPS_ACC0(0,3,0)] = rhoE_B0[OPS_ACC0(0,-3,0)];

   rho_B0[OPS_ACC3(0,4,0)] = rho_B0[OPS_ACC3(0,-4,0)];

   rhou0_B0[OPS_ACC2(0,4,0)] = rhou0_B0[OPS_ACC2(0,-4,0)];

   rhou1_B0[OPS_ACC1(0,4,0)] = -1.0*rhou1_B0[OPS_ACC1(0,-4,0)];

   rhou2_B0[OPS_ACC4(0,4,0)] = rhou2_B0[OPS_ACC4(0,-4,0)];

   rhoE_B0[OPS_ACC0(0,4,0)] = rhoE_B0[OPS_ACC0(0,-4,0)];

   rho_B0[OPS_ACC3(0,5,0)] = rho_B0[OPS_ACC3(0,-5,0)];

   rhou0_B0[OPS_ACC2(0,5,0)] = rhou0_B0[OPS_ACC2(0,-5,0)];

   rhou1_B0[OPS_ACC1(0,5,0)] = -1.0*rhou1_B0[OPS_ACC1(0,-5,0)];

   rhou2_B0[OPS_ACC4(0,5,0)] = rhou2_B0[OPS_ACC4(0,-5,0)];

   rhoE_B0[OPS_ACC0(0,5,0)] = rhoE_B0[OPS_ACC0(0,-5,0)];

}

void opensbliblock00Kernel086(double *rhoE_B0, double *rhou1_B0, double *rhou0_B0, double *rho_B0, double *rhou2_B0)
{
   rho_B0[OPS_ACC3(0,0,-1)] = rho_B0[OPS_ACC3(0,0,1)];

   rhou0_B0[OPS_ACC2(0,0,-1)] = rhou0_B0[OPS_ACC2(0,0,1)];

   rhou1_B0[OPS_ACC1(0,0,-1)] = rhou1_B0[OPS_ACC1(0,0,1)];

   rhou2_B0[OPS_ACC4(0,0,-1)] = -1.0*rhou2_B0[OPS_ACC4(0,0,1)];

   rhoE_B0[OPS_ACC0(0,0,-1)] = rhoE_B0[OPS_ACC0(0,0,1)];

   rho_B0[OPS_ACC3(0,0,-2)] = rho_B0[OPS_ACC3(0,0,2)];

   rhou0_B0[OPS_ACC2(0,0,-2)] = rhou0_B0[OPS_ACC2(0,0,2)];

   rhou1_B0[OPS_ACC1(0,0,-2)] = rhou1_B0[OPS_ACC1(0,0,2)];

   rhou2_B0[OPS_ACC4(0,0,-2)] = -1.0*rhou2_B0[OPS_ACC4(0,0,2)];

   rhoE_B0[OPS_ACC0(0,0,-2)] = rhoE_B0[OPS_ACC0(0,0,2)];

   rho_B0[OPS_ACC3(0,0,-3)] = rho_B0[OPS_ACC3(0,0,3)];

   rhou0_B0[OPS_ACC2(0,0,-3)] = rhou0_B0[OPS_ACC2(0,0,3)];

   rhou1_B0[OPS_ACC1(0,0,-3)] = rhou1_B0[OPS_ACC1(0,0,3)];

   rhou2_B0[OPS_ACC4(0,0,-3)] = -1.0*rhou2_B0[OPS_ACC4(0,0,3)];

   rhoE_B0[OPS_ACC0(0,0,-3)] = rhoE_B0[OPS_ACC0(0,0,3)];

   rho_B0[OPS_ACC3(0,0,-4)] = rho_B0[OPS_ACC3(0,0,4)];

   rhou0_B0[OPS_ACC2(0,0,-4)] = rhou0_B0[OPS_ACC2(0,0,4)];

   rhou1_B0[OPS_ACC1(0,0,-4)] = rhou1_B0[OPS_ACC1(0,0,4)];

   rhou2_B0[OPS_ACC4(0,0,-4)] = -1.0*rhou2_B0[OPS_ACC4(0,0,4)];

   rhoE_B0[OPS_ACC0(0,0,-4)] = rhoE_B0[OPS_ACC0(0,0,4)];

   rho_B0[OPS_ACC3(0,0,-5)] = rho_B0[OPS_ACC3(0,0,5)];

   rhou0_B0[OPS_ACC2(0,0,-5)] = rhou0_B0[OPS_ACC2(0,0,5)];

   rhou1_B0[OPS_ACC1(0,0,-5)] = rhou1_B0[OPS_ACC1(0,0,5)];

   rhou2_B0[OPS_ACC4(0,0,-5)] = -1.0*rhou2_B0[OPS_ACC4(0,0,5)];

   rhoE_B0[OPS_ACC0(0,0,-5)] = rhoE_B0[OPS_ACC0(0,0,5)];

}

void opensbliblock00Kernel087(double *rhoE_B0, double *rhou1_B0, double *rhou0_B0, double *rho_B0, double *rhou2_B0)
{
   rho_B0[OPS_ACC3(0,0,1)] = rho_B0[OPS_ACC3(0,0,-1)];

   rhou0_B0[OPS_ACC2(0,0,1)] = rhou0_B0[OPS_ACC2(0,0,-1)];

   rhou1_B0[OPS_ACC1(0,0,1)] = rhou1_B0[OPS_ACC1(0,0,-1)];

   rhou2_B0[OPS_ACC4(0,0,1)] = -1.0*rhou2_B0[OPS_ACC4(0,0,-1)];

   rhoE_B0[OPS_ACC0(0,0,1)] = rhoE_B0[OPS_ACC0(0,0,-1)];

   rho_B0[OPS_ACC3(0,0,2)] = rho_B0[OPS_ACC3(0,0,-2)];

   rhou0_B0[OPS_ACC2(0,0,2)] = rhou0_B0[OPS_ACC2(0,0,-2)];

   rhou1_B0[OPS_ACC1(0,0,2)] = rhou1_B0[OPS_ACC1(0,0,-2)];

   rhou2_B0[OPS_ACC4(0,0,2)] = -1.0*rhou2_B0[OPS_ACC4(0,0,-2)];

   rhoE_B0[OPS_ACC0(0,0,2)] = rhoE_B0[OPS_ACC0(0,0,-2)];

   rho_B0[OPS_ACC3(0,0,3)] = rho_B0[OPS_ACC3(0,0,-3)];

   rhou0_B0[OPS_ACC2(0,0,3)] = rhou0_B0[OPS_ACC2(0,0,-3)];

   rhou1_B0[OPS_ACC1(0,0,3)] = rhou1_B0[OPS_ACC1(0,0,-3)];

   rhou2_B0[OPS_ACC4(0,0,3)] = -1.0*rhou2_B0[OPS_ACC4(0,0,-3)];

   rhoE_B0[OPS_ACC0(0,0,3)] = rhoE_B0[OPS_ACC0(0,0,-3)];

   rho_B0[OPS_ACC3(0,0,4)] = rho_B0[OPS_ACC3(0,0,-4)];

   rhou0_B0[OPS_ACC2(0,0,4)] = rhou0_B0[OPS_ACC2(0,0,-4)];

   rhou1_B0[OPS_ACC1(0,0,4)] = rhou1_B0[OPS_ACC1(0,0,-4)];

   rhou2_B0[OPS_ACC4(0,0,4)] = -1.0*rhou2_B0[OPS_ACC4(0,0,-4)];

   rhoE_B0[OPS_ACC0(0,0,4)] = rhoE_B0[OPS_ACC0(0,0,-4)];

   rho_B0[OPS_ACC3(0,0,5)] = rho_B0[OPS_ACC3(0,0,-5)];

   rhou0_B0[OPS_ACC2(0,0,5)] = rhou0_B0[OPS_ACC2(0,0,-5)];

   rhou1_B0[OPS_ACC1(0,0,5)] = rhou1_B0[OPS_ACC1(0,0,-5)];

   rhou2_B0[OPS_ACC4(0,0,5)] = -1.0*rhou2_B0[OPS_ACC4(0,0,-5)];

   rhoE_B0[OPS_ACC0(0,0,5)] = rhoE_B0[OPS_ACC0(0,0,-5)];

}

 void opensbliblock00Kernel089(const double *rhou1_B0, const double *rhoE_B0, const double *rhou0_B0, const double
*rho_B0, const double *rhou2_B0, double *rhou1_old_B0, double *rhou2_old_B0, double *rhou0_old_B0, double *rho_old_B0,
double *rhoE_old_B0)
{
   rho_old_B0[OPS_ACC8(0,0,0)] = rho_B0[OPS_ACC3(0,0,0)];

   rhou0_old_B0[OPS_ACC7(0,0,0)] = rhou0_B0[OPS_ACC2(0,0,0)];

   rhou1_old_B0[OPS_ACC5(0,0,0)] = rhou1_B0[OPS_ACC0(0,0,0)];

   rhou2_old_B0[OPS_ACC6(0,0,0)] = rhou2_B0[OPS_ACC4(0,0,0)];

   rhoE_old_B0[OPS_ACC9(0,0,0)] = rhoE_B0[OPS_ACC1(0,0,0)];

}

void opensbliblock00Kernel041(const double *rho_B0, const double *rhou2_B0, double *u2_B0)
{
   u2_B0[OPS_ACC2(0,0,0)] = rhou2_B0[OPS_ACC1(0,0,0)]/rho_B0[OPS_ACC0(0,0,0)];

}

void opensbliblock00Kernel003(const double *rhou0_B0, const double *rho_B0, double *u0_B0)
{
   u0_B0[OPS_ACC2(0,0,0)] = rhou0_B0[OPS_ACC0(0,0,0)]/rho_B0[OPS_ACC1(0,0,0)];

}

void opensbliblock00Kernel023(const double *rhou1_B0, const double *rho_B0, double *u1_B0)
{
   u1_B0[OPS_ACC2(0,0,0)] = rhou1_B0[OPS_ACC0(0,0,0)]/rho_B0[OPS_ACC1(0,0,0)];

}

 void opensbliblock00Kernel007(const double *rhoE_B0, const double *rho_B0, const double *u0_B0, const double *u1_B0,
const double *u2_B0, double *p_B0)
{
    p_B0[OPS_ACC5(0,0,0)] = (gama - 1)*(rhoE_B0[OPS_ACC0(0,0,0)] -
      rc6*rho_B0[OPS_ACC1(0,0,0)]*pow(u0_B0[OPS_ACC2(0,0,0)], 2) -
      rc6*rho_B0[OPS_ACC1(0,0,0)]*pow(u1_B0[OPS_ACC3(0,0,0)], 2) -
      rc6*rho_B0[OPS_ACC1(0,0,0)]*pow(u2_B0[OPS_ACC4(0,0,0)], 2));

}

void opensbliblock00Kernel080(const double *rho_B0, const double *p_B0, double *T_B0)
{
   T_B0[OPS_ACC2(0,0,0)] = pow(Minf, 2)*gama*p_B0[OPS_ACC1(0,0,0)]/rho_B0[OPS_ACC0(0,0,0)];

}

 void opensbliblock00Kernel000(double *Residual4_B0, double *Residual3_B0, double *Residual0_B0, double *Residual2_B0,
double *Residual1_B0)
{
   Residual0_B0[OPS_ACC2(0,0,0)] = 0;

   Residual1_B0[OPS_ACC4(0,0,0)] = 0;

   Residual2_B0[OPS_ACC3(0,0,0)] = 0;

   Residual3_B0[OPS_ACC1(0,0,0)] = 0;

   Residual4_B0[OPS_ACC0(0,0,0)] = 0;

}

 void opensbliblock00Kernel001(const double *rhou2_B0, const double *rhoE_B0, const double *rho_B0, const double *p_B0,
const double *rhou1_B0, const double *rhou0_B0, const double *u0_B0, double *wk40_B0, double *wk43_B0, double *wk41_B0,
double *wk39_B0, double *wk42_B0, double *wk44_B0)
{
   wk39_B0[OPS_ACC10(0,0,0)] = rhou1_B0[OPS_ACC4(0,0,0)]*u0_B0[OPS_ACC6(0,0,0)];

   wk40_B0[OPS_ACC7(0,0,0)] = rhou2_B0[OPS_ACC0(0,0,0)]*u0_B0[OPS_ACC6(0,0,0)];

   wk41_B0[OPS_ACC9(0,0,0)] = rho_B0[OPS_ACC2(0,0,0)]*u0_B0[OPS_ACC6(0,0,0)];

   wk42_B0[OPS_ACC11(0,0,0)] = rhoE_B0[OPS_ACC1(0,0,0)]*u0_B0[OPS_ACC6(0,0,0)];

   wk43_B0[OPS_ACC8(0,0,0)] = rhou0_B0[OPS_ACC5(0,0,0)]*u0_B0[OPS_ACC6(0,0,0)];

   wk44_B0[OPS_ACC12(0,0,0)] = p_B0[OPS_ACC3(0,0,0)]*u0_B0[OPS_ACC6(0,0,0)];

}

void opensbliblock00Kernel004(const double *wk39_B0, double *wk0_B0)
{
    wk0_B0[OPS_ACC1(0,0,0)] = inv_0*(-rc29*wk39_B0[OPS_ACC0(2,0,0)] + (rc30)*wk39_B0[OPS_ACC0(3,0,0)] -
      rc31*wk39_B0[OPS_ACC0(4,0,0)] - rc32*wk39_B0[OPS_ACC0(-5,0,0)] + (rc32)*wk39_B0[OPS_ACC0(5,0,0)] +
      (rc31)*wk39_B0[OPS_ACC0(-4,0,0)] + (rc29)*wk39_B0[OPS_ACC0(-2,0,0)] - rc30*wk39_B0[OPS_ACC0(-3,0,0)] +
      (rc33)*wk39_B0[OPS_ACC0(1,0,0)] - rc33*wk39_B0[OPS_ACC0(-1,0,0)]);

}

void opensbliblock00Kernel006(const double *wk40_B0, double *wk1_B0)
{
    wk1_B0[OPS_ACC1(0,0,0)] = inv_0*(-rc30*wk40_B0[OPS_ACC0(-3,0,0)] - rc31*wk40_B0[OPS_ACC0(4,0,0)] +
      (rc29)*wk40_B0[OPS_ACC0(-2,0,0)] - rc33*wk40_B0[OPS_ACC0(-1,0,0)] + (rc32)*wk40_B0[OPS_ACC0(5,0,0)] +
      (rc33)*wk40_B0[OPS_ACC0(1,0,0)] - rc32*wk40_B0[OPS_ACC0(-5,0,0)] - rc29*wk40_B0[OPS_ACC0(2,0,0)] +
      (rc31)*wk40_B0[OPS_ACC0(-4,0,0)] + (rc30)*wk40_B0[OPS_ACC0(3,0,0)]);

}

void opensbliblock00Kernel008(const double *p_B0, double *wk2_B0)
{
    wk2_B0[OPS_ACC1(0,0,0)] = inv_0*(-rc29*p_B0[OPS_ACC0(2,0,0)] - rc32*p_B0[OPS_ACC0(-5,0,0)] +
      (rc33)*p_B0[OPS_ACC0(1,0,0)] + (rc32)*p_B0[OPS_ACC0(5,0,0)] - rc33*p_B0[OPS_ACC0(-1,0,0)] -
      rc31*p_B0[OPS_ACC0(4,0,0)] - rc30*p_B0[OPS_ACC0(-3,0,0)] + (rc31)*p_B0[OPS_ACC0(-4,0,0)] +
      (rc30)*p_B0[OPS_ACC0(3,0,0)] + (rc29)*p_B0[OPS_ACC0(-2,0,0)]);

}

void opensbliblock00Kernel009(const double *rhou2_B0, double *wk3_B0)
{
    wk3_B0[OPS_ACC1(0,0,0)] = inv_0*((rc30)*rhou2_B0[OPS_ACC0(3,0,0)] - rc29*rhou2_B0[OPS_ACC0(2,0,0)] -
      rc33*rhou2_B0[OPS_ACC0(-1,0,0)] + (rc33)*rhou2_B0[OPS_ACC0(1,0,0)] + (rc29)*rhou2_B0[OPS_ACC0(-2,0,0)] -
      rc30*rhou2_B0[OPS_ACC0(-3,0,0)] + (rc31)*rhou2_B0[OPS_ACC0(-4,0,0)] + (rc32)*rhou2_B0[OPS_ACC0(5,0,0)] -
      rc32*rhou2_B0[OPS_ACC0(-5,0,0)] - rc31*rhou2_B0[OPS_ACC0(4,0,0)]);

}

void opensbliblock00Kernel011(const double *wk41_B0, double *wk4_B0)
{
    wk4_B0[OPS_ACC1(0,0,0)] = inv_0*((rc30)*wk41_B0[OPS_ACC0(3,0,0)] + (rc32)*wk41_B0[OPS_ACC0(5,0,0)] -
      rc29*wk41_B0[OPS_ACC0(2,0,0)] - rc31*wk41_B0[OPS_ACC0(4,0,0)] - rc32*wk41_B0[OPS_ACC0(-5,0,0)] -
      rc30*wk41_B0[OPS_ACC0(-3,0,0)] + (rc31)*wk41_B0[OPS_ACC0(-4,0,0)] + (rc29)*wk41_B0[OPS_ACC0(-2,0,0)] +
      (rc33)*wk41_B0[OPS_ACC0(1,0,0)] - rc33*wk41_B0[OPS_ACC0(-1,0,0)]);

}

void opensbliblock00Kernel013(const double *wk42_B0, double *wk5_B0)
{
    wk5_B0[OPS_ACC1(0,0,0)] = inv_0*(-rc33*wk42_B0[OPS_ACC0(-1,0,0)] + (rc29)*wk42_B0[OPS_ACC0(-2,0,0)] -
      rc31*wk42_B0[OPS_ACC0(4,0,0)] + (rc32)*wk42_B0[OPS_ACC0(5,0,0)] + (rc31)*wk42_B0[OPS_ACC0(-4,0,0)] -
      rc29*wk42_B0[OPS_ACC0(2,0,0)] - rc30*wk42_B0[OPS_ACC0(-3,0,0)] + (rc30)*wk42_B0[OPS_ACC0(3,0,0)] -
      rc32*wk42_B0[OPS_ACC0(-5,0,0)] + (rc33)*wk42_B0[OPS_ACC0(1,0,0)]);

}

void opensbliblock00Kernel014(const double *rho_B0, double *wk6_B0)
{
    wk6_B0[OPS_ACC1(0,0,0)] = inv_0*((rc33)*rho_B0[OPS_ACC0(1,0,0)] - rc29*rho_B0[OPS_ACC0(2,0,0)] -
      rc31*rho_B0[OPS_ACC0(4,0,0)] + (rc30)*rho_B0[OPS_ACC0(3,0,0)] + (rc32)*rho_B0[OPS_ACC0(5,0,0)] +
      (rc31)*rho_B0[OPS_ACC0(-4,0,0)] - rc32*rho_B0[OPS_ACC0(-5,0,0)] - rc30*rho_B0[OPS_ACC0(-3,0,0)] -
      rc33*rho_B0[OPS_ACC0(-1,0,0)] + (rc29)*rho_B0[OPS_ACC0(-2,0,0)]);

}

void opensbliblock00Kernel015(const double *u0_B0, double *wk7_B0)
{
    wk7_B0[OPS_ACC1(0,0,0)] = inv_0*((rc30)*u0_B0[OPS_ACC0(3,0,0)] - rc29*u0_B0[OPS_ACC0(2,0,0)] -
      rc33*u0_B0[OPS_ACC0(-1,0,0)] + (rc33)*u0_B0[OPS_ACC0(1,0,0)] + (rc29)*u0_B0[OPS_ACC0(-2,0,0)] -
      rc30*u0_B0[OPS_ACC0(-3,0,0)] + (rc31)*u0_B0[OPS_ACC0(-4,0,0)] + (rc32)*u0_B0[OPS_ACC0(5,0,0)] -
      rc32*u0_B0[OPS_ACC0(-5,0,0)] - rc31*u0_B0[OPS_ACC0(4,0,0)]);

}

void opensbliblock00Kernel016(const double *rhou1_B0, double *wk8_B0)
{
    wk8_B0[OPS_ACC1(0,0,0)] = inv_0*((rc32)*rhou1_B0[OPS_ACC0(5,0,0)] + (rc31)*rhou1_B0[OPS_ACC0(-4,0,0)] -
      rc30*rhou1_B0[OPS_ACC0(-3,0,0)] + (rc33)*rhou1_B0[OPS_ACC0(1,0,0)] - rc33*rhou1_B0[OPS_ACC0(-1,0,0)] -
      rc29*rhou1_B0[OPS_ACC0(2,0,0)] + (rc29)*rhou1_B0[OPS_ACC0(-2,0,0)] + (rc30)*rhou1_B0[OPS_ACC0(3,0,0)] -
      rc31*rhou1_B0[OPS_ACC0(4,0,0)] - rc32*rhou1_B0[OPS_ACC0(-5,0,0)]);

}

void opensbliblock00Kernel018(const double *wk43_B0, double *wk9_B0)
{
    wk9_B0[OPS_ACC1(0,0,0)] = inv_0*(-rc33*wk43_B0[OPS_ACC0(-1,0,0)] - rc30*wk43_B0[OPS_ACC0(-3,0,0)] +
      (rc29)*wk43_B0[OPS_ACC0(-2,0,0)] - rc32*wk43_B0[OPS_ACC0(-5,0,0)] + (rc31)*wk43_B0[OPS_ACC0(-4,0,0)] +
      (rc32)*wk43_B0[OPS_ACC0(5,0,0)] + (rc30)*wk43_B0[OPS_ACC0(3,0,0)] - rc31*wk43_B0[OPS_ACC0(4,0,0)] -
      rc29*wk43_B0[OPS_ACC0(2,0,0)] + (rc33)*wk43_B0[OPS_ACC0(1,0,0)]);

}

void opensbliblock00Kernel019(const double *rhou0_B0, double *wk10_B0)
{
    wk10_B0[OPS_ACC1(0,0,0)] = inv_0*((rc32)*rhou0_B0[OPS_ACC0(5,0,0)] - rc29*rhou0_B0[OPS_ACC0(2,0,0)] -
      rc31*rhou0_B0[OPS_ACC0(4,0,0)] - rc33*rhou0_B0[OPS_ACC0(-1,0,0)] + (rc29)*rhou0_B0[OPS_ACC0(-2,0,0)] +
      (rc33)*rhou0_B0[OPS_ACC0(1,0,0)] - rc32*rhou0_B0[OPS_ACC0(-5,0,0)] - rc30*rhou0_B0[OPS_ACC0(-3,0,0)] +
      (rc31)*rhou0_B0[OPS_ACC0(-4,0,0)] + (rc30)*rhou0_B0[OPS_ACC0(3,0,0)]);

}

void opensbliblock00Kernel020(const double *rhoE_B0, double *wk11_B0)
{
    wk11_B0[OPS_ACC1(0,0,0)] = inv_0*((rc33)*rhoE_B0[OPS_ACC0(1,0,0)] - rc32*rhoE_B0[OPS_ACC0(-5,0,0)] -
      rc29*rhoE_B0[OPS_ACC0(2,0,0)] + (rc31)*rhoE_B0[OPS_ACC0(-4,0,0)] + (rc29)*rhoE_B0[OPS_ACC0(-2,0,0)] +
      (rc30)*rhoE_B0[OPS_ACC0(3,0,0)] - rc30*rhoE_B0[OPS_ACC0(-3,0,0)] - rc31*rhoE_B0[OPS_ACC0(4,0,0)] -
      rc33*rhoE_B0[OPS_ACC0(-1,0,0)] + (rc32)*rhoE_B0[OPS_ACC0(5,0,0)]);

}

void opensbliblock00Kernel021(const double *wk44_B0, double *wk12_B0)
{
    wk12_B0[OPS_ACC1(0,0,0)] = inv_0*((rc31)*wk44_B0[OPS_ACC0(-4,0,0)] + (rc33)*wk44_B0[OPS_ACC0(1,0,0)] -
      rc32*wk44_B0[OPS_ACC0(-5,0,0)] - rc30*wk44_B0[OPS_ACC0(-3,0,0)] - rc29*wk44_B0[OPS_ACC0(2,0,0)] -
      rc31*wk44_B0[OPS_ACC0(4,0,0)] - rc33*wk44_B0[OPS_ACC0(-1,0,0)] + (rc30)*wk44_B0[OPS_ACC0(3,0,0)] +
      (rc32)*wk44_B0[OPS_ACC0(5,0,0)] + (rc29)*wk44_B0[OPS_ACC0(-2,0,0)]);

}

 void opensbliblock00Kernel022(const double *rhoE_B0, const double *rho_B0, const double *p_B0, const double *rhou1_B0,
const double *rhou0_B0, const double *rhou2_B0, const double *u1_B0, double *wk40_B0, double *wk43_B0, double *wk41_B0,
double *wk39_B0, double *wk42_B0, double *wk44_B0)
{
   wk39_B0[OPS_ACC10(0,0,0)] = p_B0[OPS_ACC2(0,0,0)]*u1_B0[OPS_ACC6(0,0,0)];

   wk40_B0[OPS_ACC7(0,0,0)] = rho_B0[OPS_ACC1(0,0,0)]*u1_B0[OPS_ACC6(0,0,0)];

   wk41_B0[OPS_ACC9(0,0,0)] = rhou0_B0[OPS_ACC4(0,0,0)]*u1_B0[OPS_ACC6(0,0,0)];

   wk42_B0[OPS_ACC11(0,0,0)] = rhoE_B0[OPS_ACC0(0,0,0)]*u1_B0[OPS_ACC6(0,0,0)];

   wk43_B0[OPS_ACC8(0,0,0)] = rhou1_B0[OPS_ACC3(0,0,0)]*u1_B0[OPS_ACC6(0,0,0)];

   wk44_B0[OPS_ACC12(0,0,0)] = rhou2_B0[OPS_ACC5(0,0,0)]*u1_B0[OPS_ACC6(0,0,0)];

}

void opensbliblock00Kernel024(const double *u1_B0, double *wk13_B0)
{
    wk13_B0[OPS_ACC1(0,0,0)] = inv_1*((rc29)*u1_B0[OPS_ACC0(0,-2,0)] + (rc30)*u1_B0[OPS_ACC0(0,3,0)] -
      rc32*u1_B0[OPS_ACC0(0,-5,0)] + (rc33)*u1_B0[OPS_ACC0(0,1,0)] - rc33*u1_B0[OPS_ACC0(0,-1,0)] -
      rc31*u1_B0[OPS_ACC0(0,4,0)] + (rc32)*u1_B0[OPS_ACC0(0,5,0)] + (rc31)*u1_B0[OPS_ACC0(0,-4,0)] -
      rc29*u1_B0[OPS_ACC0(0,2,0)] - rc30*u1_B0[OPS_ACC0(0,-3,0)]);

}

void opensbliblock00Kernel025(const double *rhoE_B0, double *wk14_B0)
{
    wk14_B0[OPS_ACC1(0,0,0)] = inv_1*((rc33)*rhoE_B0[OPS_ACC0(0,1,0)] - rc32*rhoE_B0[OPS_ACC0(0,-5,0)] -
      rc29*rhoE_B0[OPS_ACC0(0,2,0)] + (rc31)*rhoE_B0[OPS_ACC0(0,-4,0)] + (rc29)*rhoE_B0[OPS_ACC0(0,-2,0)] +
      (rc30)*rhoE_B0[OPS_ACC0(0,3,0)] - rc30*rhoE_B0[OPS_ACC0(0,-3,0)] - rc31*rhoE_B0[OPS_ACC0(0,4,0)] -
      rc33*rhoE_B0[OPS_ACC0(0,-1,0)] + (rc32)*rhoE_B0[OPS_ACC0(0,5,0)]);

}

void opensbliblock00Kernel026(const double *wk39_B0, double *wk15_B0)
{
    wk15_B0[OPS_ACC1(0,0,0)] = inv_1*(-rc29*wk39_B0[OPS_ACC0(0,2,0)] + (rc30)*wk39_B0[OPS_ACC0(0,3,0)] -
      rc31*wk39_B0[OPS_ACC0(0,4,0)] - rc32*wk39_B0[OPS_ACC0(0,-5,0)] + (rc32)*wk39_B0[OPS_ACC0(0,5,0)] +
      (rc31)*wk39_B0[OPS_ACC0(0,-4,0)] + (rc29)*wk39_B0[OPS_ACC0(0,-2,0)] - rc30*wk39_B0[OPS_ACC0(0,-3,0)] +
      (rc33)*wk39_B0[OPS_ACC0(0,1,0)] - rc33*wk39_B0[OPS_ACC0(0,-1,0)]);

}

void opensbliblock00Kernel027(const double *rhou2_B0, double *wk16_B0)
{
    wk16_B0[OPS_ACC1(0,0,0)] = inv_1*((rc30)*rhou2_B0[OPS_ACC0(0,3,0)] - rc29*rhou2_B0[OPS_ACC0(0,2,0)] -
      rc33*rhou2_B0[OPS_ACC0(0,-1,0)] + (rc33)*rhou2_B0[OPS_ACC0(0,1,0)] + (rc29)*rhou2_B0[OPS_ACC0(0,-2,0)] -
      rc30*rhou2_B0[OPS_ACC0(0,-3,0)] + (rc31)*rhou2_B0[OPS_ACC0(0,-4,0)] + (rc32)*rhou2_B0[OPS_ACC0(0,5,0)] -
      rc32*rhou2_B0[OPS_ACC0(0,-5,0)] - rc31*rhou2_B0[OPS_ACC0(0,4,0)]);

}

void opensbliblock00Kernel028(const double *wk40_B0, double *wk17_B0)
{
    wk17_B0[OPS_ACC1(0,0,0)] = inv_1*(-rc30*wk40_B0[OPS_ACC0(0,-3,0)] - rc31*wk40_B0[OPS_ACC0(0,4,0)] +
      (rc29)*wk40_B0[OPS_ACC0(0,-2,0)] - rc33*wk40_B0[OPS_ACC0(0,-1,0)] + (rc32)*wk40_B0[OPS_ACC0(0,5,0)] +
      (rc33)*wk40_B0[OPS_ACC0(0,1,0)] - rc32*wk40_B0[OPS_ACC0(0,-5,0)] - rc29*wk40_B0[OPS_ACC0(0,2,0)] +
      (rc31)*wk40_B0[OPS_ACC0(0,-4,0)] + (rc30)*wk40_B0[OPS_ACC0(0,3,0)]);

}

void opensbliblock00Kernel029(const double *wk41_B0, double *wk18_B0)
{
    wk18_B0[OPS_ACC1(0,0,0)] = inv_1*((rc30)*wk41_B0[OPS_ACC0(0,3,0)] + (rc32)*wk41_B0[OPS_ACC0(0,5,0)] -
      rc29*wk41_B0[OPS_ACC0(0,2,0)] - rc31*wk41_B0[OPS_ACC0(0,4,0)] - rc32*wk41_B0[OPS_ACC0(0,-5,0)] -
      rc30*wk41_B0[OPS_ACC0(0,-3,0)] + (rc31)*wk41_B0[OPS_ACC0(0,-4,0)] + (rc29)*wk41_B0[OPS_ACC0(0,-2,0)] +
      (rc33)*wk41_B0[OPS_ACC0(0,1,0)] - rc33*wk41_B0[OPS_ACC0(0,-1,0)]);

}

void opensbliblock00Kernel030(const double *wk42_B0, double *wk19_B0)
{
    wk19_B0[OPS_ACC1(0,0,0)] = inv_1*(-rc33*wk42_B0[OPS_ACC0(0,-1,0)] + (rc29)*wk42_B0[OPS_ACC0(0,-2,0)] -
      rc31*wk42_B0[OPS_ACC0(0,4,0)] + (rc32)*wk42_B0[OPS_ACC0(0,5,0)] + (rc31)*wk42_B0[OPS_ACC0(0,-4,0)] -
      rc29*wk42_B0[OPS_ACC0(0,2,0)] - rc30*wk42_B0[OPS_ACC0(0,-3,0)] + (rc30)*wk42_B0[OPS_ACC0(0,3,0)] -
      rc32*wk42_B0[OPS_ACC0(0,-5,0)] + (rc33)*wk42_B0[OPS_ACC0(0,1,0)]);

}

void opensbliblock00Kernel031(const double *p_B0, double *wk20_B0)
{
    wk20_B0[OPS_ACC1(0,0,0)] = inv_1*(-rc29*p_B0[OPS_ACC0(0,2,0)] - rc32*p_B0[OPS_ACC0(0,-5,0)] +
      (rc33)*p_B0[OPS_ACC0(0,1,0)] + (rc32)*p_B0[OPS_ACC0(0,5,0)] - rc33*p_B0[OPS_ACC0(0,-1,0)] -
      rc31*p_B0[OPS_ACC0(0,4,0)] - rc30*p_B0[OPS_ACC0(0,-3,0)] + (rc31)*p_B0[OPS_ACC0(0,-4,0)] +
      (rc30)*p_B0[OPS_ACC0(0,3,0)] + (rc29)*p_B0[OPS_ACC0(0,-2,0)]);

}

void opensbliblock00Kernel032(const double *rhou1_B0, double *wk21_B0)
{
    wk21_B0[OPS_ACC1(0,0,0)] = inv_1*((rc32)*rhou1_B0[OPS_ACC0(0,5,0)] + (rc31)*rhou1_B0[OPS_ACC0(0,-4,0)] -
      rc30*rhou1_B0[OPS_ACC0(0,-3,0)] + (rc33)*rhou1_B0[OPS_ACC0(0,1,0)] - rc33*rhou1_B0[OPS_ACC0(0,-1,0)] -
      rc29*rhou1_B0[OPS_ACC0(0,2,0)] + (rc29)*rhou1_B0[OPS_ACC0(0,-2,0)] + (rc30)*rhou1_B0[OPS_ACC0(0,3,0)] -
      rc31*rhou1_B0[OPS_ACC0(0,4,0)] - rc32*rhou1_B0[OPS_ACC0(0,-5,0)]);

}

void opensbliblock00Kernel033(const double *rhou0_B0, double *wk22_B0)
{
    wk22_B0[OPS_ACC1(0,0,0)] = inv_1*((rc32)*rhou0_B0[OPS_ACC0(0,5,0)] - rc29*rhou0_B0[OPS_ACC0(0,2,0)] -
      rc31*rhou0_B0[OPS_ACC0(0,4,0)] - rc33*rhou0_B0[OPS_ACC0(0,-1,0)] + (rc29)*rhou0_B0[OPS_ACC0(0,-2,0)] +
      (rc33)*rhou0_B0[OPS_ACC0(0,1,0)] - rc32*rhou0_B0[OPS_ACC0(0,-5,0)] - rc30*rhou0_B0[OPS_ACC0(0,-3,0)] +
      (rc31)*rhou0_B0[OPS_ACC0(0,-4,0)] + (rc30)*rhou0_B0[OPS_ACC0(0,3,0)]);

}

void opensbliblock00Kernel034(const double *rho_B0, double *wk23_B0)
{
    wk23_B0[OPS_ACC1(0,0,0)] = inv_1*((rc33)*rho_B0[OPS_ACC0(0,1,0)] - rc29*rho_B0[OPS_ACC0(0,2,0)] -
      rc31*rho_B0[OPS_ACC0(0,4,0)] + (rc30)*rho_B0[OPS_ACC0(0,3,0)] + (rc32)*rho_B0[OPS_ACC0(0,5,0)] +
      (rc31)*rho_B0[OPS_ACC0(0,-4,0)] - rc32*rho_B0[OPS_ACC0(0,-5,0)] - rc30*rho_B0[OPS_ACC0(0,-3,0)] -
      rc33*rho_B0[OPS_ACC0(0,-1,0)] + (rc29)*rho_B0[OPS_ACC0(0,-2,0)]);

}

void opensbliblock00Kernel035(const double *wk43_B0, double *wk24_B0)
{
    wk24_B0[OPS_ACC1(0,0,0)] = inv_1*(-rc33*wk43_B0[OPS_ACC0(0,-1,0)] - rc30*wk43_B0[OPS_ACC0(0,-3,0)] +
      (rc29)*wk43_B0[OPS_ACC0(0,-2,0)] - rc32*wk43_B0[OPS_ACC0(0,-5,0)] + (rc31)*wk43_B0[OPS_ACC0(0,-4,0)] +
      (rc32)*wk43_B0[OPS_ACC0(0,5,0)] + (rc30)*wk43_B0[OPS_ACC0(0,3,0)] - rc31*wk43_B0[OPS_ACC0(0,4,0)] -
      rc29*wk43_B0[OPS_ACC0(0,2,0)] + (rc33)*wk43_B0[OPS_ACC0(0,1,0)]);

}

void opensbliblock00Kernel036(const double *wk44_B0, double *wk25_B0)
{
    wk25_B0[OPS_ACC1(0,0,0)] = inv_1*((rc31)*wk44_B0[OPS_ACC0(0,-4,0)] + (rc33)*wk44_B0[OPS_ACC0(0,1,0)] -
      rc32*wk44_B0[OPS_ACC0(0,-5,0)] - rc30*wk44_B0[OPS_ACC0(0,-3,0)] - rc29*wk44_B0[OPS_ACC0(0,2,0)] -
      rc31*wk44_B0[OPS_ACC0(0,4,0)] - rc33*wk44_B0[OPS_ACC0(0,-1,0)] + (rc30)*wk44_B0[OPS_ACC0(0,3,0)] +
      (rc32)*wk44_B0[OPS_ACC0(0,5,0)] + (rc29)*wk44_B0[OPS_ACC0(0,-2,0)]);

}

 void opensbliblock00Kernel037(const double *u2_B0, const double *rhoE_B0, const double *rho_B0, const double *p_B0,
const double *rhou1_B0, const double *rhou0_B0, const double *rhou2_B0, double *wk40_B0, double *wk43_B0, double
*wk41_B0, double *wk39_B0, double *wk42_B0, double *wk44_B0)
{
   wk39_B0[OPS_ACC10(0,0,0)] = rhou0_B0[OPS_ACC5(0,0,0)]*u2_B0[OPS_ACC0(0,0,0)];

   wk40_B0[OPS_ACC7(0,0,0)] = rhou1_B0[OPS_ACC4(0,0,0)]*u2_B0[OPS_ACC0(0,0,0)];

   wk41_B0[OPS_ACC9(0,0,0)] = rho_B0[OPS_ACC2(0,0,0)]*u2_B0[OPS_ACC0(0,0,0)];

   wk42_B0[OPS_ACC11(0,0,0)] = rhoE_B0[OPS_ACC1(0,0,0)]*u2_B0[OPS_ACC0(0,0,0)];

   wk43_B0[OPS_ACC8(0,0,0)] = p_B0[OPS_ACC3(0,0,0)]*u2_B0[OPS_ACC0(0,0,0)];

   wk44_B0[OPS_ACC12(0,0,0)] = rhou2_B0[OPS_ACC6(0,0,0)]*u2_B0[OPS_ACC0(0,0,0)];

}

void opensbliblock00Kernel038(const double *rhou1_B0, double *wk26_B0)
{
    wk26_B0[OPS_ACC1(0,0,0)] = inv_2*((rc30)*rhou1_B0[OPS_ACC0(0,0,3)] - rc31*rhou1_B0[OPS_ACC0(0,0,4)] -
      rc30*rhou1_B0[OPS_ACC0(0,0,-3)] + (rc32)*rhou1_B0[OPS_ACC0(0,0,5)] - rc33*rhou1_B0[OPS_ACC0(0,0,-1)] +
      (rc33)*rhou1_B0[OPS_ACC0(0,0,1)] + (rc29)*rhou1_B0[OPS_ACC0(0,0,-2)] - rc29*rhou1_B0[OPS_ACC0(0,0,2)] -
      rc32*rhou1_B0[OPS_ACC0(0,0,-5)] + (rc31)*rhou1_B0[OPS_ACC0(0,0,-4)]);

}

void opensbliblock00Kernel039(const double *p_B0, double *wk27_B0)
{
    wk27_B0[OPS_ACC1(0,0,0)] = inv_2*((rc33)*p_B0[OPS_ACC0(0,0,1)] - rc30*p_B0[OPS_ACC0(0,0,-3)] -
      rc31*p_B0[OPS_ACC0(0,0,4)] + (rc29)*p_B0[OPS_ACC0(0,0,-2)] + (rc30)*p_B0[OPS_ACC0(0,0,3)] -
      rc32*p_B0[OPS_ACC0(0,0,-5)] - rc29*p_B0[OPS_ACC0(0,0,2)] + (rc31)*p_B0[OPS_ACC0(0,0,-4)] -
      rc33*p_B0[OPS_ACC0(0,0,-1)] + (rc32)*p_B0[OPS_ACC0(0,0,5)]);

}

void opensbliblock00Kernel040(const double *rho_B0, double *wk28_B0)
{
    wk28_B0[OPS_ACC1(0,0,0)] = inv_2*(-rc31*rho_B0[OPS_ACC0(0,0,4)] + (rc33)*rho_B0[OPS_ACC0(0,0,1)] +
      (rc31)*rho_B0[OPS_ACC0(0,0,-4)] + (rc32)*rho_B0[OPS_ACC0(0,0,5)] - rc29*rho_B0[OPS_ACC0(0,0,2)] -
      rc30*rho_B0[OPS_ACC0(0,0,-3)] + (rc30)*rho_B0[OPS_ACC0(0,0,3)] - rc33*rho_B0[OPS_ACC0(0,0,-1)] +
      (rc29)*rho_B0[OPS_ACC0(0,0,-2)] - rc32*rho_B0[OPS_ACC0(0,0,-5)]);

}

void opensbliblock00Kernel042(const double *wk39_B0, double *wk29_B0)
{
    wk29_B0[OPS_ACC1(0,0,0)] = inv_2*((rc33)*wk39_B0[OPS_ACC0(0,0,1)] - rc29*wk39_B0[OPS_ACC0(0,0,2)] -
      rc32*wk39_B0[OPS_ACC0(0,0,-5)] + (rc31)*wk39_B0[OPS_ACC0(0,0,-4)] + (rc30)*wk39_B0[OPS_ACC0(0,0,3)] -
      rc31*wk39_B0[OPS_ACC0(0,0,4)] - rc30*wk39_B0[OPS_ACC0(0,0,-3)] + (rc29)*wk39_B0[OPS_ACC0(0,0,-2)] +
      (rc32)*wk39_B0[OPS_ACC0(0,0,5)] - rc33*wk39_B0[OPS_ACC0(0,0,-1)]);

}

void opensbliblock00Kernel043(const double *rhoE_B0, double *wk30_B0)
{
    wk30_B0[OPS_ACC1(0,0,0)] = inv_2*(-rc32*rhoE_B0[OPS_ACC0(0,0,-5)] + (rc31)*rhoE_B0[OPS_ACC0(0,0,-4)] +
      (rc32)*rhoE_B0[OPS_ACC0(0,0,5)] + (rc33)*rhoE_B0[OPS_ACC0(0,0,1)] + (rc29)*rhoE_B0[OPS_ACC0(0,0,-2)] -
      rc30*rhoE_B0[OPS_ACC0(0,0,-3)] - rc29*rhoE_B0[OPS_ACC0(0,0,2)] - rc33*rhoE_B0[OPS_ACC0(0,0,-1)] +
      (rc30)*rhoE_B0[OPS_ACC0(0,0,3)] - rc31*rhoE_B0[OPS_ACC0(0,0,4)]);

}

void opensbliblock00Kernel044(const double *rhou2_B0, double *wk31_B0)
{
    wk31_B0[OPS_ACC1(0,0,0)] = inv_2*(-rc29*rhou2_B0[OPS_ACC0(0,0,2)] + (rc32)*rhou2_B0[OPS_ACC0(0,0,5)] +
      (rc31)*rhou2_B0[OPS_ACC0(0,0,-4)] + (rc33)*rhou2_B0[OPS_ACC0(0,0,1)] - rc31*rhou2_B0[OPS_ACC0(0,0,4)] -
      rc32*rhou2_B0[OPS_ACC0(0,0,-5)] - rc33*rhou2_B0[OPS_ACC0(0,0,-1)] + (rc30)*rhou2_B0[OPS_ACC0(0,0,3)] -
      rc30*rhou2_B0[OPS_ACC0(0,0,-3)] + (rc29)*rhou2_B0[OPS_ACC0(0,0,-2)]);

}

void opensbliblock00Kernel045(const double *wk40_B0, double *wk32_B0)
{
    wk32_B0[OPS_ACC1(0,0,0)] = inv_2*(-rc29*wk40_B0[OPS_ACC0(0,0,2)] + (rc29)*wk40_B0[OPS_ACC0(0,0,-2)] -
      rc33*wk40_B0[OPS_ACC0(0,0,-1)] + (rc30)*wk40_B0[OPS_ACC0(0,0,3)] - rc31*wk40_B0[OPS_ACC0(0,0,4)] -
      rc32*wk40_B0[OPS_ACC0(0,0,-5)] + (rc31)*wk40_B0[OPS_ACC0(0,0,-4)] + (rc32)*wk40_B0[OPS_ACC0(0,0,5)] +
      (rc33)*wk40_B0[OPS_ACC0(0,0,1)] - rc30*wk40_B0[OPS_ACC0(0,0,-3)]);

}

void opensbliblock00Kernel046(const double *wk41_B0, double *wk33_B0)
{
    wk33_B0[OPS_ACC1(0,0,0)] = inv_2*(-rc32*wk41_B0[OPS_ACC0(0,0,-5)] - rc33*wk41_B0[OPS_ACC0(0,0,-1)] +
      (rc30)*wk41_B0[OPS_ACC0(0,0,3)] + (rc29)*wk41_B0[OPS_ACC0(0,0,-2)] - rc30*wk41_B0[OPS_ACC0(0,0,-3)] -
      rc29*wk41_B0[OPS_ACC0(0,0,2)] + (rc32)*wk41_B0[OPS_ACC0(0,0,5)] + (rc31)*wk41_B0[OPS_ACC0(0,0,-4)] +
      (rc33)*wk41_B0[OPS_ACC0(0,0,1)] - rc31*wk41_B0[OPS_ACC0(0,0,4)]);

}

void opensbliblock00Kernel047(const double *wk42_B0, double *wk34_B0)
{
    wk34_B0[OPS_ACC1(0,0,0)] = inv_2*(-rc33*wk42_B0[OPS_ACC0(0,0,-1)] + (rc29)*wk42_B0[OPS_ACC0(0,0,-2)] +
      (rc32)*wk42_B0[OPS_ACC0(0,0,5)] - rc29*wk42_B0[OPS_ACC0(0,0,2)] - rc32*wk42_B0[OPS_ACC0(0,0,-5)] +
      (rc30)*wk42_B0[OPS_ACC0(0,0,3)] + (rc31)*wk42_B0[OPS_ACC0(0,0,-4)] - rc31*wk42_B0[OPS_ACC0(0,0,4)] -
      rc30*wk42_B0[OPS_ACC0(0,0,-3)] + (rc33)*wk42_B0[OPS_ACC0(0,0,1)]);

}

void opensbliblock00Kernel048(const double *rhou0_B0, double *wk35_B0)
{
    wk35_B0[OPS_ACC1(0,0,0)] = inv_2*((rc30)*rhou0_B0[OPS_ACC0(0,0,3)] - rc32*rhou0_B0[OPS_ACC0(0,0,-5)] -
      rc29*rhou0_B0[OPS_ACC0(0,0,2)] + (rc32)*rhou0_B0[OPS_ACC0(0,0,5)] - rc33*rhou0_B0[OPS_ACC0(0,0,-1)] +
      (rc33)*rhou0_B0[OPS_ACC0(0,0,1)] - rc30*rhou0_B0[OPS_ACC0(0,0,-3)] - rc31*rhou0_B0[OPS_ACC0(0,0,4)] +
      (rc29)*rhou0_B0[OPS_ACC0(0,0,-2)] + (rc31)*rhou0_B0[OPS_ACC0(0,0,-4)]);

}

void opensbliblock00Kernel049(const double *wk43_B0, double *wk36_B0)
{
    wk36_B0[OPS_ACC1(0,0,0)] = inv_2*(-rc31*wk43_B0[OPS_ACC0(0,0,4)] + (rc30)*wk43_B0[OPS_ACC0(0,0,3)] -
      rc33*wk43_B0[OPS_ACC0(0,0,-1)] - rc29*wk43_B0[OPS_ACC0(0,0,2)] - rc30*wk43_B0[OPS_ACC0(0,0,-3)] +
      (rc33)*wk43_B0[OPS_ACC0(0,0,1)] + (rc29)*wk43_B0[OPS_ACC0(0,0,-2)] + (rc32)*wk43_B0[OPS_ACC0(0,0,5)] +
      (rc31)*wk43_B0[OPS_ACC0(0,0,-4)] - rc32*wk43_B0[OPS_ACC0(0,0,-5)]);

}

void opensbliblock00Kernel050(const double *wk44_B0, double *wk37_B0)
{
    wk37_B0[OPS_ACC1(0,0,0)] = inv_2*((rc31)*wk44_B0[OPS_ACC0(0,0,-4)] + (rc29)*wk44_B0[OPS_ACC0(0,0,-2)] -
      rc31*wk44_B0[OPS_ACC0(0,0,4)] - rc30*wk44_B0[OPS_ACC0(0,0,-3)] + (rc33)*wk44_B0[OPS_ACC0(0,0,1)] +
      (rc32)*wk44_B0[OPS_ACC0(0,0,5)] - rc33*wk44_B0[OPS_ACC0(0,0,-1)] - rc29*wk44_B0[OPS_ACC0(0,0,2)] -
      rc32*wk44_B0[OPS_ACC0(0,0,-5)] + (rc30)*wk44_B0[OPS_ACC0(0,0,3)]);

}

void opensbliblock00Kernel051(const double *u2_B0, double *wk38_B0)
{
    wk38_B0[OPS_ACC1(0,0,0)] = inv_2*((rc32)*u2_B0[OPS_ACC0(0,0,5)] - rc33*u2_B0[OPS_ACC0(0,0,-1)] -
      rc30*u2_B0[OPS_ACC0(0,0,-3)] - rc31*u2_B0[OPS_ACC0(0,0,4)] + (rc30)*u2_B0[OPS_ACC0(0,0,3)] +
      (rc31)*u2_B0[OPS_ACC0(0,0,-4)] + (rc29)*u2_B0[OPS_ACC0(0,0,-2)] - rc32*u2_B0[OPS_ACC0(0,0,-5)] -
      rc29*u2_B0[OPS_ACC0(0,0,2)] + (rc33)*u2_B0[OPS_ACC0(0,0,1)]);

}

 void opensbliblock00Kernel052(const double *wk8_B0, const double *wk37_B0, const double *wk35_B0, const double
*wk19_B0, const double *u2_B0, const double *u0_B0, const double *wk23_B0, const double *wk17_B0, const double *wk16_B0,
const double *wk13_B0, const double *wk36_B0, const double *wk33_B0, const double *rhoE_B0, const double *wk9_B0, const
double *wk34_B0, const double *wk22_B0, const double *wk21_B0, const double *wk1_B0, const double *wk28_B0, const double
*wk29_B0, const double *wk10_B0, const double *wk12_B0, const double *u1_B0, const double *wk14_B0, const double
*wk24_B0, const double *wk38_B0, const double *wk26_B0, const double *wk3_B0, const double *wk0_B0, const double
*wk30_B0, const double *wk5_B0, const double *rhou1_B0, const double *wk25_B0, const double *wk20_B0, const double
*wk18_B0, const double *wk11_B0, const double *wk6_B0, const double *wk4_B0, const double *wk27_B0, const double
*wk31_B0, const double *wk32_B0, const double *wk15_B0, const double *rho_B0, const double *rhou0_B0, const double
*wk7_B0, const double *rhou2_B0, const double *wk2_B0, double *Residual4_B0, double *Residual3_B0, double *Residual0_B0,
double *Residual2_B0, double *Residual1_B0)
{
    Residual0_B0[OPS_ACC49(0,0,0)] = -rc6*(wk13_B0[OPS_ACC9(0,0,0)] + wk38_B0[OPS_ACC25(0,0,0)] +
      wk7_B0[OPS_ACC44(0,0,0)])*rho_B0[OPS_ACC42(0,0,0)] + Residual0_B0[OPS_ACC49(0,0,0)] -
      rc6*u0_B0[OPS_ACC5(0,0,0)]*wk6_B0[OPS_ACC36(0,0,0)] - rc6*u1_B0[OPS_ACC22(0,0,0)]*wk23_B0[OPS_ACC6(0,0,0)] -
      rc6*u2_B0[OPS_ACC4(0,0,0)]*wk28_B0[OPS_ACC18(0,0,0)] - rc6*wk17_B0[OPS_ACC7(0,0,0)] -
      rc6*wk33_B0[OPS_ACC11(0,0,0)] - rc6*wk4_B0[OPS_ACC37(0,0,0)];

    Residual1_B0[OPS_ACC51(0,0,0)] = -rc6*(wk13_B0[OPS_ACC9(0,0,0)] + wk38_B0[OPS_ACC25(0,0,0)] +
      wk7_B0[OPS_ACC44(0,0,0)])*rhou0_B0[OPS_ACC43(0,0,0)] + Residual1_B0[OPS_ACC51(0,0,0)] -
      rc6*u0_B0[OPS_ACC5(0,0,0)]*wk10_B0[OPS_ACC20(0,0,0)] - rc6*u1_B0[OPS_ACC22(0,0,0)]*wk22_B0[OPS_ACC15(0,0,0)] -
      rc6*u2_B0[OPS_ACC4(0,0,0)]*wk35_B0[OPS_ACC2(0,0,0)] - rc6*wk18_B0[OPS_ACC34(0,0,0)] -
      rc6*wk29_B0[OPS_ACC19(0,0,0)] - wk2_B0[OPS_ACC46(0,0,0)] - rc6*wk9_B0[OPS_ACC13(0,0,0)];

    Residual2_B0[OPS_ACC50(0,0,0)] = -rc6*(wk13_B0[OPS_ACC9(0,0,0)] + wk38_B0[OPS_ACC25(0,0,0)] +
      wk7_B0[OPS_ACC44(0,0,0)])*rhou1_B0[OPS_ACC31(0,0,0)] + Residual2_B0[OPS_ACC50(0,0,0)] -
      rc6*u0_B0[OPS_ACC5(0,0,0)]*wk8_B0[OPS_ACC0(0,0,0)] - rc6*u1_B0[OPS_ACC22(0,0,0)]*wk21_B0[OPS_ACC16(0,0,0)] -
      rc6*u2_B0[OPS_ACC4(0,0,0)]*wk26_B0[OPS_ACC26(0,0,0)] - rc6*wk0_B0[OPS_ACC28(0,0,0)] - wk20_B0[OPS_ACC33(0,0,0)] -
      rc6*wk24_B0[OPS_ACC24(0,0,0)] - rc6*wk32_B0[OPS_ACC40(0,0,0)];

    Residual3_B0[OPS_ACC48(0,0,0)] = -rc6*(wk13_B0[OPS_ACC9(0,0,0)] + wk38_B0[OPS_ACC25(0,0,0)] +
      wk7_B0[OPS_ACC44(0,0,0)])*rhou2_B0[OPS_ACC45(0,0,0)] + Residual3_B0[OPS_ACC48(0,0,0)] -
      rc6*u0_B0[OPS_ACC5(0,0,0)]*wk3_B0[OPS_ACC27(0,0,0)] - rc6*u1_B0[OPS_ACC22(0,0,0)]*wk16_B0[OPS_ACC8(0,0,0)] -
      rc6*u2_B0[OPS_ACC4(0,0,0)]*wk31_B0[OPS_ACC39(0,0,0)] - rc6*wk1_B0[OPS_ACC17(0,0,0)] -
      rc6*wk25_B0[OPS_ACC32(0,0,0)] - wk27_B0[OPS_ACC38(0,0,0)] - rc6*wk37_B0[OPS_ACC1(0,0,0)];

    Residual4_B0[OPS_ACC47(0,0,0)] = -rc6*(wk13_B0[OPS_ACC9(0,0,0)] + wk38_B0[OPS_ACC25(0,0,0)] +
      wk7_B0[OPS_ACC44(0,0,0)])*rhoE_B0[OPS_ACC12(0,0,0)] + Residual4_B0[OPS_ACC47(0,0,0)] -
      rc6*u0_B0[OPS_ACC5(0,0,0)]*wk11_B0[OPS_ACC35(0,0,0)] - rc6*u1_B0[OPS_ACC22(0,0,0)]*wk14_B0[OPS_ACC23(0,0,0)] -
      rc6*u2_B0[OPS_ACC4(0,0,0)]*wk30_B0[OPS_ACC29(0,0,0)] - wk12_B0[OPS_ACC21(0,0,0)] - wk15_B0[OPS_ACC41(0,0,0)] -
      rc6*wk19_B0[OPS_ACC3(0,0,0)] - rc6*wk34_B0[OPS_ACC14(0,0,0)] - wk36_B0[OPS_ACC10(0,0,0)] -
      rc6*wk5_B0[OPS_ACC30(0,0,0)];

}

void opensbliblock00Kernel053(const double *u1_B0, double *wk0_B0)
{
    wk0_B0[OPS_ACC1(0,0,0)] = inv_3*((rc34)*u1_B0[OPS_ACC0(-1,0,0)] - rc35*u1_B0[OPS_ACC0(0,0,0)] +
      (rc36)*u1_B0[OPS_ACC0(3,0,0)] + (rc37)*u1_B0[OPS_ACC0(-5,0,0)] + (rc34)*u1_B0[OPS_ACC0(1,0,0)] -
      rc29*u1_B0[OPS_ACC0(-2,0,0)] - rc38*u1_B0[OPS_ACC0(4,0,0)] + (rc37)*u1_B0[OPS_ACC0(5,0,0)] -
      rc38*u1_B0[OPS_ACC0(-4,0,0)] - rc29*u1_B0[OPS_ACC0(2,0,0)] + (rc36)*u1_B0[OPS_ACC0(-3,0,0)]);

}

void opensbliblock00Kernel054(const double *T_B0, double *wk1_B0)
{
    wk1_B0[OPS_ACC1(0,0,0)] = inv_4*(-rc29*T_B0[OPS_ACC0(0,-2,0)] + (rc36)*T_B0[OPS_ACC0(0,-3,0)] +
      (rc34)*T_B0[OPS_ACC0(0,-1,0)] + (rc37)*T_B0[OPS_ACC0(0,-5,0)] - rc38*T_B0[OPS_ACC0(0,-4,0)] +
      (rc37)*T_B0[OPS_ACC0(0,5,0)] + (rc36)*T_B0[OPS_ACC0(0,3,0)] - rc38*T_B0[OPS_ACC0(0,4,0)] -
      rc29*T_B0[OPS_ACC0(0,2,0)] + (rc34)*T_B0[OPS_ACC0(0,1,0)] - rc35*T_B0[OPS_ACC0(0,0,0)]);

}

void opensbliblock00Kernel055(const double *u1_B0, double *wk2_B0)
{
    wk2_B0[OPS_ACC1(0,0,0)] = inv_1*((rc29)*u1_B0[OPS_ACC0(0,-2,0)] + (rc30)*u1_B0[OPS_ACC0(0,3,0)] -
      rc32*u1_B0[OPS_ACC0(0,-5,0)] + (rc33)*u1_B0[OPS_ACC0(0,1,0)] - rc33*u1_B0[OPS_ACC0(0,-1,0)] -
      rc31*u1_B0[OPS_ACC0(0,4,0)] + (rc32)*u1_B0[OPS_ACC0(0,5,0)] + (rc31)*u1_B0[OPS_ACC0(0,-4,0)] -
      rc29*u1_B0[OPS_ACC0(0,2,0)] - rc30*u1_B0[OPS_ACC0(0,-3,0)]);

}

void opensbliblock00Kernel057(const double *u1_B0, double *wk4_B0)
{
    wk4_B0[OPS_ACC1(0,0,0)] = inv_5*((rc34)*u1_B0[OPS_ACC0(0,0,-1)] - rc38*u1_B0[OPS_ACC0(0,0,-4)] -
      rc35*u1_B0[OPS_ACC0(0,0,0)] - rc38*u1_B0[OPS_ACC0(0,0,4)] + (rc36)*u1_B0[OPS_ACC0(0,0,-3)] +
      (rc34)*u1_B0[OPS_ACC0(0,0,1)] - rc29*u1_B0[OPS_ACC0(0,0,-2)] + (rc37)*u1_B0[OPS_ACC0(0,0,5)] -
      rc29*u1_B0[OPS_ACC0(0,0,2)] + (rc37)*u1_B0[OPS_ACC0(0,0,-5)] + (rc36)*u1_B0[OPS_ACC0(0,0,3)]);

}

void opensbliblock00Kernel058(const double *u0_B0, double *wk5_B0)
{
    wk5_B0[OPS_ACC1(0,0,0)] = inv_2*(-rc29*u0_B0[OPS_ACC0(0,0,2)] + (rc32)*u0_B0[OPS_ACC0(0,0,5)] +
      (rc31)*u0_B0[OPS_ACC0(0,0,-4)] + (rc33)*u0_B0[OPS_ACC0(0,0,1)] - rc31*u0_B0[OPS_ACC0(0,0,4)] -
      rc32*u0_B0[OPS_ACC0(0,0,-5)] - rc33*u0_B0[OPS_ACC0(0,0,-1)] + (rc30)*u0_B0[OPS_ACC0(0,0,3)] -
      rc30*u0_B0[OPS_ACC0(0,0,-3)] + (rc29)*u0_B0[OPS_ACC0(0,0,-2)]);

}

void opensbliblock00Kernel059(const double *u2_B0, double *wk6_B0)
{
    wk6_B0[OPS_ACC1(0,0,0)] = inv_0*((rc33)*u2_B0[OPS_ACC0(1,0,0)] - rc32*u2_B0[OPS_ACC0(-5,0,0)] +
      (rc29)*u2_B0[OPS_ACC0(-2,0,0)] + (rc30)*u2_B0[OPS_ACC0(3,0,0)] - rc30*u2_B0[OPS_ACC0(-3,0,0)] -
      rc29*u2_B0[OPS_ACC0(2,0,0)] + (rc31)*u2_B0[OPS_ACC0(-4,0,0)] + (rc32)*u2_B0[OPS_ACC0(5,0,0)] -
      rc31*u2_B0[OPS_ACC0(4,0,0)] - rc33*u2_B0[OPS_ACC0(-1,0,0)]);

}

void opensbliblock00Kernel060(const double *u1_B0, double *wk7_B0)
{
    wk7_B0[OPS_ACC1(0,0,0)] = inv_2*((rc29)*u1_B0[OPS_ACC0(0,0,-2)] + (rc31)*u1_B0[OPS_ACC0(0,0,-4)] -
      rc31*u1_B0[OPS_ACC0(0,0,4)] - rc30*u1_B0[OPS_ACC0(0,0,-3)] + (rc33)*u1_B0[OPS_ACC0(0,0,1)] -
      rc33*u1_B0[OPS_ACC0(0,0,-1)] + (rc32)*u1_B0[OPS_ACC0(0,0,5)] - rc29*u1_B0[OPS_ACC0(0,0,2)] -
      rc32*u1_B0[OPS_ACC0(0,0,-5)] + (rc30)*u1_B0[OPS_ACC0(0,0,3)]);

}

void opensbliblock00Kernel061(const double *u0_B0, double *wk8_B0)
{
    wk8_B0[OPS_ACC1(0,0,0)] = inv_4*((rc36)*u0_B0[OPS_ACC0(0,3,0)] - rc29*u0_B0[OPS_ACC0(0,2,0)] -
      rc29*u0_B0[OPS_ACC0(0,-2,0)] + (rc34)*u0_B0[OPS_ACC0(0,1,0)] + (rc34)*u0_B0[OPS_ACC0(0,-1,0)] +
      (rc36)*u0_B0[OPS_ACC0(0,-3,0)] - rc35*u0_B0[OPS_ACC0(0,0,0)] - rc38*u0_B0[OPS_ACC0(0,-4,0)] +
      (rc37)*u0_B0[OPS_ACC0(0,5,0)] + (rc37)*u0_B0[OPS_ACC0(0,-5,0)] - rc38*u0_B0[OPS_ACC0(0,4,0)]);

}

void opensbliblock00Kernel063(const double *u2_B0, double *wk10_B0)
{
    wk10_B0[OPS_ACC1(0,0,0)] = inv_1*((rc33)*u2_B0[OPS_ACC0(0,1,0)] - rc32*u2_B0[OPS_ACC0(0,-5,0)] +
      (rc29)*u2_B0[OPS_ACC0(0,-2,0)] + (rc30)*u2_B0[OPS_ACC0(0,3,0)] - rc30*u2_B0[OPS_ACC0(0,-3,0)] -
      rc29*u2_B0[OPS_ACC0(0,2,0)] + (rc31)*u2_B0[OPS_ACC0(0,-4,0)] + (rc32)*u2_B0[OPS_ACC0(0,5,0)] -
      rc31*u2_B0[OPS_ACC0(0,4,0)] - rc33*u2_B0[OPS_ACC0(0,-1,0)]);

}

void opensbliblock00Kernel064(const double *u2_B0, double *wk11_B0)
{
    wk11_B0[OPS_ACC1(0,0,0)] = inv_4*((rc34)*u2_B0[OPS_ACC0(0,1,0)] + (rc37)*u2_B0[OPS_ACC0(0,-5,0)] +
      (rc34)*u2_B0[OPS_ACC0(0,-1,0)] - rc35*u2_B0[OPS_ACC0(0,0,0)] + (rc36)*u2_B0[OPS_ACC0(0,3,0)] +
      (rc36)*u2_B0[OPS_ACC0(0,-3,0)] - rc29*u2_B0[OPS_ACC0(0,2,0)] - rc38*u2_B0[OPS_ACC0(0,-4,0)] +
      (rc37)*u2_B0[OPS_ACC0(0,5,0)] - rc38*u2_B0[OPS_ACC0(0,4,0)] - rc29*u2_B0[OPS_ACC0(0,-2,0)]);

}

void opensbliblock00Kernel066(const double *u0_B0, double *wk13_B0)
{
    wk13_B0[OPS_ACC1(0,0,0)] = inv_0*((rc30)*u0_B0[OPS_ACC0(3,0,0)] - rc29*u0_B0[OPS_ACC0(2,0,0)] -
      rc33*u0_B0[OPS_ACC0(-1,0,0)] + (rc33)*u0_B0[OPS_ACC0(1,0,0)] + (rc29)*u0_B0[OPS_ACC0(-2,0,0)] -
      rc30*u0_B0[OPS_ACC0(-3,0,0)] + (rc31)*u0_B0[OPS_ACC0(-4,0,0)] + (rc32)*u0_B0[OPS_ACC0(5,0,0)] -
      rc32*u0_B0[OPS_ACC0(-5,0,0)] - rc31*u0_B0[OPS_ACC0(4,0,0)]);

}

void opensbliblock00Kernel067(const double *u2_B0, double *wk14_B0)
{
    wk14_B0[OPS_ACC1(0,0,0)] = inv_5*((rc37)*u2_B0[OPS_ACC0(0,0,5)] - rc29*u2_B0[OPS_ACC0(0,0,-2)] -
      rc35*u2_B0[OPS_ACC0(0,0,0)] + (rc36)*u2_B0[OPS_ACC0(0,0,-3)] - rc38*u2_B0[OPS_ACC0(0,0,4)] +
      (rc36)*u2_B0[OPS_ACC0(0,0,3)] - rc38*u2_B0[OPS_ACC0(0,0,-4)] + (rc34)*u2_B0[OPS_ACC0(0,0,-1)] +
      (rc37)*u2_B0[OPS_ACC0(0,0,-5)] - rc29*u2_B0[OPS_ACC0(0,0,2)] + (rc34)*u2_B0[OPS_ACC0(0,0,1)]);

}

void opensbliblock00Kernel068(const double *u1_B0, double *wk15_B0)
{
    wk15_B0[OPS_ACC1(0,0,0)] = inv_0*((rc29)*u1_B0[OPS_ACC0(-2,0,0)] + (rc30)*u1_B0[OPS_ACC0(3,0,0)] -
      rc32*u1_B0[OPS_ACC0(-5,0,0)] + (rc33)*u1_B0[OPS_ACC0(1,0,0)] - rc33*u1_B0[OPS_ACC0(-1,0,0)] -
      rc31*u1_B0[OPS_ACC0(4,0,0)] + (rc32)*u1_B0[OPS_ACC0(5,0,0)] + (rc31)*u1_B0[OPS_ACC0(-4,0,0)] -
      rc29*u1_B0[OPS_ACC0(2,0,0)] - rc30*u1_B0[OPS_ACC0(-3,0,0)]);

}

void opensbliblock00Kernel070(const double *u0_B0, double *wk17_B0)
{
    wk17_B0[OPS_ACC1(0,0,0)] = inv_3*((rc36)*u0_B0[OPS_ACC0(3,0,0)] - rc29*u0_B0[OPS_ACC0(2,0,0)] -
      rc29*u0_B0[OPS_ACC0(-2,0,0)] + (rc34)*u0_B0[OPS_ACC0(1,0,0)] + (rc34)*u0_B0[OPS_ACC0(-1,0,0)] +
      (rc36)*u0_B0[OPS_ACC0(-3,0,0)] - rc35*u0_B0[OPS_ACC0(0,0,0)] - rc38*u0_B0[OPS_ACC0(-4,0,0)] +
      (rc37)*u0_B0[OPS_ACC0(5,0,0)] + (rc37)*u0_B0[OPS_ACC0(-5,0,0)] - rc38*u0_B0[OPS_ACC0(4,0,0)]);

}

void opensbliblock00Kernel071(const double *u2_B0, double *wk18_B0)
{
    wk18_B0[OPS_ACC1(0,0,0)] = inv_3*((rc34)*u2_B0[OPS_ACC0(1,0,0)] + (rc37)*u2_B0[OPS_ACC0(-5,0,0)] +
      (rc34)*u2_B0[OPS_ACC0(-1,0,0)] - rc35*u2_B0[OPS_ACC0(0,0,0)] + (rc36)*u2_B0[OPS_ACC0(3,0,0)] +
      (rc36)*u2_B0[OPS_ACC0(-3,0,0)] - rc29*u2_B0[OPS_ACC0(2,0,0)] - rc38*u2_B0[OPS_ACC0(-4,0,0)] +
      (rc37)*u2_B0[OPS_ACC0(5,0,0)] - rc38*u2_B0[OPS_ACC0(4,0,0)] - rc29*u2_B0[OPS_ACC0(-2,0,0)]);

}

void opensbliblock00Kernel072(const double *T_B0, double *wk19_B0)
{
    wk19_B0[OPS_ACC1(0,0,0)] = inv_3*(-rc29*T_B0[OPS_ACC0(-2,0,0)] + (rc36)*T_B0[OPS_ACC0(-3,0,0)] +
      (rc34)*T_B0[OPS_ACC0(-1,0,0)] + (rc37)*T_B0[OPS_ACC0(-5,0,0)] - rc38*T_B0[OPS_ACC0(-4,0,0)] +
      (rc37)*T_B0[OPS_ACC0(5,0,0)] + (rc36)*T_B0[OPS_ACC0(3,0,0)] - rc38*T_B0[OPS_ACC0(4,0,0)] -
      rc29*T_B0[OPS_ACC0(2,0,0)] + (rc34)*T_B0[OPS_ACC0(1,0,0)] - rc35*T_B0[OPS_ACC0(0,0,0)]);

}

void opensbliblock00Kernel073(const double *u1_B0, double *wk20_B0)
{
    wk20_B0[OPS_ACC1(0,0,0)] = inv_4*((rc34)*u1_B0[OPS_ACC0(0,-1,0)] - rc35*u1_B0[OPS_ACC0(0,0,0)] +
      (rc36)*u1_B0[OPS_ACC0(0,3,0)] + (rc37)*u1_B0[OPS_ACC0(0,-5,0)] + (rc34)*u1_B0[OPS_ACC0(0,1,0)] -
      rc29*u1_B0[OPS_ACC0(0,-2,0)] - rc38*u1_B0[OPS_ACC0(0,4,0)] + (rc37)*u1_B0[OPS_ACC0(0,5,0)] -
      rc38*u1_B0[OPS_ACC0(0,-4,0)] - rc29*u1_B0[OPS_ACC0(0,2,0)] + (rc36)*u1_B0[OPS_ACC0(0,-3,0)]);

}

void opensbliblock00Kernel075(const double *u0_B0, double *wk22_B0)
{
    wk22_B0[OPS_ACC1(0,0,0)] = inv_1*((rc30)*u0_B0[OPS_ACC0(0,3,0)] - rc29*u0_B0[OPS_ACC0(0,2,0)] -
      rc33*u0_B0[OPS_ACC0(0,-1,0)] + (rc33)*u0_B0[OPS_ACC0(0,1,0)] + (rc29)*u0_B0[OPS_ACC0(0,-2,0)] -
      rc30*u0_B0[OPS_ACC0(0,-3,0)] + (rc31)*u0_B0[OPS_ACC0(0,-4,0)] + (rc32)*u0_B0[OPS_ACC0(0,5,0)] -
      rc32*u0_B0[OPS_ACC0(0,-5,0)] - rc31*u0_B0[OPS_ACC0(0,4,0)]);

}

void opensbliblock00Kernel065(const double *T_B0, double *wk12_B0)
{
    wk12_B0[OPS_ACC1(0,0,0)] = inv_5*(-rc38*T_B0[OPS_ACC0(0,0,4)] + (rc36)*T_B0[OPS_ACC0(0,0,3)] -
      rc29*T_B0[OPS_ACC0(0,0,-2)] - rc29*T_B0[OPS_ACC0(0,0,2)] + (rc36)*T_B0[OPS_ACC0(0,0,-3)] +
      (rc34)*T_B0[OPS_ACC0(0,0,1)] + (rc34)*T_B0[OPS_ACC0(0,0,-1)] + (rc37)*T_B0[OPS_ACC0(0,0,5)] -
      rc38*T_B0[OPS_ACC0(0,0,-4)] + (rc37)*T_B0[OPS_ACC0(0,0,-5)] - rc35*T_B0[OPS_ACC0(0,0,0)]);

}

void opensbliblock00Kernel078(const double *u0_B0, double *wk25_B0)
{
    wk25_B0[OPS_ACC1(0,0,0)] = inv_5*(-rc29*u0_B0[OPS_ACC0(0,0,2)] + (rc37)*u0_B0[OPS_ACC0(0,0,5)] -
      rc38*u0_B0[OPS_ACC0(0,0,-4)] + (rc34)*u0_B0[OPS_ACC0(0,0,1)] - rc38*u0_B0[OPS_ACC0(0,0,4)] +
      (rc37)*u0_B0[OPS_ACC0(0,0,-5)] - rc35*u0_B0[OPS_ACC0(0,0,0)] - rc29*u0_B0[OPS_ACC0(0,0,-2)] +
      (rc36)*u0_B0[OPS_ACC0(0,0,3)] + (rc36)*u0_B0[OPS_ACC0(0,0,-3)] + (rc34)*u0_B0[OPS_ACC0(0,0,-1)]);

}

void opensbliblock00Kernel079(const double *u2_B0, double *wk26_B0)
{
    wk26_B0[OPS_ACC1(0,0,0)] = inv_2*((rc32)*u2_B0[OPS_ACC0(0,0,5)] - rc33*u2_B0[OPS_ACC0(0,0,-1)] -
      rc30*u2_B0[OPS_ACC0(0,0,-3)] - rc31*u2_B0[OPS_ACC0(0,0,4)] + (rc30)*u2_B0[OPS_ACC0(0,0,3)] +
      (rc31)*u2_B0[OPS_ACC0(0,0,-4)] + (rc29)*u2_B0[OPS_ACC0(0,0,-2)] - rc32*u2_B0[OPS_ACC0(0,0,-5)] -
      rc29*u2_B0[OPS_ACC0(0,0,2)] + (rc33)*u2_B0[OPS_ACC0(0,0,1)]);

}

void opensbliblock00Kernel056(const double *wk15_B0, double *wk3_B0)
{
    wk3_B0[OPS_ACC1(0,0,0)] = inv_1*(-rc30*wk15_B0[OPS_ACC0(0,-3,0)] - rc32*wk15_B0[OPS_ACC0(0,-5,0)] +
      (rc33)*wk15_B0[OPS_ACC0(0,1,0)] - rc33*wk15_B0[OPS_ACC0(0,-1,0)] - rc31*wk15_B0[OPS_ACC0(0,4,0)] -
      rc29*wk15_B0[OPS_ACC0(0,2,0)] + (rc29)*wk15_B0[OPS_ACC0(0,-2,0)] + (rc32)*wk15_B0[OPS_ACC0(0,5,0)] +
      (rc30)*wk15_B0[OPS_ACC0(0,3,0)] + (rc31)*wk15_B0[OPS_ACC0(0,-4,0)]);

}

void opensbliblock00Kernel062(const double *wk13_B0, double *wk9_B0)
{
    wk9_B0[OPS_ACC1(0,0,0)] = inv_1*((rc32)*wk13_B0[OPS_ACC0(0,5,0)] + (rc31)*wk13_B0[OPS_ACC0(0,-4,0)] -
      rc30*wk13_B0[OPS_ACC0(0,-3,0)] + (rc33)*wk13_B0[OPS_ACC0(0,1,0)] - rc33*wk13_B0[OPS_ACC0(0,-1,0)] -
      rc29*wk13_B0[OPS_ACC0(0,2,0)] + (rc29)*wk13_B0[OPS_ACC0(0,-2,0)] + (rc30)*wk13_B0[OPS_ACC0(0,3,0)] -
      rc31*wk13_B0[OPS_ACC0(0,4,0)] - rc32*wk13_B0[OPS_ACC0(0,-5,0)]);

}

void opensbliblock00Kernel069(const double *wk13_B0, double *wk16_B0)
{
    wk16_B0[OPS_ACC1(0,0,0)] = inv_2*((rc30)*wk13_B0[OPS_ACC0(0,0,3)] - rc31*wk13_B0[OPS_ACC0(0,0,4)] -
      rc30*wk13_B0[OPS_ACC0(0,0,-3)] + (rc32)*wk13_B0[OPS_ACC0(0,0,5)] - rc33*wk13_B0[OPS_ACC0(0,0,-1)] +
      (rc33)*wk13_B0[OPS_ACC0(0,0,1)] + (rc29)*wk13_B0[OPS_ACC0(0,0,-2)] - rc29*wk13_B0[OPS_ACC0(0,0,2)] -
      rc32*wk13_B0[OPS_ACC0(0,0,-5)] + (rc31)*wk13_B0[OPS_ACC0(0,0,-4)]);

}

void opensbliblock00Kernel077(const double *wk6_B0, double *wk24_B0)
{
    wk24_B0[OPS_ACC1(0,0,0)] = inv_2*((rc33)*wk6_B0[OPS_ACC0(0,0,1)] - rc30*wk6_B0[OPS_ACC0(0,0,-3)] -
      rc31*wk6_B0[OPS_ACC0(0,0,4)] + (rc30)*wk6_B0[OPS_ACC0(0,0,3)] + (rc31)*wk6_B0[OPS_ACC0(0,0,-4)] +
      (rc29)*wk6_B0[OPS_ACC0(0,0,-2)] - rc32*wk6_B0[OPS_ACC0(0,0,-5)] - rc29*wk6_B0[OPS_ACC0(0,0,2)] +
      (rc32)*wk6_B0[OPS_ACC0(0,0,5)] - rc33*wk6_B0[OPS_ACC0(0,0,-1)]);

}

void opensbliblock00Kernel074(const double *wk10_B0, double *wk21_B0)
{
    wk21_B0[OPS_ACC1(0,0,0)] = inv_2*((rc31)*wk10_B0[OPS_ACC0(0,0,-4)] - rc32*wk10_B0[OPS_ACC0(0,0,-5)] -
      rc29*wk10_B0[OPS_ACC0(0,0,2)] + (rc29)*wk10_B0[OPS_ACC0(0,0,-2)] + (rc33)*wk10_B0[OPS_ACC0(0,0,1)] -
      rc33*wk10_B0[OPS_ACC0(0,0,-1)] + (rc32)*wk10_B0[OPS_ACC0(0,0,5)] - rc30*wk10_B0[OPS_ACC0(0,0,-3)] -
      rc31*wk10_B0[OPS_ACC0(0,0,4)] + (rc30)*wk10_B0[OPS_ACC0(0,0,3)]);

}

void opensbliblock00Kernel076(const double *wk2_B0, double *wk23_B0)
{
    wk23_B0[OPS_ACC1(0,0,0)] = inv_2*((rc31)*wk2_B0[OPS_ACC0(0,0,-4)] - rc32*wk2_B0[OPS_ACC0(0,0,-5)] -
      rc29*wk2_B0[OPS_ACC0(0,0,2)] + (rc33)*wk2_B0[OPS_ACC0(0,0,1)] + (rc32)*wk2_B0[OPS_ACC0(0,0,5)] -
      rc33*wk2_B0[OPS_ACC0(0,0,-1)] - rc30*wk2_B0[OPS_ACC0(0,0,-3)] - rc31*wk2_B0[OPS_ACC0(0,0,4)] +
      (rc29)*wk2_B0[OPS_ACC0(0,0,-2)] + (rc30)*wk2_B0[OPS_ACC0(0,0,3)]);

}

 void opensbliblock00Kernel081(const double *wk8_B0, const double *wk5_B0, const double *u2_B0, const double *wk23_B0,
const double *wk17_B0, const double *wk16_B0, const double *wk13_B0, const double *u0_B0, const double *wk9_B0, const
double *wk22_B0, const double *wk21_B0, const double *wk1_B0, const double *wk10_B0, const double *wk12_B0, const double
*u1_B0, const double *wk14_B0, const double *wk24_B0, const double *wk26_B0, const double *wk3_B0, const double *wk0_B0,
const double *wk19_B0, const double *wk25_B0, const double *wk20_B0, const double *wk18_B0, const double *wk11_B0, const
double *wk6_B0, const double *wk4_B0, const double *wk15_B0, const double *wk7_B0, const double *wk2_B0, double
*Residual4_B0, double *Residual3_B0, double *Residual2_B0, double *Residual1_B0)
{
    Residual1_B0[OPS_ACC33(0,0,0)] = 1.0*rcinv11*((rc9)*wk17_B0[OPS_ACC4(0,0,0)] + (rc12)*wk24_B0[OPS_ACC16(0,0,0)] +
      wk25_B0[OPS_ACC21(0,0,0)] + (rc12)*wk3_B0[OPS_ACC18(0,0,0)] + wk8_B0[OPS_ACC0(0,0,0)]) +
      Residual1_B0[OPS_ACC33(0,0,0)];

    Residual2_B0[OPS_ACC32(0,0,0)] = 1.0*rcinv11*(wk0_B0[OPS_ACC19(0,0,0)] + (rc9)*wk20_B0[OPS_ACC22(0,0,0)] +
      (rc12)*wk21_B0[OPS_ACC10(0,0,0)] + wk4_B0[OPS_ACC26(0,0,0)] + (rc12)*wk9_B0[OPS_ACC8(0,0,0)]) +
      Residual2_B0[OPS_ACC32(0,0,0)];

    Residual3_B0[OPS_ACC31(0,0,0)] = 1.0*rcinv11*(wk11_B0[OPS_ACC24(0,0,0)] + (rc9)*wk14_B0[OPS_ACC15(0,0,0)] +
      (rc12)*wk16_B0[OPS_ACC5(0,0,0)] + wk18_B0[OPS_ACC23(0,0,0)] + (rc12)*wk23_B0[OPS_ACC3(0,0,0)]) +
      Residual3_B0[OPS_ACC31(0,0,0)];

    Residual4_B0[OPS_ACC30(0,0,0)] = 1.0*rcinv11*rcinv13*rcinv14*(wk12_B0[OPS_ACC13(0,0,0)] + wk19_B0[OPS_ACC20(0,0,0)]
      + wk1_B0[OPS_ACC11(0,0,0)])/(gama - 1) + 1.0*rcinv11*(wk10_B0[OPS_ACC12(0,0,0)] +
      wk7_B0[OPS_ACC28(0,0,0)])*wk10_B0[OPS_ACC12(0,0,0)] + 1.0*rcinv11*(wk10_B0[OPS_ACC12(0,0,0)] +
      wk7_B0[OPS_ACC28(0,0,0)])*wk7_B0[OPS_ACC28(0,0,0)] + 1.0*rcinv11*(wk15_B0[OPS_ACC27(0,0,0)] +
      wk22_B0[OPS_ACC9(0,0,0)])*wk15_B0[OPS_ACC27(0,0,0)] + 1.0*rcinv11*(wk15_B0[OPS_ACC27(0,0,0)] +
      wk22_B0[OPS_ACC9(0,0,0)])*wk22_B0[OPS_ACC9(0,0,0)] + 1.0*rcinv11*(wk5_B0[OPS_ACC1(0,0,0)] +
      wk6_B0[OPS_ACC25(0,0,0)])*wk5_B0[OPS_ACC1(0,0,0)] + 1.0*rcinv11*(wk5_B0[OPS_ACC1(0,0,0)] +
      wk6_B0[OPS_ACC25(0,0,0)])*wk6_B0[OPS_ACC25(0,0,0)] + 1.0*rcinv11*(-rc8*wk13_B0[OPS_ACC6(0,0,0)] -
      rc8*wk26_B0[OPS_ACC17(0,0,0)] + (rc9)*wk2_B0[OPS_ACC29(0,0,0)])*wk2_B0[OPS_ACC29(0,0,0)] +
      1.0*rcinv11*(-rc8*wk13_B0[OPS_ACC6(0,0,0)] + (rc9)*wk26_B0[OPS_ACC17(0,0,0)] -
      rc8*wk2_B0[OPS_ACC29(0,0,0)])*wk26_B0[OPS_ACC17(0,0,0)] + 1.0*rcinv11*((rc9)*wk13_B0[OPS_ACC6(0,0,0)] -
      rc8*wk26_B0[OPS_ACC17(0,0,0)] - rc8*wk2_B0[OPS_ACC29(0,0,0)])*wk13_B0[OPS_ACC6(0,0,0)] +
      1.0*rcinv11*(wk0_B0[OPS_ACC19(0,0,0)] + (rc9)*wk20_B0[OPS_ACC22(0,0,0)] + (rc12)*wk21_B0[OPS_ACC10(0,0,0)] +
      wk4_B0[OPS_ACC26(0,0,0)] + (rc12)*wk9_B0[OPS_ACC8(0,0,0)])*u1_B0[OPS_ACC14(0,0,0)] +
      1.0*rcinv11*(wk11_B0[OPS_ACC24(0,0,0)] + (rc9)*wk14_B0[OPS_ACC15(0,0,0)] + (rc12)*wk16_B0[OPS_ACC5(0,0,0)] +
      wk18_B0[OPS_ACC23(0,0,0)] + (rc12)*wk23_B0[OPS_ACC3(0,0,0)])*u2_B0[OPS_ACC2(0,0,0)] +
      1.0*rcinv11*((rc9)*wk17_B0[OPS_ACC4(0,0,0)] + (rc12)*wk24_B0[OPS_ACC16(0,0,0)] + wk25_B0[OPS_ACC21(0,0,0)] +
      (rc12)*wk3_B0[OPS_ACC18(0,0,0)] + wk8_B0[OPS_ACC0(0,0,0)])*u0_B0[OPS_ACC7(0,0,0)] +
      Residual4_B0[OPS_ACC30(0,0,0)];

}

 void opensbliblock00Kernel091(const double *Residual3_B0, const double *rhou1_old_B0, const double *Residual0_B0, const
double *Residual1_B0, const double *rho_old_B0, const double *Residual2_B0, const double *Residual4_B0, const double
*rhou0_old_B0, const double *rhoE_old_B0, const double *rhou2_old_B0, double *rhou1_B0, double *rhoE_B0, double
*rhou0_B0, double *rho_B0, double *rhou2_B0, const double *rknew)
{
   rho_B0[OPS_ACC13(0,0,0)] = dt*rknew[0]*Residual0_B0[OPS_ACC2(0,0,0)] + rho_old_B0[OPS_ACC4(0,0,0)];

   rhou0_B0[OPS_ACC12(0,0,0)] = dt*rknew[0]*Residual1_B0[OPS_ACC3(0,0,0)] + rhou0_old_B0[OPS_ACC7(0,0,0)];

   rhou1_B0[OPS_ACC10(0,0,0)] = dt*rknew[0]*Residual2_B0[OPS_ACC5(0,0,0)] + rhou1_old_B0[OPS_ACC1(0,0,0)];

   rhou2_B0[OPS_ACC14(0,0,0)] = dt*rknew[0]*Residual3_B0[OPS_ACC0(0,0,0)] + rhou2_old_B0[OPS_ACC9(0,0,0)];

   rhoE_B0[OPS_ACC11(0,0,0)] = dt*rknew[0]*Residual4_B0[OPS_ACC6(0,0,0)] + rhoE_old_B0[OPS_ACC8(0,0,0)];

}

 void opensbliblock00Kernel090(const double *Residual4_B0, const double *Residual3_B0, const double *Residual0_B0, const
double *Residual2_B0, const double *Residual1_B0, double *rhou1_old_B0, double *rhou2_old_B0, double *rhou0_old_B0,
double *rho_old_B0, double *rhoE_old_B0, const double *rkold)
{
   rho_old_B0[OPS_ACC8(0,0,0)] = dt*rkold[0]*Residual0_B0[OPS_ACC2(0,0,0)] + rho_old_B0[OPS_ACC8(0,0,0)];

   rhou0_old_B0[OPS_ACC7(0,0,0)] = dt*rkold[0]*Residual1_B0[OPS_ACC4(0,0,0)] + rhou0_old_B0[OPS_ACC7(0,0,0)];

   rhou1_old_B0[OPS_ACC5(0,0,0)] = dt*rkold[0]*Residual2_B0[OPS_ACC3(0,0,0)] + rhou1_old_B0[OPS_ACC5(0,0,0)];

   rhou2_old_B0[OPS_ACC6(0,0,0)] = dt*rkold[0]*Residual3_B0[OPS_ACC1(0,0,0)] + rhou2_old_B0[OPS_ACC6(0,0,0)];

   rhoE_old_B0[OPS_ACC9(0,0,0)] = dt*rkold[0]*Residual4_B0[OPS_ACC0(0,0,0)] + rhoE_old_B0[OPS_ACC9(0,0,0)];

}

#endif
