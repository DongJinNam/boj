#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdlib.h>

using namespace std;

int inf = 1000000000;

bool canCheck(int cur, int diff) {
	return cur + diff >= 0 && cur + diff <= 100000;
}

int main() {

	int A, B, N, M;
	std::vector<int> dp(100001, inf);
	std::vector<bool> check(100001, false);
	std::queue<int> bfs; // 위치값을 넣을 예정
	int i, j;
	int opt[6];

	scanf("%d %d %d %d", &A, &B, &N, &M);

	opt[0] = A;
	opt[1] = -A;
	opt[2] = B;
	opt[3] = -B;
	opt[4] = 1;
	opt[5] = -1;

	dp[N] = 0;
	bfs.push(N);
	while (!bfs.empty()) {
		int front = bfs.front();
		int diff_min = std::abs(M - front);
		bfs.pop();
		
		for (i = 0; i < 6; i++) {
			if (canCheck(front, opt[i]) && (dp[front] + 1) < dp[front + opt[i]]) {
				dp[front + opt[i]] = std::min(dp[front] + 1, dp[front + opt[i]]);
				bfs.push(front + opt[i]);
			}
		}
		if (canCheck(front, front*(A - 1)) && (dp[front] + 1) < dp[front * A]) {
			dp[front * A] = std::min(dp[front * A], dp[front] + 1);
			bfs.push(front + front * (A - 1));
		}
		if (canCheck(front, front*(B - 1)) && (dp[front] + 1) < dp[front * B]) {
			dp[front * B] = std::min(dp[front * B], dp[front] + 1);
			bfs.push(front + front * (B - 1));
		}
		
	}

	printf("%d", dp[M]);
	return 0;
}