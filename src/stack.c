#include <stdlib.h>
#include <stdio.h>

#include "stack.h"


// define a stack element which contains it's 
// following node
struct _STACK_ELEMENT {
	struct _STACK_ELEMENT *next;
	STACK_TYPE data;
};

// define a stack struct itself
struct _STACK {
	STACK_ELEMENT element;
};


// Creates a new stack
// 
// Returns:
// 		A pointer to the stack
// 
// Error:
//     Fails if there's no memory to allocate
STACK new_stack() {
	STACK stack = (STACK)malloc(sizeof(STACK));

	if (stack == NULL) {
		printf("[ERROR][STACK][new_stack] Could not allocate memory. Exiting.");

		exit(1);
	} else {
		stack->element = 0;

		return stack;
	}
}

// Pushes an element to the stack
// 
// Error: 
//     Fails if there's no memory to allocate
void stack_push(STACK stack, STACK_TYPE data) {
	if (stack != NULL) {
		STACK_ELEMENT element = (STACK_ELEMENT)malloc(sizeof(STACK_ELEMENT));

		if (element == NULL) {
			printf("[ERROR][STACK][stack_push] Could not allocate memory. Exiting.");

			exit(1);
		} else {
			element->data = data;
			element->next = stack->element;

			stack->element = element;
		}
	}
}


// Get the first element of the stack or a NULL-pointer
// 
// Parameters:
//     stack - The stack
STACK_TYPE stack_pop(STACK stack) {
	STACK_ELEMENT element;
	STACK_TYPE data;

	if (stack != NULL && stack->element != NULL) {
		element = stack->element;
		data    = element->data;

		stack->element = element->next;

		free(element);

		return data;
	} else {
		return NULL;
	}
}


// Get the length of the stack
// 
// Parameters:
//     stack - The stack
unsigned int stack_length(STACK stack) {
	unsigned int counter = 0;
	STACK_ELEMENT element;

	if (stack != NULL) {
		element = stack->element;

		while (element != NULL) {
			element = element->next;
			counter++;
		}

		return counter;
	} else {
		return 0;
	}
}

// Get the value of element `index` in the stack
// 
// Parameters:
//     stack - The stack
//     index - The index of the element to get
STACK_TYPE stack_get(STACK stack, unsigned int index) {
	STACK_ELEMENT element;

	if (stack != NULL && index < stack_length(stack)) {
		element = stack->element;

		while (index-- > 0) {
			element = element->next;
		}

		return element->data;
	} else {
		return NULL;
	}
}

// Output the stack for debugging purpose
// 
// Parameters:
//     stack - The stack to be printed
void stack_print(STACK stack) {
	unsigned int size = stack_length(stack),
	             i;

	printf("[");
	for (i = 0; i < size; i++) {
		printf(STACK_LITERAL, stack_get(stack, i));
		
		if (i < size - 1) {
			printf(", ");
		}
	}
	printf("]\n");
}