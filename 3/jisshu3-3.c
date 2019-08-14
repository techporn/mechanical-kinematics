#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char** argv)
{
	#define LAMBDA 7.3e-10
	double dt = 1, tim=0;
	double x_k=1, x_k1;
	FILE *fp;
	
	if(!(fp = fopen("jisshu3-3.csv", "w")))
	{
		printf("result file can not be opend.\n");
		exit(0);
	}

	for(tim=0; tim<=100; tim+=dt)
	{

		x_k1 = x_k + (-7.3e-10*x_k)*dt*86400*365;
		fprintf(fp, "%f,%f\n", tim, x_k);
		printf("%f %f\n", tim, x_k1);
		x_k = x_k1;
	}
    
    fclose(fp);
	return 0;
}