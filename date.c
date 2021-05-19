#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	if(argv[1] == NULL) {
		time_t t = time(NULL);
		struct tm *tm = localtime(&t);
		printf("%s", asctime(tm));
	}
	else if(strcmp(argv[1], "--help") == 0) {
		printf("NAME\n     date -- display or set date and time\n\nSYNOPSIS\n     date [-jRu] [-r seconds | filename] [-v [+|-]val[ymwdHMS]] ...\n          [+output_fmt]\n     date [-jnu] [[[mm]dd]HH]MM[[cc]yy][.ss]\n     date [-jnRu] -f input_fmt new_date [+output_fmt]\n     date [-d dst] [-t minutes_west]");
	} else if((strcmp(argv[1], "-u") == 0) && argv[2] == NULL) {
		time_t utc;
		struct tm *tm;
		time(&utc);
		tm = gmtime(&utc);
	    printf("%s", asctime(tm));
	} else {
		printf("Flag not handled.\n");
	}
	return 0;
}