#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);

	string a, b;
	string str_and, str_or,str_xor,not_a, not_b;
	cin >> a >> b;

	
	for (int i = 0; i < b.length(); i++) {
		int val = (int)(a[i] + b[i] - '0' - '0');
		// and
		if (a[i] == '1' && b[i] == '1') str_and += '1';
		else str_and += '0';
		// or
		if (a[i] == '1' || b[i] == '1') str_or += '1';
		else str_or += '0';
		// xor
		if (val == 1) str_xor += '1';
		else str_xor += '0';
		// not a
		if (a[i] == '1') not_a += '0';
		else not_a += '1';
		// not b
		if (b[i] == '1') not_b += '0';
		else not_b += '1';
	}
	
	cout << str_and << "\n";
	cout << str_or << "\n";
	cout << str_xor << "\n";
	cout << not_a << "\n";
	cout << not_b << "\n";
	return 0;
}