#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main(int argc, char** argv)
{
	double dt=0.05, m=1, l=0.5, c=0.5;
	double x1_k, x1_k1, x2_k, x2_k1, tim=0;
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
		x1_k1 = x1_k + x2_k*dt;
		x2_k1 = x2_k + (-9.8/l*sin(x1_k) - c/m*x2_k)*dt;
		fprintf(fp, "%f %f\n", tim, x1_k);
		x1_k = x1_k1;
		x2_k = x2_k1;
	}
	
	return 0;
}