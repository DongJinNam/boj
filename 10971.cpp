#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[11][11];

int main() {
	std::ios::sync_with_stdio(false);

	int N;
	int i, j;
	int ans = 1000000000;
	std::vector<int> num_vec;
	cin >> N;

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			cin >> dp[i][j];
		}
		num_vec.push_back(i);
	}

	do {
		int from, to;
		int temp = 0;
		bool bError = false;
		for (i = 0; i < N; i++) {
			from = num_vec[i];
			to = num_vec[(i + 1) % N];
			if (dp[from][to] == 0) {
				bError = true;
				break;
			}
			temp += dp[from][to];
		}
		if (bError == false) ans = temp < ans ? temp : ans;
	} while (std::next_permutation(num_vec.begin(), num_vec.end()) && num_vec[0] == 1);
	cout << ans;
	return 0;
}