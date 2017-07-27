#include <iostream>
#include <string>

using namespace std;

std::pair<char, char> iPair_arr[12];

int main() {
	std::ios::sync_with_stdio(false);

	int ans = 0; // Ãâ·Â°ª
	string s;
	cin >> s;

	iPair_arr[2] = { ' ',' ' };
	iPair_arr[3] = { 'A','C' };
	iPair_arr[4] = { 'D','F' };
	iPair_arr[5] = { 'G','I' };
	iPair_arr[6] = { 'J','L' };
	iPair_arr[7] = { 'M','O' };
	iPair_arr[8] = { 'P ','S' };
	iPair_arr[9] = { 'T','V' };
	iPair_arr[10] = { 'W','Z' };
	iPair_arr[11] = { '*','/' };

	for (int i = 0; i < s.length(); i++) {
		char ch = s.at(i);
		for (int j = 2; j < 12; j++) {
			if (iPair_arr[j].first <= ch && ch <= iPair_arr[j].second) {
				ans += j;
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}