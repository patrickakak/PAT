#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "12345678";
	char needle[] = "1";

	char *ptr = strstr(str, needle);
	if (ptr) {
		printf("*ptr=%c\n", *ptr);
	} else {
		printf("No\n");
	}
	return 0;
}
