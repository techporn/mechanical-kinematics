#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char** argv)
{
	#define CA 100e-6
	#define RE 10e3
	double dt = 0.1, tim=0;
	double x_k=0, x_k1, u_k=-1;
	float p;
	FILE *fp;
	
	if(!(fp = fopen("jisshu3-2.csv", "w")))
	{
		printf("result file can not be opend.\n");
		exit(0);
	}

	for(tim=0; tim<=10; tim+=dt)
	{
		if(modff(tim, &p) == 0.0)
            u_k *= -1;

		x_k1 = x_k + 1/(CA*RE)*(u_k -x_k)*dt;
		fprintf(fp, "%f,%f,%f\n", tim, u_k, x_k);
		x_k = x_k1;
	}
    
    fclose(fp);
	return 0;
}