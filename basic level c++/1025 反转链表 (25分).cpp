#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
	int ad, key, next;
};
vector<node> v, w(100010);
int main() {
	int fir, n, k, ad, key, next;
	cin >> fir >> n >> k;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &ad, &key, &next);
		w[ad] = {ad, key, next};
	}
	for (int p = fir; p != -1; p = w[p].next)
		v.push_back(w[p]);
	for (int i = 0; i+k <= v.size(); i += k)
		reverse(v.begin()+i, v.begin()+i+k);
	for (int i = 0; i < v.size(); i++)
		if (i != v.size()-1) printf("%05d %d %05d\n", v[i].ad, v[i].key, v[i+1].ad);
		else printf("%05d %d -1\n", v[i].ad, v[i].key);
	return 0;
}
