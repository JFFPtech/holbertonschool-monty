#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int sp = -1;

void push(int value, int line_number) {
    if (stack.top >= STACK_SIZE) {
        fprintf(stderr, "L%d: Stack overflow\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack.stack[++stack.top] = value;
}

void pall() {
    int i;
    for (i = stack.top; i > 0; i--) {
        printf("%d\n", stack.stack[i]);
    }
}

int main(int argc, char *argv[]) {
    // Initialize stack
    stack.top = 0;

    // Sample bytecode execution
    push(1, 1);
    push(2, 2);
    push(3, 3);
    pall();

    return 0;
}
