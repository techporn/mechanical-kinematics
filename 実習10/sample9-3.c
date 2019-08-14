#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159

double dt=0.01, m=1, l=0.5, c=0.5;

int main(int argc, char** argv)
{
	double func1(double, double);
	double func2(double, double);
	
	double x1_k, x1_k1, x2_k, x2_k1, tim=0;
	double k1_1, k2_1, k1_2, k2_2;
	FILE *fp;
	
	if(!(fp = fopen("result.txt", "w")))
	{
		printf("result file can not be opend.\n");
		exit(0);
	}
	
	x1_k = 30.0/180.0*PI;
	x2_k = 0;
	
	for(tim=0; tim<=10; tim+=dt)
	{
		k1_1 = func1(x1_k, x2_k)*dt;
		k1_2 = func2(x1_k, x2_k)*dt;
		k2_1 = func1(x1_k+k1_1, x2_k+k1_2)*dt;
		k2_2 = func2(x1_k+k1_1, x2_k+k1_2)*dt;
		x1_k1 = x1_k + (k1_1 + k2_1)/2;
		x2_k1 = x2_k + (k1_2 + k2_2)/2;
		fprintf(fp, "%f %f\n", tim, x1_k);
		x1_k = x1_k1;
		x2_k = x2_k1;
	}
	
	return 0;
}

double func1(double x1, double x2)
{	
	return x2;
}

double func2(double x1, double x2)
{	
	return -9.8/l*sin(x1) - c/m*x2;
}

