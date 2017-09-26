#include <iostream>
#include <string>

using namespace std;

char map[26] = { 'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q' };

int main() {

	std::ios::sync_with_stdio(false);

	int tc, i, j;
	cin >> tc;
	for (i = 0; i < tc; i++) {

		string s;
		std::getline(std::cin, s);

		if (s.length() == 0) {
			i--;
			continue;
		}

		cout << "Case #" << i + 1 << ": ";

		for (j = 0; j < s.length(); j++) {
			if (s[j] >= 'a' && s[j] <= 'z') {
				int idx = (int)s[j] - 'a';
				s[j] = map[idx];
			}
		}
		cout << s << "\n";
	}
	return 0;
}