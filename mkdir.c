#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	if(strcmp(argv[1], "--help") == 0) {
		printf("Usage: mkdir [OPTION]... DIRECTORY...\nCreate the DIRECTORY(ies), if they do not already exist.\n\nMandatory arguments to long options are mandatory for short options too.\n  -m, --mode=MODE   set file mode (as in chmod), not a=rwx - umask\n  -p, --parents     no error if existing, make parent directories as needed\n  -v, --verbose     print a message for each created directory\n  -Z                   set SELinux security context of each created directory\n                         to the default type\n      --context[=CTX]  like -Z, or if CTX is specified then set the SELinux\n                         or SMACK security context to CTX\n      --help     display this help and exit\n      --version  output version information and exit\n\n");
	} else if(argv[1] != NULL && argv[2] == NULL) {
		char cwd[1024];
		getcwd(cwd, sizeof(cwd));
		strcat(cwd, "/");
		strcat(cwd, argv[1]);
		struct stat type = {0};
		int exist = stat(cwd, &type);
		if(exist == -1){
			int check;
			check = mkdir(cwd, 0700);
			if(check) {
				printf("mkdir: No such file or directory\n");
			} else {
			}
		} else {
			printf("mkdir: %s: Directory exists \n", argv[1]);
		}
	} else if((strcmp(argv[1], "-v")==0) && argv[2] != NULL) {
		char cwd[1024];
		getcwd(cwd, sizeof(cwd));
		strcat(cwd, "/");
		strcat(cwd, argv[2]);
		struct stat type = {0};
		int exist = stat(cwd, &type);
		if(exist == -1){
			int check;
			check = mkdir(cwd, 0700);
			if(check) {
				printf("mkdir: No such file or directory\n");
			} else {
				printf("Directory Created\n");
			}
		} else {
			printf("mkdir: %s: Directory exists \n", argv[2]);
		}
	} else {
		printf("Flag not handled. \n");
	}	
	return 0;
}

