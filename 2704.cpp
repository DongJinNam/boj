#include <iostream>
#include <string>

using namespace std;

int main() {

	std::ios::sync_with_stdio(false);
	cout.tie(NULL);
	int tc;
	cin >> tc;
	while (tc--) {
		string time;
		string s_h, s_m, s_s;
		int h = 0, m = 0, s = 0;
		cin >> time;

		h = stoi(time.substr(0, 2));
		m = stoi(time.substr(3, 2));
		s = stoi(time.substr(6, 2));

		for (int i = 5; i >= 0; i--) {
			if (h & (1 << i)) s_h += '1';
			else s_h += '0';
			if (m & (1 << i)) s_m += '1';
			else s_m += '0';
			if (s & (1 << i)) s_s += '1';
			else s_s += '0';
		}
		for (int i = 0; i < 6; i++) {
			cout << s_h[i] << s_m[i] << s_s[i];
		}
		cout << " ";
		cout << s_h;
		cout << s_m;
		cout << s_s;
		cout << "\n";
	}		

	return 0;
}