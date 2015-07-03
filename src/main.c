#include <stdio.h>
#include <stdlib.h>

#include "hanoi.h"


int main(int argc, char *argv[]) {
	int height = 5;

	if (argc == 2) {
		height = atoi(argv[1]);
	}

	if (argc != 2 || height < 1) {
		printf("Towers of hanoi. Usage: \n    %s [height]\n", argv[0]);

		exit(0);
	}

	// start hanoi
	hanoi(height);

	return 0;
}