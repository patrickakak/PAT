#include <iostream>
using namespace std;

int main()
{
	int n, score, max = -1, min = 101;
	string name, id, maxname, minname, maxid, minid;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name >> id >> score;
		if (score > max) {
			max = score;
			maxname = name;
			maxid = id;
		}
		if (score < min) {
			min = score;
			minname = name;
			minid = id;
		}
	}
	cout << maxname << ' ' << maxid << endl << minname << ' ' << minid;
	return 0;
}
