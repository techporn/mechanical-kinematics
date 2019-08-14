#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define C 100e-6
#define R 10e3
double u = 1.0;

int main(int argc, char** argv)
{
	double func(double);
	
	double dt=0.1, x_k=0, x_k1, tim=0;
	double k1, k2;
	FILE *fp;
	
	if(!(fp = fopen("jisshu9-2.csv", "w")))
	{
		printf("result file can not be opend.\n");
		exit(0);
	}

	for(tim=0; tim<=10; tim+=dt)
	{
		k1 = func(x_k)*dt;
		k2 = func(x_k + k1)*dt;
		x_k1 = x_k + (k1 + k2)/2;
		fprintf(fp, "%f,%f\n", tim, x_k);
		x_k = x_k1;
	}
	
	return 0;
}

double func(double x)
{
	return 1/(C*R) * (u - x);
}
