#include <iostream>
#include <string>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	long long a, b;	
	string c;

	cin >> a >> b >> c;

	int cnt = (int)c[c.length() - 1] - '0';

	if (cnt % 2 == 0) {
		cout << a;
	}
	else {
		long long ans = a ^ b;
		cout << ans;
	}
	return 0;
}