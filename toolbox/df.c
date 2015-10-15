#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/param.h>
#include <sys/mount.h>

void printsize(long long size)
{
	char unit = 'K';
	long long t;

	size *= 10;
	if(size > 1024 * 1024 * 10){
		size /= 1024;
		unit = 'M';
	}

	if(size > 1024 * 1024 * 10){
		size /= 1024;
		unit = 'G';
	}

	t = (size + 512) / 1024;
	printf("%4lld.%1lld%c",t / 10, t % 10, unit);
}

void df(char *s, int always)
{
	struct statfs st;

	if(statfs(s,&st) < 0){
		fprintf(stderr, "%s: %s\n",s, strerror(errno));
		return ;
	}else{
		if(st.f_blocks == 0 && !always)
			return ;
		printf("%-20s  ", s);
		printsize((long long)st.f_blocks * (long long)st.f_bsize);
		printf("  ");
		printsize((long long)(st.f_blocks - st.f_bfree) * (long long)st.f_bsize);
		printf("  ");
		printsize((long long)st.f_bfree * (long long)st.f_bsize);
		printf("  %d\n",(int)st.f_bsize);
	}
}

int df_main(int argc, char **argv)
{
	printf("Filesystem               Size     Used     Free   Blksize\n");
	if(argc == 1){
	}else{
		int i;

		for(i = 1; i < argc; ++i)
			df(argv[i],1);
	}

	return 0;
}
