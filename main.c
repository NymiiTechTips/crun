#include <stdio.h>
#include <unistd.h> 
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int file_checker(char *file) {
	struct stat st;
	return stat(file, &st) == 0 && S_ISREG(st.st_mode);
}

int file_extension_checker(const char *file) {
    const char *extension = strrchr(file, '.');

    return extension != NULL &&
           (strcmp(extension, ".c") == 0 ||
            strcmp(extension, ".h") == 0);
}

void compile(const char *file) {
	char command[256];
	snprintf(command, sizeof(command), "gcc %s -o output", file);
	system(command);
}

void run_output(void) {
	system("./output");
}

void clean_output(void) {
	system("rm -f output");
}

void help(void) {
	printf("Usage: command <file>\n");
	printf("Compile, execute and clean the output of a C source file.\n");
}

int main(int argc, char **argv) {
	int i = 0;
	if (argc == 2) {
		if (argv[1] && strcmp(argv[1], "-h") == 0) {
			help();
		} else {
			if (file_checker(argv[1]) == 1 && file_extension_checker(argv[1]) == 1) {
				compile(argv[1]);
				run_output();
				clean_output();
			} else {
				printf("File is not a valid C source or header file or does not exist.\n");
		}
		}
	} else {
		printf("please enter one argument to use the command\n");
	}
	return 0;
}
