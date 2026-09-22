#include <stdio.h>
#include <unistd.h> // access
#include <sys/stat.h>
#include <string.h>

int file_checker(char *file) {
	struct stat st;
	return stat(file, &st) == 0 && S_ISREG(st.st_mode);
}

int main(int argc, char **argv) {
	int i = 0;
	if (argc == 1) {
		write(1, "ok\n", 3);
		printf("%d", file_checker(argv[1]));
	} else {
		write(1, "please enter one arguments to use the command\n", 42);
	}
	return 0;
}
