#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	string s;
	std::vector<string> str_vec;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		string temp;
		temp = s.substr(i, s.length() - i);
		str_vec.push_back(temp);
	}
	std::sort(str_vec.begin(), str_vec.end());
	for (int i = 0; i < str_vec.size(); i++) {
		cout << str_vec[i] << endl;
	}
	return 0;
}