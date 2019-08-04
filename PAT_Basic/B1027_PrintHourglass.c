/**
 * Sample Input:
 * 19 *
 * Sample Output:
 * *****
 *  ***
 *   *
 *  ***
 * *****
 * 2
 */
#include <stdio.h>

#define MAXN 1000

void PrintChar(char ch, int N);
void Hourglass(char ch, int most);

int main()
{
	int N, NumTriangle, incre;
	char ch;

	scanf("%d %c", &N, &ch);
	for (NumTriangle=1, incre=1; NumTriangle+2*(incre+2) <= N; 
			NumTriangle+=2*(incre+2), incre+=2) ;

	/* 'incre' to represent the length of side with most characters used */
	Hourglass(ch, incre);
	printf("%d\n", N-NumTriangle);

	return 0;
}

void PrintChar(char ch, int N)
{
	int i;

	for (i = 0; i < N; i++)
		printf("%c", ch);
}

void Hourglass(char ch, int most)
{
	int spaceNum, incre;

	for (incre=most, spaceNum=0; incre >= 1; incre-=2, spaceNum++) {
		PrintChar(' ', spaceNum);
		PrintChar(ch, incre);
		printf("\n");
	}
	for (incre=3, spaceNum-=2; incre <= most; incre+=2, spaceNum--) {
		PrintChar(' ', spaceNum);
		PrintChar(ch, incre);
		printf("\n");
	}
}
