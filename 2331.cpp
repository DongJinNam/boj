#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);

	string s;
	int A = 0, P;
	int i, j;
	bool bFind = false;
	vector<int> dp;
	std::vector<int>::iterator tempIt;
	vector<string> dp_s;

	cin >> s >> P;
	for (i = 0; i < s.length(); i++) {
		int at = (int)s[i] - '0';
		A += at * std::pow(10, s.length() - 1 - i);
	}
	dp.push_back(A);
	dp_s.push_back(s);
	int count = 0;
	while (!bFind) {
		string temp_s;
		A = 0;
		for (i = 0; i < dp_s[count].length(); i++) {
			int at = (int)dp_s[count][i] - '0';
			A += std::pow(at, P);
		}
		// 현재 벡터에 존재하는지 검사.
		if (std::find(dp.begin(), dp.end(), A) != dp.end()) {
			bFind = true;
			tempIt = std::find(dp.begin(), dp.end(), A);
			break;
		}

		dp.push_back(A);

		int temp = A;
		int digit = 0;
		while (temp > 0) {
			temp /= 10;
			digit++;
		}

		while (A > 0) {
			int val;
			if (digit > 1) {
				val = A / std::pow(10,digit-1);
				A -= val * std::pow(10, digit - 1);
			}
			else {
				val = A % 10;
				A -= val;
			}
			char ch = (char)val + '0';
			temp_s += ch;
			digit--;
		}
		dp_s.push_back(temp_s);
		count++;
	}

	int ans = 0;
	for (std::vector<int>::iterator it = dp.begin(); it != tempIt; it++) {
		ans++;
	}
	printf("%d", ans);
	return 0;
}