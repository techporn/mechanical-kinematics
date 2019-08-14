#include <stdlib.h> 
#include <stdio.h> 
#include <math.h>

#define PI 3.14159
#define M 3.0
#define m 1.0
#define l 0.5
#define c 0.5
#define C 1.0
#define g 9.8
#define f 0
#define D ((M + m) * m*l*l - m*m*l)

int main(int argc, char** argv) {
    FILE *fp;
    double x1_k, x1_k1,
            x2_k, x2_k1,
            x3_k, x3_k1,
            x4_k, x4_k1,
            tim, dt;

    x1_k = 0.0;
    x2_k = 30.0/180.0*PI;
    x3_k = 0.0;
    x4_k = 0.0;
    dt = 10e-3;

    if(!(fp = fopen("jisshu28-1.csv", "w"))) {
        printf("result file can not be opend.¥n");
        exit(0); 
    }

    for(tim=0; tim<=10; tim+=dt) {
        x1_k1 = x1_k + x3_k * dt;
        x2_k1 = x2_k + x4_k * dt;
        x3_k1 = x3_k + (m*l*l * (m*l*x4_k*x4_k*x2_k - C*x3_k + f) + 
                        m*l*(m*g*l*x2_k + c*l*l*x4_k))/D * dt;
        x4_k1 = x4_k + (-m * (m*l*x4_k*x4_k*x2_k - C*x3_k + f) -
                        (M + m)*(m*g*l*x2_k + c*l*l*x4_k))/D * dt;

        fprintf(fp, "%f,%f,%f\n", tim, x1_k, x2_k); 
        x1_k = x1_k1;
        x2_k = x2_k1;
        x3_k = x3_k1;
        x4_k = x4_k1;
    }

    return 0; 
}