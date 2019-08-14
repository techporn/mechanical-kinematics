#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double dt=0.5, M=1,D=1, K=1;

int main(int argc, char** argv)
{
	double func1(double, double, double);
	double func2(double, double, double);
	
	double x1_k, x1_k1, x2_k, x2_k1, tim=0, u_k, u_k12, u_k1;
	double k1_1, k1_2, k2_1, k2_2, k3_1, k3_2, k4_1, k4_2;
	FILE *fp;
	
	if(!(fp = fopen("sample10-1.csv", "w")))
	{
		printf("result file can not be opend.\n");
		exit(0);
	}
	
	x1_k = 0;
	x2_k = 0;
	
	u_k = 1.0;
	u_k12 = 1.0;
	u_k1 = 1.0;
	
	for(tim=0; tim<=10; tim+=dt)
	{
		k1_1= func1(x1_k, x2_k, u_k)*dt;
		k1_2= func2(x1_k, x2_k, u_k)*dt;
		k2_1= func1(x1_k+k1_1/2, x2_k+k1_2/2, u_k12)*dt;
		k2_2= func2(x1_k+k1_1/2, x2_k+k1_2/2, u_k12)*dt;
		k3_1= func1(x1_k+k2_1/2, x2_k+k2_2/2, u_k12)*dt;
		k3_2= func2(x1_k+k2_1/2, x2_k+k2_2/2, u_k12)*dt;
		k4_1 = func1(x1_k+k3_1, x2_k+k3_2, u_k1)*dt;
		k4_2 = func2(x1_k+k3_1, x2_k+k3_2, u_k1)*dt;
		x1_k1 = x1_k + (k1_1+ 2*k2_1+ 2*k3_1+ k4_1)/6;
		x2_k1 = x2_k + (k1_2+ 2*k2_2+ 2*k3_2+ k4_2)/6;
		fprintf(fp, "%f,%f\n", tim, x1_k);
		x1_k = x1_k1;
		x2_k = x2_k1;
	}
	
	return 0;
}

double func1(double x1, double x2, double u)
{	
	return x2;
}

double func2(double x1, double x2, double u)
{	
	return -K/M*x1 - D/M*x2 + 1/M*u;
}

