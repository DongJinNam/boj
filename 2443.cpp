#include <iostream>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 1; j < (n << 1); j++) {			
			if (n - i <= j && j <= n + i) {
				cout << "*";
			}
			else if (j < n - i) {
				cout << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}