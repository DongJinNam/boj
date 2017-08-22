#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	std::ios::sync_with_stdio(false);
	int n1, n2, n3, n4;
	int ans1 = 0, ans2 = 0;
	cin >> n1 >> n2;
	cin >> n3 >> n4;

	int max_gcd = gcd(n2, n4);
	int mul = n2 * n4 / max_gcd;

	ans1 += n1 * n4 / max_gcd;
	ans1 += n3 * n2 / max_gcd;
	ans2 = mul;

	int temp = gcd(ans1, ans2);
	ans1 /= temp;
	ans2 /= temp;

	cout << ans1 << " " << ans2;
	return 0;
}