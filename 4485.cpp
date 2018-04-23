#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

typedef std::pair<int, int> iPair;

using namespace std;

#define MAX_VAL 1000000001

int arr[125][125] = { 0 };
int yy[4] = { 0,0,1,-1 };
int xx[4] = { 1,-1,0,0 };

bool check(int y, int x, int n) {
	return y >= 0 && y < n && x >= 0 && x < n;
}

int main() {
	int tc = 0;
	while (1) {
		int n;
		scanf("%d", &n);
		if (n == 0) break;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		
		std::vector<std::vector<int>> dp(n, std::vector<int>(n, MAX_VAL));
		std::priority_queue<iPair> pq;
		pq.push(make_pair(0, 0));
		dp[0][0] = arr[0][0];
		while (!pq.empty()) {
			int cost = -pq.top().first;
			int r = pq.top().second / n;
			int c = pq.top().second % n;
			pq.pop();

			for (int i = 0; i < 4; i++) {
				int ny = r + yy[i];
				int nx = c + xx[i];
				if (check(ny, nx, n) && dp[r][c] + arr[ny][nx] < dp[ny][nx]) {
					dp[ny][nx] = dp[r][c] + arr[ny][nx];
					pq.push(make_pair(-dp[ny][nx], ny*n + nx));
				}
			}		
		}
		printf("Problem %d: %d\n", ++tc, dp[n - 1][n - 1]);
	}
	return 0;
}