#include <iostream>
#include <string>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int tc, i;
	cin >> tc;
	while (tc--) {
		string s1, s2;
		int len = 0; // 알파벳 거리 차이
		cin >> s1 >> s2;
		cout << "Distances: ";
		for (i = 0; i < s1.length(); i++) {
			char c1 = s1.at(i);
			char c2 = s2.at(i);
			if (c1 == c2) len = 0;
			else if (c1 > c2) {
				len = (int)(c2 + 26) - c1;
			}
			else {
				len = (int)c2 - c1;
			}
			cout << len << " ";
		}
		cout << endl;
	}
	return 0;
}