#include <iostream>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int a, b, c;

	cin >> a >> b;
	cin >> c;
	if (a + b >= 2 * c) {
		printf("%d", a + b - 2 * c);
	}
	else {
		printf("%d", a + b);
	}
	return 0;
}