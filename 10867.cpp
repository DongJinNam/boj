#include <iostream>

using namespace std;

bool check[2001];

int main() {
	std::ios::sync_with_stdio(false);
	int N;
	int i, j, data;
	cin >> N;

	for (i = 0; i < N; i++) {
		cin >> data;
		check[data + 1000] = true;
	}
	for (i = 0; i <= 2000; i++) {
		if (check[i] == true) {
			cout << i - 1000 << " ";
		}
	}
	return 0;
}