#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ���ڸ� ��� �迭
int num[1000001] = { 0 };

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> num[i];
	// LIS (Longest Increasing Subsequence)
	std::vector<int> dp;
	dp.push_back(num[0]);
	for (int i = 1; i < n; i++) {
		if (dp.back() < num[i]) {
			// dp[i] : ���̰� i�� ��, �κ� ���ڿ� �� ���� ���� ���� ������ ���Ұ�.
			dp.push_back(num[i]);
		}
		else {
			// lower_bound : dp �迭 ������ num[i] ���� �� ��, num[i]���� ���� ���� �� ���� ū �� �ڿ� �ش��ϴ� ��ġ��.
			// upper_bound : dp �迭 ������ num[i] ���� �� ��, num[i]���� �۰ų� ���� ���� �� ���� ū �� �ڿ� �ش��ϴ� ��ġ��.
			auto it = std::lower_bound(dp.begin(), dp.end(), num[i]);
			*it = num[i];
		}
	}
	cout << dp.size() << "\n";
	return 0;
}