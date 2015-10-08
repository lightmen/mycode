#include <stdio.h>
#include <string.h>

int main(int argc, char **argv);

int toolbox_main(int argc, char **argv)
{
	if(argc > 1){
		return main(argc-1,argv+1);
	}else{
		printf("toolbox\n");
		return 0;
	};

}

#define TOOL(name) int name##_main(int, char **);
#include "tools.h"
#undef TOOL

static struct {
	const char *name;
	int (*func)(int argc, char **argv);
} tools[] = {
	{"toolbox", toolbox_main},
#define TOOL(name) {#name, name##_main},
#include "tools.h"
#undef TOOL
	{0, 0},
};

int main(int argc, char **argv)
{
	int i;
	char *name;

	name = strrchr(argv[0],'/');
	if(name)
		name++;
	else
		name = argv[0];

	for(i = 0; tools[i].name; i++){
		if(!strcmp(tools[i].name,name)){
			return tools[i].func(argc, argv);
		}
	}

	if(!tools[i].name){
		printf("tool %s not fountd\n",name);
	}

	return -1;
}
