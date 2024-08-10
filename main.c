#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void err(char* msg) {
	fprintf(stderr, "Error: %s\n", msg);
}

int main(int argc, char* argv[]) {
	if (argc == 1) {
		err("No arguments");

		return 1;
	}

	if (argc != 1 + 1) {
		err("Wrong number of arguments");

		return 1;
	}

	size_t ln_base = strlen("wrap $(wrap -sq) -sq");
	size_t ln = ln_base + 1 + strlen(argv[1]);

	char str[ln];
	sprintf(str, "wrap $(wrap %s -sq) -sq", argv[1]);

	system(str);

	return 0;
}
