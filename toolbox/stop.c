#ifdef ANDROID
#include <stdio.h>
#include <string.h>

#include <cutils/properties.h>

int stop_main(int argc, char **argv)
{
	if(argc > 1){
		property_set("ctl.stop", argv[1]);
	}else{
		property_set("ctl.stop", "zygote_secondary");
		property_set("ctl.stop", "zygote");
		property_set("ctl.stop", "surfaceflinger");
		property_set("ctl.stop", "netd");
	}

	return 0;
}
#else
int stop_main(int argc, char **argv)
{
	return 0;
}
#endif
