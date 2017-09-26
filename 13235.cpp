#include <iostream>
#include <string>

using namespace std;

int main() {

	std::ios::sync_with_stdio(false);
	string s;
	cin >> s;

	int i, j;

	if (s.length() == 1) {
		cout << "true";
	}
	else {
		bool ans = true;
		for (i = 0; i < s.length() / 2; i++) {
			if (s[i] != s[s.length() - 1 - i]) {
				ans = false;
				break;
			}
		}
		if (ans) cout << "true";
		else cout << "false";
	}
	return 0;
}