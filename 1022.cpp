#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int setMax(int target, int val) {
	if (val < 0) target = -val > target ? -val : target;
	else target = val > target ? val : target;
	return target;
}

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);

	int r1, r2, c1, c2;
	int limit_max = 0;
	cin >> r1 >> c1 >> r2 >> c2;
	limit_max = setMax(limit_max, r1);
	limit_max = setMax(limit_max, r2);
	limit_max = setMax(limit_max, c1);
	limit_max = setMax(limit_max, c2);

	//std::vector<std::vector<int>> dp(2 * limit_max + 1, std::vector<int>(2 * limit_max + 1,0));
	std::vector<std::vector<int>> dp2(r2-r1+1, std::vector<int>(c2-c1+1, 0));

	int s_r = limit_max + r1;
	int s_c = limit_max + c1;
	int e_r = limit_max + r2;
	int e_c = limit_max + c2;

	if (s_r <= limit_max && limit_max <= e_r && s_c <= limit_max && limit_max <= e_c) {
		dp2[limit_max - s_r][limit_max - s_c] = 1;
	}
	for (int i = 1; i <= limit_max; i++) {
		int val = (2 * i + 1)*(2 * i + 1);
		if (s_r <= limit_max + i && limit_max + i <= e_r && s_c <= limit_max + i && limit_max + i <= e_c) {
			dp2[limit_max + i - s_r][limit_max + i - s_c] = val;
		}
		for (int j = limit_max + i - 1; j >= limit_max - i; j--) {
			//dp[limit_max + i][j] = dp[limit_max + i][j + 1] - 1;
			val--;
			if (s_r <= limit_max + i && limit_max + i <= e_r && s_c <= j && j <= e_c) {
				dp2[limit_max + i - s_r][j - s_c] = val;
			}
		}
		for (int j = limit_max + i - 1; j >= limit_max - i; j--) {
			//dp[j][limit_max - i] = dp[j+1][limit_max - i] - 1;
			val--;
			if (s_r <= j && j <= e_r && s_c <= limit_max - i && limit_max - i <= e_c) {
				dp2[j - s_r][limit_max - i - s_c] = val;
			}
		}
		for (int j = limit_max - i + 1; j <= limit_max + i; j++) {
			//dp[limit_max - i][j] = dp[limit_max - i][j-1] - 1;
			val--;
			if (s_r <= limit_max - i && limit_max - i <= e_r && s_c <= j && j <= e_c) {
				dp2[limit_max - i - s_r][j - s_c] = val;
			}
		}
		for (int j = limit_max - i + 1; j < limit_max + i; j++) {
			//dp[j][limit_max+i] = dp[j-1][limit_max + i] - 1;
			val--;
			if (s_r <= j && j <= e_r && s_c <= limit_max + i && limit_max + i <= e_c) {
				dp2[j - s_r][limit_max + i - s_c] = val;
			}
		}
	}

	int start_i = limit_max + r1;
	int start_j = limit_max + c1;
	int end_i = limit_max + r2;
	int end_j = limit_max + c2;
	int max_val = 0;

	for (int i = 0; i < r2 - r1 + 1; i++) {
		for (int j = 0; j < c2 - c1 + 1; j++) {
			max_val = dp2[i][j] > max_val ? dp2[i][j] : max_val;
		}
	}

	int temp = max_val;
	int dc = 0;
	while (temp > 0) {
		temp /= 10;
		dc++;
	}

	// 출력하기.
	for (int i = 0; i < r2 - r1 + 1; i++) {
		for (int j = 0; j < c2 - c1 + 1; j++) {
			int t_val = dp2[i][j];
			int ac = 0;
			while (t_val > 0) {
				t_val /= 10;
				ac++;
			}
			for (int k = 0; k < dc - ac; k++)
				cout << " ";
			cout << dp2[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}