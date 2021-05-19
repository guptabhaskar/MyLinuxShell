#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	if(argv[1] == NULL) {
		struct dirent **list;
		int totalFiles;
		totalFiles = scandir(".", &list, 0, alphasort);
		while(totalFiles--) {
			char *name = list[totalFiles]->d_name;
			if(name[0] != '.') {
				printf("%s \t\t", name);
			}
		}
		free(list);
		printf("\n");
	}
	else if(strcmp(argv[1], "-a") == 0) {
		struct dirent **list;
		int totalFiles;
		totalFiles = scandir(".", &list, 0, alphasort);
		while(totalFiles--) {
			char *name = list[totalFiles]->d_name;
			printf("%s \t\t", name);
		}
		free(list);
		printf("\n");
	}
	else if(strcmp(argv[1], "-A") == 0) {
		struct dirent **list;
		int totalFiles;
		totalFiles = scandir(".", &list, 0, alphasort);
		while(totalFiles--) {
			char *name = list[totalFiles]->d_name;
			if(strcmp(name, ".") != 0 && strcmp(name, "..") != 0) {
				printf("%s \t\t", name);
			}
		}
		free(list);
		printf("\n");
	}
	else {
		printf("Flag not handled. \n");
	}
	return(0);
}