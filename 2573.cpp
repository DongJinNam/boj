#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define V_MAX 301

typedef std::pair<int, int> iPair;

using namespace std;

int n, m;
int yy[4] = { 0,0,1,-1 };
int xx[4] = { 1,-1,0,0 };
std::vector<std::vector<int>> dp;

bool check(int ny, int nx, int row, int col) {
	return ny >= 0 && ny < row && nx >= 0 && nx < col;
}

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);

	cin >> n >> m;
	dp.resize(n, std::vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> dp[i][j];
		}
	}
	int ans = 0;
	while (1) {
		std::vector<std::vector<int>> delta(n, std::vector<int>(m, 0));
		std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
		int area = 0;
		int r = 0, c = 0;
		// 변화량 측정
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (dp[i][j] > 0) {
					int minus = 0;
					for (int k = 0; k < 4; k++) {
						int ny = i + yy[k];
						int nx = j + xx[k];
						if (check(ny, nx, n, m) && dp[ny][nx] == 0) minus++;
					}
					delta[i][j] = minus;
				}
			}
		}
		// 변화량 적용
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				dp[i][j] = (dp[i][j] - delta[i][j]) < 0 ? 0 : (dp[i][j] - delta[i][j]);
				if (dp[i][j] > 0) {
					r = i; // bfs 시작 행
					c = j; // bfs 시작 열
					area++; // 총 점의 개수 체크
				}
			}
		}
		// 모든 점이 녹은 경우[빙산이 두 덩이로 나눠지지 않았으므로]
		if (area == 0) {
			ans = 0;
			break;
		}
		std::queue<iPair> q;		
		int v_count = 0;
		q.push(make_pair(r, c));
		visited[r][c] = true;
		v_count++;
		while (!q.empty()) {
			iPair front = q.front();
			int row = front.first;
			int col = front.second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = row + yy[i];
				int nx = col + xx[i];
				if (check(ny, nx, n, m) && dp[ny][nx] > 0 && !visited[ny][nx]) {
					q.push(make_pair(ny, nx));
					visited[ny][nx] = true;
					v_count++;
				}
			}
		}
		ans++;
		// 남아있는 점의 개수와 bfs 방문 점의 개수가 다른 경우, 빙산이 두 덩어리 이상으로 나눠진 것임.
		if (area != v_count) break;
	}
	cout << ans << "\n";
	return 0;
}