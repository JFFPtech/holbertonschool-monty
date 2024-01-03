#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int sp = -1;

void push(int value, int line_number) {
	if (sp == STACK_SIZE - 1) {
		fprintf(stderr, "L%d: Stack overflow\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack[++sp] = value;
}

void pall() {
	for (int i = sp; i > 0; i--) {
		printf("%d\n", stack[i]);
	}
}

void interpret(FILE *file) {
	char line[100];
	int line_number = 0;

	while (fgets(line, sizeof(line), file) != NULL) {
		line_number++;

	char opcode[10];
	int value;

	if (sscanf(line, "%s %d", opcode, &value) == 2) {
	if (strcmp(opcode, "push") == 0) {
		push(value, line_number);
		} else if (strcmp(opcode, "pall") == 0) {
			pall();
		} else {
			fprintf(stderr, "L%d: Unknown opcode: %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	} else if (strcmp(opcode, "pall") != 0) {
		fprintf(stderr, "L%d: Invalid line: %s", line_number, line);
		exit(EXIT_FAILURE);
	} else {
		}
	}
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");
	if (file == NULL) {
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	interpret(file);

	fclose(file);
	return 0;
}
