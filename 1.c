#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void quadratic(double a, double b, double c){
	double x1, x2;
	double D = (b*b) - (4 * a * c);
	if(D == 0){
		printf("D == 0 --> one root\n");
		printf("x1 = x2 = -(%.2lf / 2 * %.2lf)\n", b, a);
		x1 = x2 = -(b / (2*a));
		printf("x = %.2lf\n", x1);
        }
        if(D < 0){
		printf("D < 0 --> equation haven't roots or have complex roots\n");
		printf("x1 = ((-%.2lf) + i * sqrt(fabs(%.2lf))) / (2 * %.2lf)\n", b, D, a);
		printf("x2 = ((-%.2lf) - i * sqrt(fabs(%.2lf))) / (2 * %.2lf)\n", b, D, a);
        }
	if(D > 0){
		printf("D > 0 --> equation have two roots\n");
                printf("x1 = ((-%.2lf) + sqrt(%.2lf)) / 2 * %.2lf\n", b, D, a);
                printf("x2 = ((-%.2lf) - sqrt(%.2lf)) / 2 * %.2lf\n", b, D, a);
		x1 = ((-b) + sqrt(D)) / (2 * a);
		x2 = ((-b) - sqrt(D)) / (2 * a);
		printf("D = %.2lf\nx1 = %.2lf\nx2 = %.2lf\n", D, x1, x2);
	} 
}

int main(int argc, char** argv){

if(argc != 4){
	printf("\nplease enter 3 arguments\n");
	return 0;
}

if(atof(argv[1]) == 0){
	printf("it isn't quadratic");
	return 0;
}

double a = atof(argv[1]);
double b = atof(argv[2]);
double c = atof(argv[3]);

quadratic(a, b, c);

return 0;
}