#include <stdio.h>

#define MAX 30
#define Once 1
#define Twice 2

typedef enum {false, true} bool;
typedef int ElementType;
struct StackRecord {
	ElementType Data;
	int         Tag; 	// Tag=2 means second time to pop out
};

int main()
{
	char OP[5];
	bool flag = false; 	// flag to control output format
	int N, i, size = 0; 	// size to indicate stack capacity
	struct StackRecord stack[MAX];

	scanf("%d", &N);
	if (!N) return 0;
	for (i = 0; i < 2*N; i++) {
		scanf("%s", OP);
		switch (OP[3]) {
		case 'h': 	// Push
			scanf("%d", &stack[size].Data);
			stack[size++].Tag = Once; 	// First time pushed into stack
			break;
		default: 	// Pop
			while (size > 0 && stack[size-1].Tag == Twice) { 	// Pop out node(s) with Tag=2
				if (flag) printf(" "); else flag = true;
				printf("%d", stack[--size].Data);
			}
			if (size > 0) stack[size-1].Tag = Twice;
			break;
		}
	}
	while (size) { 	// Pop out those remaining nodes
		if (flag) printf(" "); else flag = true;
		printf("%d", stack[--size].Data);
	}
	return 0;
}

