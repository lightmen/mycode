#ifdef ANDROID
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <cutils/properties.h>

int start_main(int argc, char **argv)
{
	if(argc > 1){
		property_set("ctl.start", argv[1]);
	}else{
		property_set("ctl.start", "netd");
		property_set("ctl.start", "surfaceflinger");
		property_set("ctl.start", "zygote");
		property_set("ctl.start", "zygote_secondary");
	}

	return 0;
}
#else
int start_main(int argc, char **argv)
{
	return 0;
}
#endif
