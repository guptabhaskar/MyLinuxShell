#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	if(strcmp(argv[1], "--help") == 0) {
		printf("Usage: cat [OPTION]... [FILE]...\nConcatenate FILE(s) to standard output.\nWith no FILE, or when FILE is -, read standard input.\n  -A, --show-all           equivalent to -vET\n  -b, --number-nonblank    number nonempty output lines, overrides -n\n  -e                       equivalent to -vE\n  -E, --show-ends          display $ at end of each line\n  -n, --number             number all output lines\n  -s, --squeeze-blank      suppress repeated empty output lines\n  -t                       equivalent to -vT\n  -T, --show-tabs          display TAB characters as ^I\n  -u                       (ignored)\n  -v, --show-nonprinting   use ^ and M- notation, except for LFD and TAB\n      --help     display this help and exit\n      --version  output version information and exit\nExamples:\n  cat f - g  Output f's contents, then standard input, then g's contents.\n  cat        Copy standard input to standard output.\n");
	} else if(argv[1] != NULL && argv[2] == NULL) {
		char cwd[1024];
		getcwd(cwd, sizeof(cwd));
		strcat(cwd, "/");
		strcat(cwd, argv[1]);
		struct stat type = {0};
		int x = stat(cwd, &type);
		if(x != -1) {
			FILE *file;
			char line[1000];
			file = fopen(cwd, "r");
			DIR* check = opendir(cwd);
			if(check) {
				printf("cat: %s: Is a directory\n", argv[1]);
			} else {
				while(fgets(line, sizeof(line), file) != NULL) {
					fputs(line, stdout);
				}
				fclose(file);
			}
		} else {
			printf("No such file exists.\n");
		}
	} else if((strcmp(argv[1], "-n") == 0) && argv[2] != NULL) {
		char cwd[1024];
		getcwd(cwd, sizeof(cwd));
		strcat(cwd, "/");
		strcat(cwd, argv[2]);
		struct stat type = {0};
		int x = stat(cwd, &type);
		if(x != -1) {
			FILE *file;
			char line[1000];
			int c = 1;
			file = fopen(cwd, "r");
			DIR* check = opendir(cwd);
			if(check) {
				printf("cat: %s: Is a directory\n", argv[2]);
			} else {
				while(fgets(line, sizeof(line), file) != NULL) {
					printf("%d\t", c++);
					fputs(line, stdout);
				}
				fclose(file);
			}
		} else {
			printf("No such file exists.\n");
		}
	} else {
		printf("Flag not handled.\n");
	}
	return 0;
}