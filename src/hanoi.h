#ifndef _HANOI_INCLUDED_
#define _HANOI_INCLUDED_ 1

// get the stack definitions
#define STACK_TYPE int
#define STACK_LITERAL "%d"
#include "stack.h"

// define the hanoi struct as type
typedef struct _HANOI* HANOI;

// method prototypes
void hanoi(int height);
HANOI new_hanoi(int height);

void hanoi_solve(STACK a, STACK b, STACK c, int n, HANOI hanoi);

void print_towers(HANOI hanoi);
void center_char(char c, int width, int repeatings);
void repeat_char(char c, int repeatings);

#endif