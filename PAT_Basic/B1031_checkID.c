/**
 * Sample input1:
 * 4
 * 320124198808240056
 * 12010X198901011234
 * 110108196711301866
 * 37070419881216001X
 * Sample output1:
 * 12010X198901011234
 * 110108196711301866
 * 37070419881216001X
 * ------------------
 * Sample input2:
 * 2
 * 320124198808240056
 * 110108196711301862
 * Sample output2:
 * All passed
 */
#include <stdio.h>

int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char Z2M[11] = {'1','0','X','9','8','7','6','5','4','3','2'};

int main()
{
	//freopen("test.txt", "r", stdin);
	int N, i, j, sum, Z, count=0;
	char id[20];

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		sum = 0;
		scanf("%s", id);
		for (j = 0; j < 17; j++) {
			if (id[j] < '0' || id[j] > '9')
				break;
			sum += (id[j]-'0') * weight[j];
		}
		if (j < 17) {
			printf("%s\n", id);
			count++;
		} else {
			Z = sum % 11;
			if (Z2M[Z] != id[17]) {
				printf("%s\n", id);
				count++;
			}
		}
	}
	if (count == 0)
		printf("All passed\n");

	return 0;
}

