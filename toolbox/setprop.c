#ifdef ANDROID
#include <stdio.h>
#incluce <cutils/properties.h>

int setprop_main(int argc, char **argv)
{
	if(argc != 3) {
		fprintf(stderr, "usage: setprop <key> <value>\n");
		return -1;
	}

	if(property_set(argv[1],argv[2])){
		fprintf(stderr, "could not set property\n");
		return -1;
	}

	return 0
}
#else
int setprop_main(int argc, char **argv)
{
	return 0;
}
#endif
