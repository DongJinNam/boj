#include <iostream>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	if (n % 2 == 1) cout << "CY";
	else cout << "SK";
	return 0;
}