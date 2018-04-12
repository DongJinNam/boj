#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);

	string str_digit2;
	std::vector<int> ans_vec;
	cin >> str_digit2;

	int extra = (3 - str_digit2.length() % 3);
	if (extra < 3) {
		for (int i = 0; i < extra; i++)
			str_digit2.insert(str_digit2.begin(), '0');
	}
	for (int i = 0; i < str_digit2.length(); i+=3) {
		int a = (str_digit2[i] - '0') * 4;
		int b = (str_digit2[i+1] - '0') * 2;
		int c = (str_digit2[i+2] - '0');
		cout << a + b + c;
	}
	cout << "\n";

	return 0;
}