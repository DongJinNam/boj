#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int a, b, c;
std::vector<int> d_arr;

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);

	cin >> n;
	cin >> a >> b;
	cin >> c;
	d_arr.resize(n, 0);
	for (int i = 0; i < n; i++)
		cin >> d_arr[i];
	// greedy algorithm
	std::sort(d_arr.begin(), d_arr.end());
	int ans = c / a;
	for (int i = n; i > 0; i--) {
		int temp_cal = c;
		int temp_val = a;
		for (int j = n - 1; j >= n - i; j--) {
			temp_cal += d_arr[j];
			temp_val += b;
		}
		if (temp_cal / temp_val > ans) {
			ans = temp_cal / temp_val;
		}
	}
	cout << ans << "\n";
	return 0;
}