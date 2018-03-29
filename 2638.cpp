#include <iostream>
#include <vector>
#include <queue>

typedef std::pair<int, int> iPair;

using namespace std;

int yy[4] = { 0,0,1,-1 };
int xx[4] = { 1,-1,0,0 };

bool check(int ny, int nx, int row, int col) {
	return ny >= 0 && ny < row && nx >= 0 && nx < col;
}

int main() {
	std::ios::sync_with_stdio(false);
	int n, m;
	int total = 0;
	cin >> n >> m;

	std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> dp[i][j];
			if (dp[i][j] == 1) {
				total++;
			}
		}
	}
	int step = 0;
	// graph 문제는 dfs or bfs로 모두 해결가능
	while (total > 0) {
		dp[0][0] = -1;
		std::queue<iPair> bfs;
		bfs.push(iPair(0, 0));
		while (!bfs.empty()) {
			iPair pos = bfs.front();
			bfs.pop();
			for (int i = 0; i < 4; i++) {
				int ny = pos.first + yy[i];
				int nx = pos.second + xx[i];
				if (check(ny, nx, n, m) && dp[ny][nx] > 0) {
					dp[ny][nx]++;
				}
				if (check(ny, nx, n, m) && dp[ny][nx] == 0) {
					dp[ny][nx] = -1;
					bfs.push(iPair(ny, nx));
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (dp[i][j] > 2) {
					dp[i][j] = 0;
					total--;
				}
				else if (dp[i][j] <= 2 && dp[i][j] > 0) {
					dp[i][j] = 1;
				}
				else {
					dp[i][j] = 0;
				}
			}
		}
		step++;
	}
	cout << step << "\n";
	return 0;
}