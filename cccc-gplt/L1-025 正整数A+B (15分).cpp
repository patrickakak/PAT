#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char a[110], aa[110], b[110], bb[110];
	scanf("%s ", a);
	cin.getline(b, 110);
	int ta, tb, flg1 = 1, flg2 = 1;
	sscanf(a, "%d", &ta);
	sprintf(aa, "%d", ta);
	sscanf(b, "%d", &tb);
	sprintf(bb, "%d", tb);
	for (int i = 0; i < strlen(a); i++)
		if (a[i] != aa[i]) {
			flg1 = 0;
			break;
		}
	for (int i = 0; i < strlen(b); i++)
		if (b[i] != bb[i]) {
			flg2 = 0;
			break;
		}
	if (flg1 == 1 && ta >= 1 && ta <= 1000) flg1 = 2;
	if (flg2 == 1 && tb >= 1 && tb <= 1000) flg2 = 2;
	printf("%s + %s = %s\n", flg1 == 2 ? a : "?", flg2 == 2 ? b : "?", (flg1==2 && flg2==2) ? to_string(ta+tb).c_str() : "?");
	return 0;
}
