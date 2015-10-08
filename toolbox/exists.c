#include <sys/stat.h>
#include <stdio.h>

int exists_main(int argc, char **argv)
{
	struct stat st;
	if(argc < 2)
		return 1;

	if(stat(argv[1],&st) < 0){
		return 1;
	}else{
		return 0;
	}
}
