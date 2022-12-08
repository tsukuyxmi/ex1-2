#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main(int argc, char** argv){

char* f_name = "test.txt";
FILE *f = NULL;
char *opts = "ho:c:";
int opt;
int opt_s = 0;


while((opt = getopt(argc, argv, opts)) != -1){
	switch (opt){
	case 'h':
		printf("test flags -h -o -c\n");
		printf("-h manual user\n");
		printf("-o set output file name\n");
		printf("-c special mode 1(reverse) or default(nothing)\n");
		return 0;
	case 'o':
		f_name = optarg;
		printf("you change file name on %s\n", optarg);
		break;
	case 'c':
		if(atoi(optarg) == 1)
			opt_s = 1;
		printf("You enable special mode\n");
		break;
	case '?':
	default: /* '?' */
		printf("?? getopt returned character code 0 ??\n");
		exit(1);
	}
}
	if((f = fopen(f_name, "w")) == NULL){
        	printf("FILE OPEN ERR!!!!\n");
                return 0;
        }
	if(opt_s == 1)
		for(int i = 100; i > 0; i--){
			fprintf(f,"%d\n", i);
		}
	else
		for(int i = 0; i < 100; i++){
			fprintf(f,"%d\n", i);
		}
	fclose(f);
return 0;
}