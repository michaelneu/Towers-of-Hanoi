#ifndef _STACK_INCLUDED_
#define _STACK_INCLUDED_ 1

// pseudo generic stack type. defaults to 
// int, if no type is supplied on include
#ifndef STACK_TYPE
	#define STACK_TYPE int
#endif

#ifndef STACK_LITERAL
	#define STACK_LITERAL "%x"
#endif


// define the stack structs as types
typedef struct _STACK* STACK;
typedef struct _STACK_ELEMENT* STACK_ELEMENT;


// method prototypes
STACK new_stack();

void stack_push(STACK stack, STACK_TYPE data);
STACK_TYPE stack_pop(STACK stack);
STACK_TYPE stack_get(STACK stack, unsigned int index);

unsigned int stack_length(STACK stack);
void stack_print(STACK stack);

#endif