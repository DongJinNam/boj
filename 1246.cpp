#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int n, m;
	int i, j;
	int price = 0, ad = 0;
	cin >> n >> m;
	std::vector<int> num_arr(m, 0);
	for (i = 0; i < m; i++) {
		cin >> num_arr[i];
	}
	std::sort(num_arr.begin(), num_arr.end());
	for (i = 0; i < m; i++) {
		int amount = 0;
		if (m - i >= n) {
			amount = n;
		}
		else {
			amount = m - i;
		}
		if (ad < num_arr[i] * amount) {
			ad = num_arr[i] * amount;
			price = num_arr[i];
		}
	}
	cout << price << " " << ad;
	return 0;
}