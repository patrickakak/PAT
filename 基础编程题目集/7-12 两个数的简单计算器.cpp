#include <cstdio>
int main() {
	int a, b;
	char op;
	scanf("%d %c %d", &a, &op, &b);
	switch (op) {
	case '+': printf("%d", a+b); break;
	case '-': printf("%d", a-b); break;
	case '*': printf("%d", a*b); break;
	case '/': printf("%d", a/b); break;
	case '%': printf("%d", a%b); break;
	default: printf("ERROR");
	}
	return 0;
}
