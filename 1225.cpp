#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int main() {
	std::ios::sync_with_stdio(false);

	string s1, s2;
	int i, j;
	ll ans = 0;
	cin >> s1 >> s2;

	for (i = 0; i < s1.length(); i++) {
		int at1 = s1[i] - '0';
		for (j = 0; j < s2.length(); j++) {
			int at2 = s2[j] - '0';
			ans += at1 * at2;
		}
	}
	cout << ans;
	return 0;
}