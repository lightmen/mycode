#include <stdio.h>
#include <string.h>

int main(int argc, char **argv);

int toolbox_main(int argc, char **argv)
{
	int ret = 0;
	if(argc > 1){
		ret = main(argc-1,argv+1);
	}else{
		printf("toolbox\n");
	};

	return ret;
}

struct {
	const char *name;
	int (*func)(int argc, char **argv);
} tools[] = {
	{"toolbox", toolbox_main},
	{0, 0},
};

int main(int argc, char **argv)
{
	int i;
	int ret;
	char *name;
	if(argc > 1){
		name = argv[1];
		argc--;
		argv++;
	}else{
		name = argv[0];
	}

	name = strrchr(name,'/')+1;

	for(i = 0; tools[i].name; i++){
		if(!strcmp(tools[i].name,name)){	
			ret = tools[i].func(argc, argv); 
			break;
		}
	}

	if(!tools[i].name){
		printf("tool %s not fountd\n",name);
		ret = -1;
	}

	return ret;
}
