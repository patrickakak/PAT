#include <stdio.h>

#define MAX 30
typedef int ElementType;
struct StackRecord {
	ElementType Data;
	int         Tag; 	// Tag=2 means second time to pop out
};

int main()
{
	int N, i, flag = 0, size = 0;
	struct StackRecord stack[MAX];

  scanf("%d", &N);
  if (!N) return;
	for (i = 0; i < 2*N; i++) {
		char OP[5];
		scanf("%s", OP);
		if (OP[3]) { 	// Push
			scanf("%d", &stack[size].Data);
			stack[size].Tag = 1; // First time pushed into stack
			++size;
		} else { 	// Pop
			while (size > 0 && stack[size-1].Tag == 2) { // Pop out node(s) with Tag=2
				if (flag) printf(" "); else flag = 1;
				printf("%d", stack[--size].Data);
			}
			if (size > 0) stack[size-1].Tag = 2;
		}
	}
	while (size) { // Pop out those remaining nodes
		if (flag) printf(" "); else flag = 1;
		printf("%d", stack[--size].Data);
	}
	return 0;
}

