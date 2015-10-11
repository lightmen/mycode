#include <sys/mount.h>
#include <stdio.h>

int umount_main(int argc, char **argv)
{
	int ret;

	if(argc < 2){
		printf("usage: umount <device_path>\n");
		return -1;
	}

	ret = unmount(argv[1],0);
	return ret;
}
