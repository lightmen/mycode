#include <sys/stat.h>
#include <stdio.h>

int exists_main(int argc, char **argv)
{
	struct stat st;
	if(argc < 2){
		printf("Usage: exists file\n");
		return 1;
	}

	if(stat(argv[1],&st) < 0){
		printf("%s not exists\n",argv[1]);
		return 1;
	}else{
		return 0;
	}
}
