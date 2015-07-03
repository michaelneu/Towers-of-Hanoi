#include <stdio.h>
#include <stdlib.h>

#include "hanoi.h"

struct _HANOI {
	int height;
	STACK a, b, c;
};

// Solve the towers of hanoi with height `height`
// 
// Parameters:
//     height - The height of the first tower
void hanoi(int height) {
	HANOI hanoi = new_hanoi(height);

	hanoi_solve(hanoi->a, hanoi->b, hanoi->c, height, hanoi);

	// lastly output the solved towers
	print_towers(hanoi);
}

// Create a new representation struct of the towers of hanoi
// 
// Parameters:
//     height - The height of the first tower
HANOI new_hanoi(int height) {
	HANOI hanoi = (HANOI)malloc(sizeof(HANOI));

	if (hanoi == NULL) {
		printf("[ERROR][HANOI][new_hanoi] Could not allocate memory. Exiting.");

		exit(1);
	} else {
		hanoi->height = height;

		hanoi->a = new_stack();
		hanoi->b = new_stack();
		hanoi->c = new_stack();

		while (height > 0) {
			stack_push(hanoi->a, height);
			height--;
		}

		return hanoi;
	}
}


// Solve the towers of hanoi using recursion
// 
// Parameters:
//     a     - The first tower of hanoi
//     b     - The second tower of hanoi
//     c     - The third tower of hanoi
//     n     - The current recursion depth
//     hanoi - The actual hanoi towers, not switched by recursion
void hanoi_solve(STACK a, STACK b, STACK c, int n, HANOI hanoi) {
	int disc;

	if (n == 1) {
		// first output the towers using the real towers, not
		// the ones switched by recursion
		print_towers(hanoi);

		// actually move the disc
		disc = stack_pop(a);
		stack_push(c, disc);
	} else {
		n--;

		hanoi_solve(a, c, b, n, hanoi);
		hanoi_solve(a, b, c, 1, hanoi);
		hanoi_solve(b, a, c, n, hanoi);
	}
}


// Center a given char (repeated `repeatings` times) in a given width on stdout
// 
// Parameters:
//     c          - The char to be centered
//     width      - The width `c` should be centered in
//     repeatings - How often `c` should be repeated
void center_char(char c, int width, int repeatings) {
	int spaces_left, spaces_right;

	if (repeatings < 1) {
		repeatings = 1;
	}
	if (width < repeatings) {
		width = 1;
	}

	spaces_left = (width - repeatings) / 2;
	repeat_char(' ', spaces_left);

	repeat_char(c, repeatings);

	spaces_right = width - repeatings - spaces_left;
	repeat_char(' ', spaces_right);
}

// Repeat a given char `repeatings` times on the stdout
// 
// Parameters:
//     c          - The char
//     repeatings - How often `c` should be repeated
void repeat_char(char c, int repeatings) {
	if (repeatings < 1) {
		repeatings = 1;
	}

	while (repeatings--) {
		printf("%c", c);
	}
}


// Output the towers of hanoi
// 
// Parameters
//     hanoi - The HANOI representation of the towers
void print_towers(HANOI hanoi) {
	int base_width = hanoi->height * 2 + 1,
	    offsets    = 3,
	    i, k, temp;

	// store stacks/stack lengths in arrays to prevent code duplication
	// in the next loop
	STACK stacks[] = { hanoi->a, hanoi->b, hanoi->c };
	unsigned int lengths[3];
	
	for (i = 0; i < 3; i++) {
		lengths[i] = stack_length(stacks[i]);
	}

	// output the 3 towers line by line, starting on top. the loop inside
	// prevents having 3 if-else-statements by iterating over the stack/
	// /stack lengths array
	for (i = hanoi->height; i > 0; i--) {
		printf("  ");
		for (k = 0; k < 3; k++) {
			if (lengths[k] >= i) {
				temp = stack_get(stacks[k], (lengths[k] - i));

				// print a centered disc
				center_char('=', base_width, temp * 2 - 1);
				// separate the disc from the next tower
				repeat_char(' ', offsets);
			} else {
				repeat_char(' ', base_width + offsets);
			}
		}

		printf("\n");
	}

	// output the bottom description
	repeat_char('-', (base_width + offsets) * 3 + 1);
	printf("\n|");

	for (i = 0; i < 3; i++) {
		center_char('A' + i, base_width + offsets - 1, 0);
		printf("|");
	}

	printf("\n");
	repeat_char('-', (base_width + offsets) * 3 + 1);
	printf("\n\n");
}