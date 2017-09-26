#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {

	ll a, b;
	ll res = 0;
	ll gcd_num = 0;

	cin >> a >> b;

	if (a > b) gcd_num = gcd(a, b);
	else gcd_num = gcd(b, a);

	res = a * b / gcd_num;
	cout << res;
	return 0;
}