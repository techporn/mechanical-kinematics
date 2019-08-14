#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char** argv)
{
	#define G 9.8
	#define C 0.1
	#define M 1
	
	double dt = 0.1, tim=0;
	double x_k=0, x_k1;
	FILE *fp;
	
	if(!(fp = fopen("jisshu4-2.csv", "w")))
	{
		printf("result file can not be opend.\n");
		exit(0);
	}

	for(tim=0; tim<=100; tim+=dt)
	{
		x_k1 = x_k + (G - C/M*x_k)*dt;
		fprintf(fp, "%f,%f\n", tim, x_k);
		x_k = x_k1;
	}
    
    fclose(fp);
	return 0;
}