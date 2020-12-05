#include <iostream>
using namespace std;
int main() {
	string n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n.length(); i++)
		sum += (n[i] - '0');
	string s = to_string(sum);
	string arr[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
	cout << arr[s[0] - '0'];
	for (int i = 1; i < s.length(); i++)
		cout << " " << arr[s[i] - '0'];
	return 0;
}
