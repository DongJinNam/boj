#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool dp[10001];

int main() {
	
	int tc, i, j;
	std::vector<int> p_vec;
	dp[0] = true;
	dp[1] = true;
	for (i = 2; i <= 10000; i++) {
		if (dp[i] == false) {
			for (j = i + i; j <= 10000; j += i) {
				dp[j] = true;
			}
			p_vec.push_back(i); // 소수 배열
		}
	}

	scanf("%d", &tc);
	while (tc--) {
		int test, limit;
		int ans = 0, ans2 = 10000;
		scanf("%d", &test);

		std::vector<int>::iterator low;
		low = lower_bound(p_vec.begin(), p_vec.end(), test);
		limit = (low - p_vec.begin());

		for (i = 0; i < limit; i++) {
			for (j = i; j < limit; j++) {
				if (p_vec[i] + p_vec[j] > test) break;
				if (p_vec[i] + p_vec[j] == test && (p_vec[j] - p_vec[i]) < ans2 - ans) {
					ans = p_vec[i];
					ans2 = p_vec[j];
					break;
				}
			}
		}
		printf("%d %d\n", ans, ans2);
	}
	return 0;
}