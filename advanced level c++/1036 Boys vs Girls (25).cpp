#include <iostream>
using namespace std;
int main() {
	int n, grade, lm = 100, hf = 0, flag = 0;
	cin >> n;
	string name, gender, id, m, f, fid, mid;
	for (int i = 0; i < n; i++) {
		cin >> name >> gender >> id >> grade;
		if (gender == "F" && grade > hf) {
			f = name;
			fid = id;
			hf = grade;
		}
		if (gender == "M" && grade < lm) {
			m = name;
			mid = id;
			lm = grade;
		}
	}
	if (m == "" || f == "") flag = 1;
	if (f == "") printf("Absent\n");
	else printf("%s %s\n", f.c_str(), fid.c_str());
	if (m == "") printf("Absent\n");
	else printf("%s %s\n", m.c_str(), mid.c_str());
	if (flag == 1) printf("NA");
	else printf("%d", hf-lm);
	return 0;
}
