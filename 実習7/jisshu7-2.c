#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main(int argc, char** argv)
{
	#define L 10e-3
	#define R 1
	#define Jm 1e-6
	#define Dm 1e-7
	#define Kb 1e-3
	#define Kt 1e-3
	
	double dt=1e-3;
	double x1_k, x1_k1, x2_k, x2_k1, tim=0, e;
	FILE *fp;
	
	if(!(fp = fopen("jisshu7-2.csv", "w")))
	{
		printf("result file can not be opend.\n");
		exit(0);
	}
	
	x1_k = 0;
	x2_k = 0;
	e = 1;
	
	for(tim=0; tim<=10; tim+=dt)
	{

		x1_k1 = x1_k + (1/L * (e - R*x1_k - Kb*x2_k)) * dt;
		x2_k1 = x2_k + (1/Jm * (Kt*x1_k - Dm*x2_k)) * dt;
		fprintf(fp, "%f,%f,%f\n", tim, x1_k, x2_k);
		x1_k = x1_k1;
		x2_k = x2_k1;
	}
	
	return 0;
}