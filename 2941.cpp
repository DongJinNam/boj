#include <iostream>
#include <string>

using namespace std;

string croatia_arr[8] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };

int main() {
	std::ios::sync_with_stdio(false);
	string s;
	int ans = 0;
	int i, j;

	cin >> s;

	for (i = 0; i < s.length(); i++) {
		int add = 0;
		for (j = 0; j < 8; j++) {
			if (i + croatia_arr[j].length() > s.length()) continue;
			string temp = s.substr(i, croatia_arr[j].length());
			if (temp == croatia_arr[j]) {
				i += croatia_arr[j].length() - 1;
			}
		}
		ans++;
	}
	cout << ans;
	return 0;
}