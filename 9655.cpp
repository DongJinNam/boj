#include <iostream>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	if (n % 2 == 1) cout << "SK";
	else cout << "CY";
	return 0;
}