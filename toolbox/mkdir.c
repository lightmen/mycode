#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <sys/stat.h>

static void usage()
{
	fprintf(stderr, "mkdir [OPTION] <target>\n");
	fprintf(stderr, "    --help          display usage and exit\n");
	fprintf(stderr, "    -p, --parants   create parant directories as neeeded\n");
}

int mkdir_main(int argc, char **argv)
{
	int ret;

	if(argc < 2 || strcmp(argv[1], "--help") == 0){
		usage();
		return -1;
	}

	int recursive = (strcmp(argv[1], "-p") == 0 ||
				strcmp(argv[1], "--parents") == 0);

	if(recursive){
		argc--;
		argv++;
	}

	char currpath[PATH_MAX],*pathpieces;
	struct stat st;

	while(argc > 1){
		argc--;
		argv++;

		if(recursive){

		}else{
			ret = mkdir(*argv,0777);
			if(ret < 0){
				fprintf(stderr, "mkdir error: %s\n",strerror(errno));
				return ret;
			}
		}
	}

	return 0;
}
