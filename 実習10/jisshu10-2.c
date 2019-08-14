#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define L 10e-3
#define R 1e3
#define e 1

int main(int argc, char** argv)
{
	double func(double);
	
	double dt=10e-7, x_k=0, x_k1, tim=0;
	double k1, k2, k3, k4;
	FILE *fp;
	
	if(!(fp = fopen("jisshu10-2.csv", "w")))
	{
		printf("result file can not be opend.\n");
		exit(0);
	}

	for(tim=0; tim<=10e-5; tim+=dt)
	{
		k1 = func(x_k)*dt;
		k2 = func(x_k + k1/2)*dt;
		k3 = func(x_k + k2/2)*dt;
		k4 = func(x_k + k3)*dt;
		x_k1 = x_k + (k1 + 2*k2 + 2*k3 + k4)/6;
		fprintf(fp, "%e,%e\n", tim, x_k);
		x_k = x_k1;
	}
	
	return 0;
}

double func(double x)
{
	return (e - R*x) / L;
}
