#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 숫자를 담는 배열
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
			// dp[i] : 길이가 i일 때, 부분 숫자열 중 가장 작은 값을 가지는 원소값.
			dp.push_back(num[i]);
		}
		else {
			// lower_bound : dp 배열 내에서 num[i] 값이 들어갈 때, num[i]보다 작은 값들 중 가장 큰 값 뒤에 해당하는 위치값.
			// upper_bound : dp 배열 내에서 num[i] 값이 들어갈 때, num[i]보다 작거나 같은 값들 중 가장 큰 값 뒤에 해당하는 위치값.
			auto it = std::lower_bound(dp.begin(), dp.end(), num[i]);
			*it = num[i];
		}
	}
	cout << dp.size() << "\n";
	return 0;
}