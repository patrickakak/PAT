/**
 * Sample input:
 * 3485djDkxh4hhGE 
 * 2984akDfkkkkggEdsb 
 * s&hgsfdk 
 * d&Hyscvnm
 * -------------
 * Sample output:
 * THU 14:04
 */
#include <stdio.h>
#include <ctype.h>

#define S_LEN 80
// Letter to Day
// A B C D E F G
// 0 1 2 3 4 5 6
char L2D[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};


int main()
{
	// freopen("test.txt", "r", stdin);
	char s1[S_LEN], s2[S_LEN], s3[S_LEN], s4[S_LEN];
	int day, hr, min, i, j;

	scanf("%s %s", s1, s2);
	scanf("%s %s", s3, s4);
	i = j = 0;
	while (s1[i] && s2[j]) {
		if (s1[i] >= 'A' && s1[i] <= 'G' && s1[i] == s2[j]) {
			day = s1[i] - 'A';
			break;
		}
		i++; j++;
	}
	i++; j++;
	while (s1[i] && s2[j]) {
		if (s1[i] >= 'A' && s1[i] <= 'N' && s1[i] == s2[j]) {
			hr = s1[i] - 'A' + 10;
			break;
		} else if (s1[i] >= '0' && s1[i] <= '9' && s1[i] == s2[j]) {
			hr = s1[i] - '0';
			break;
		}
		i++; j++;
	}
	i = j = 0;
	while (s3[i] && s4[j]) {
		if (isalpha(s3[i]) && s3[i] == s4[j]) {
			min = i;
			break;
		}
		i++; j++;
	}
	printf("%s %02d:%02d\n", L2D[day], hr, min);

	return 0;
}

