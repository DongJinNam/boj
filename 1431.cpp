#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string &l_str, const string &r_str) {
	if (l_str.length() == r_str.length()) {
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < l_str.length(); i++) {
			char c1 = l_str[i];
			char c2 = r_str[i];
			if (c1 >= '0' && c1 <= '9') {
				sum1 += (int)c1 - '0';
			}
			if (c2 >= '0' && c2 <= '9') {
				sum2 += (int)c2 - '0';
			}
		}
		if (sum1 == sum2) return l_str < r_str;
		else {
			if (sum1 < sum2) return true;
			else return false;
		}
	}
	return l_str.length() < r_str.length();
}

int main() {
	std::ios::sync_with_stdio(false);

	vector<string> vec_str;
	int N;

	cin >> N;

	vec_str.resize(N);
	for (int i = 0; i < N; i++) {
		std::string s;
		cin >> s;
		vec_str[i] = s;
	}
	std::sort(vec_str.begin(), vec_str.end(), cmp);
	for (int i = 0; i < vec_str.size(); i++) {
		cout << vec_str[i] << endl;
	}
	return 0;
}