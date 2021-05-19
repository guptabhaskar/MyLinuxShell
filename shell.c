#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

void shell();
void cdFunc(char *tokens[]);
void echoFunc(char *tokens[]);
void historyFunc(char *tokens[]);
void pwdFunc(char *tokens[]);
void exitFunc(char *tokens[]);

int main(int argc, char const *argv[]) {
	shell();
	return 0;
}

void shell() {
	printf("Welcome to Bhaskar's Shell >> \n");
	while(1) {
		char input[100]; 	// Complete input
		char *tokens[10];   // For splitting input using " "  delimiter  

		char cwd[1024];
		getcwd(cwd, sizeof(cwd));
		printf("%s %% ", cwd);

		scanf("%[^\n]%*c", input);

		FILE *file;
		file = fopen("/Users/bhaskargupta/Desktop/OS1/Q2/MyShell/history.txt", "a");
		fprintf(file, "%s\n", strdup(input));
		fclose(file);

		int counter = 0;
		tokens[counter] = strtok(input, " ");
		while(tokens[counter] != NULL)
		{
			++counter;
			tokens[counter] = strtok(NULL, " ");
		}

		if(strcmp(tokens[0], "cd") == 0) {
			cdFunc(tokens);
		}
		else if(strcmp(tokens[0], "echo") == 0){
			echoFunc(tokens);
		}
		else if(strcmp(tokens[0], "history") == 0){
			historyFunc(tokens);
		}
		else if(strcmp(tokens[0], "pwd") == 0){
			pwdFunc(tokens);
		}
		else if(strcmp(tokens[0], "exit") == 0) {
			exitFunc(tokens);
		}
		else {
			pid_t cpid;
			cpid = fork();
			if(cpid == 0) {
				// Child Process
				if(strcmp(tokens[0], "ls") == 0 && tokens[1] != NULL) {
					execl("/Users/bhaskargupta/Desktop/OS1/Q2/MyShell/ls", "ls", tokens[1], NULL);
				}
				else if(strcmp(tokens[0], "ls") == 0) {
					execl("/Users/bhaskargupta/Desktop/OS1/Q2/MyShell/ls", "ls", NULL);	
				}
				else if(strcmp(tokens[0], "rm") == 0 && tokens[1] != NULL) {
					execv("/Users/bhaskargupta/Desktop/OS1/Q2/MyShell/rm", tokens);
				}
				else if(strcmp(tokens[0], "rm") == 0 && tokens[1] == NULL) {
					printf("%s\n", "Argument Missing!");
				}
				else if(strcmp(tokens[0], "mkdir") == 0 && tokens[1] == NULL) {
					printf("%s\n", "Argument Missing!");
				}
				else if(strcmp(tokens[0], "mkdir") == 0 && tokens[1] != NULL) {
					execv("/Users/bhaskargupta/Desktop/OS1/Q2/MyShell/mkdir", tokens);
				}
				else if(strcmp(tokens[0], "cat") == 0) {
					execv("/Users/bhaskargupta/Desktop/OS1/Q2/MyShell/cat", tokens);
				}
				// else if(strcmp(tokens[0], "date") == 0 && tokens[1] != NULL && tokens[2] != NULL) {
				// 	execl("/Users/bhaskargupta/Desktop/OS1/Q2/MyShell/date", "date", tokens[1], tokens[2], NULL);
				// }
				// else if(strcmp(tokens[0], "date") == 0 && tokens[1] != NULL) {
				// 	execl("/Users/bhaskargupta/Desktop/OS1/Q2/MyShell/date", "date", tokens[1], NULL);	
				// }
				// else if(strcmp(tokens[0], "date") == 0) {
				// 	execl("/Users/bhaskargupta/Desktop/OS1/Q2/MyShell/date", "date", NULL);
				// }
				else {
					printf("Command not found: %s \n", tokens[0]);
				}
				exit(0);
			} 
			else  if(cpid > 0) {
				// Parent Process
				waitpid(0, NULL, 0);
			}
			else {
				printf("Error during fork. \n");
			} 
		}
	}
}

void cdFunc(char *tokens[]) {
	if(tokens[1] == NULL || (strcmp(tokens[1], "~") == 0)) {
		chdir(getenv("HOME")); 
	}
	else if(strcmp(tokens[1], "..") == 0) {
		chdir("../");
	}
	else {
		if(chdir(tokens[1]) == -1) {
			printf("cd: no such file or directory: %s \n", tokens[1]);
		}
	}
}

void echoFunc(char *tokens[]) {
	if(tokens[1] == NULL) {
		printf("\n");
	}
	else if(strcmp(tokens[1], "-n") == 0) {
		int i=2;
		while(tokens[i] != NULL) {
			printf("%s ", tokens[i]);
			i++;
		}
		printf("\n");
	}
	else if(strcmp(tokens[1], "-e") == 0) {
		int i=2;
		while(tokens[i] != NULL) {
			printf("%s ", tokens[i]);
			i++;
		}
		printf("\n");
	}
	else {
		int i=1;
		while(tokens[i] != NULL) {
			printf("%s ", tokens[i]);
			i++;
		}
		printf("\n");
	}
}

void historyFunc(char *tokens[]) {
	if(tokens[1] == NULL) {
		FILE* file = fopen("/Users/bhaskargupta/Desktop/OS1/Q2/MyShell/history.txt", "r");
		if(file != NULL){
			char line[500];
			int lineNo = 0;
			while(fgets(line, sizeof(line), file) != NULL){
				printf("%d 	", lineNo++);
				fputs(line, stdout);
			}
			fclose(file);
		}
	}
	else if(strcmp(tokens[1], "-c") == 0) {
		FILE* file = fopen("/Users/bhaskargupta/Desktop/OS1/Q2/MyShell/history.txt", "w");
	}
	else if(strcmp(tokens[1], "-w") == 0) {
		// Does not give error.
	}
	else {
		printf("Event not found: %s\n", tokens[1]);
	}
}

void pwdFunc(char *tokens[]) {
	if(tokens[1] == NULL) {
		char cwd[1024];
		getcwd(cwd, sizeof(cwd));
		printf("%s\n", cwd);
	}
	else if(strcmp(tokens[1], "--help") == 0) {
		printf("pwd: pwd [-LP]\n    Print the name of the current working directory.\n\n    Options:\n      -L        print the value of $PWD if it names the current working\n                directory\n      -P        print the physical directory, without any symbolic links\n\n    By default, `pwd' behaves as if `-L' were specified.\n\n    Exit Status:\n    Returns 0 unless an invalid option is given or the current directory\n    cannot be read.\n");
	}
	else if(strcmp(tokens[1], "-L") == 0) {
		char cwd[1024];
		getcwd(cwd, sizeof(cwd));
		printf("%s\n", cwd);
	} 
	else {
		printf("pwd: bad option: %s\n", tokens[1]);
	}
}

void exitFunc(char *tokens[]) {
	printf("[Process completed]");
	exit(0);
}