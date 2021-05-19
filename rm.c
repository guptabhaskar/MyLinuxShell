#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
	if(argv[1] != NULL && argv[2] == NULL) {
		char cwd[1024];
		getcwd(cwd, sizeof(cwd));
		strcat(cwd, "/");
		strcat(cwd, argv[1]);
		if(remove(cwd) == 0) {
		} else {
			printf("rm: %s: No such file exists.\n", argv[1]);
		}
	} else if(strcmp(argv[1], "-f") == 0 && argv[2] != NULL) {
		char cwd[1024];
		getcwd(cwd, sizeof(cwd));
		strcat(cwd, "/");
		strcat(cwd, argv[2]);
		remove(cwd);
	}
	else if(strcmp(argv[1], "-d") == 0 && argv[2] != NULL) {
		char cwd[1024];
		getcwd(cwd, sizeof(cwd));
		strcat(cwd, "/");
		strcat(cwd, argv[2]);
		if(remove(cwd) == 0) {
		} else {
			printf("rm: %s: No such file or directory.\n", argv[2]);
		}
	}
	else {
		printf("Flag not handled.\n");
	}
	return 0;
}