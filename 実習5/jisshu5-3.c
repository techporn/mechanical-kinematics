#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char** argv)
{
	#define OMEGA_N 1
	#define K 1
	#define ZETA 0.707
    const double MAX = 20 / OMEGA_N;
	const double DEN  = sqrt(1 - ZETA*ZETA);

	double dt = 0.1, tim=0;
	double y, num;
	FILE *fp;

	if(!(fp = fopen("jisshu5-3.csv", "w")))
	{
		printf("result file can not be opend.\n");
		exit(0);
	}

	for(tim=0; tim<=MAX; tim+=dt)
	{
		num = exp(-ZETA*OMEGA_N*tim);
		y = K * (1 \
				 - (num/DEN) * sin(OMEGA_N*DEN*tim \
				 				   + atan(DEN/ZETA))
				);

		fprintf(fp, "%f,%f\n", tim, y);
	}
    
    fclose(fp);
	return 0;
}