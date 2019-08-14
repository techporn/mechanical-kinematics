#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char** argv)
{
	#define L 1e-3
	#define R 1e3
	double dt = 1e-7, tim=0;
	double x_k=0, x_k1, u_k=0;
	float p;
	FILE *fp;
	
	if(!(fp = fopen("jisshu4-4.csv", "w")))
	{
		printf("result file can not be opend.\n");
		exit(0);
	}

	for(tim=0; tim<=1e-5; tim+=dt)
	{
		if(tim >=1e-6) u_k =1;

		x_k1 = x_k + (R/L)*(u_k - x_k)*dt;
		fprintf(fp, "%e,%f,%f\n", tim, u_k, x_k);
		x_k = x_k1;
	}
    
    fclose(fp);
	return 0;
}