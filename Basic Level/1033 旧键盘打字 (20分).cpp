#include <iostream>
using namespace std;
int main() {
	string broken, text;
	getline(cin, broken);
	getline(cin, text);
	for (int i = 0; i < text.length(); i++) {
		if (broken.find(toupper(text[i])) != string::npos) continue;
		if (isupper(text[i]) && broken.find('+') != string::npos) continue;
		cout << text[i];
	}
	return 0;
}
