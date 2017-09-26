#include <iostream>
#include <string>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	while (1) {

		int i, j;
		int total, amt;
		int ans = 0;
		bool bAllowed = true;
		string s;
		cin >> total >> s >> amt;

		if (total == 0 && s[0] == 'W' && amt == 0) break;

		if (s[0] == 'W') {
			if (total - amt < -200)
				bAllowed = false;
			else
				ans = total - amt;
		}
		else {
			ans = total + amt;
		}
		if (bAllowed) cout << ans << "\n";
		else cout << "Not allowed\n";
	}
	return 0;
}