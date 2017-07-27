#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string &l_str, const string &r_str) {
	if (l_str.length() == r_str.length()) return l_str < r_str;
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
	vec_str.erase(std::unique(vec_str.begin(), vec_str.end()), vec_str.end());
	for (int i = 0; i < vec_str.size(); i++) {
		cout << vec_str[i] << endl;
	}
	return 0;
}