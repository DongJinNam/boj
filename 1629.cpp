#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

typedef long long ll;

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	int temp_b = b;
	string digit2_b;
	while (temp_b > 0) {
		if (temp_b % 2 == 0) digit2_b += '0';
		else digit2_b += '1';
		temp_b >>= 1;
	}
	std::reverse(digit2_b.begin(), digit2_b.end());

	// square and multiply algorithm
	ll result = 1;
	for (int i = 0; i < digit2_b.length(); i++) {
		result = (result * result) % c;
		if (digit2_b[i] == '1') {
			result = (result * a) % c;
		}
	}
	cout << result << "\n";
	return 0;
}