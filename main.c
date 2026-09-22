#include <stdio.h>
#include <unistd.h> // access
#include <sys/stat.h>
#include <string.h>

int file_checker(const char *file){
	return access(file, F_OK) == 0;
}

int filecheck(char *file) {
	return 0;
}

int main(int argc, char **argv) {
	int i = 0;
	if (argc > 1) {
		int len = strlen(argv[1]);
		write(1, "ok\n", 3);
		printf("%d", file_checker(argv[len]));

	} else {
		write(1, "please enter arguments to use the command\n", 42);
	}
	return 0;
}
