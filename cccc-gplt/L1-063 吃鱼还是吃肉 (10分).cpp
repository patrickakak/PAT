#include <iostream>
using namespace std;
int main() {
	int n, sex, ht, wt;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &sex, &ht, &wt);
		if (sex == 1) {
			if (ht < 130) printf("duo chi yu! ");
			else if (ht > 130) printf("ni li hai! ");
			else printf("wan mei! ");
			if (wt < 27) printf("duo chi rou!\n");
			else if (wt > 27) printf("shao chi rou!\n");
			else printf("wan mei!\n");
		} else {
			if (ht < 129) printf("duo chi yu! ");
			else if (ht > 129) printf("ni li hai! ");
			else printf("wan mei! ");
			if (wt < 25) printf("duo chi rou!\n");
			else if (wt > 25) printf("shao chi rou!\n");
			else printf("wan mei!\n");
		}
	}
	return 0;
}
