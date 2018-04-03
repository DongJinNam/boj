#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

std::stack<int> ans;

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	std::vector<int> arr(n, 0);
	std::vector<int> dp;
	std::vector<int> idx_arr(n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp.push_back(arr[0]);
	idx_arr[0] = 1;
	for (int i = 1; i < n; i++) {
		if (dp.back() < arr[i]) {
			dp.push_back(arr[i]);
			idx_arr[i] = dp.size();
		}
		else {
			auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
			int idx = std::distance(dp.begin(), it);
			*it = arr[i];
			idx_arr[i] = idx + 1;
		}
	}
	cout << dp.size() << "\n";

	int size = dp.size();
	for (int i = n - 1; i >= 0; i--) {
		if (idx_arr[i] == size) {
			ans.push(arr[i]);
			size--;
		}
	}
	while (!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}
	cout << "\n";
	return 0;
}