
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int getId(char *name)
{
	int ret = 0;
	for (int i = 0; i < 4; i++)
		if (isalpha(name[i])) ret = ret*26 + name[i]-'A';
		else ret = ret*10 + name[i]-'0';
	return ret;
}

const int maxn = 26*26*26*10+1;
vector<int> v[maxn];
int main()
{
	// freopen("tst.txt", "r", stdin);
	int n, k;
	char name[5];

	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) {
		int courseId, num;
		scanf("%d%d", &courseId, &num);
		for (int j = 0; j < num; j++) {
			scanf("%s", name);
			int id = getId(name);
			v[id].push_back(courseId);
		}
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", name);
		int id = getId(name);
		printf("%s %d", name, v[id].size());
		sort(v[id].begin(), v[id].end());
		for (int j = 0; j < (int)v[id].size(); j++)
			printf(" %d", v[id][j]);
		printf("\n");
	}

	return 0;
}


