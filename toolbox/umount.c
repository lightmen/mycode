#include <sys/mount.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int umount_main(int argc, char **argv)
{
	if(argc < 2){
		printf("usage: umount <path>\n");
		return -1;
	}

	if(unmount(argv[1],0)){
		fprintf(stderr,"failed: %s\n",strerror(errno));
		return -1;
	}

	return 0;
}
