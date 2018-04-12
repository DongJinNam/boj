#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <cstring>
#include <queue>

#define MAX 1000001

typedef std::pair<int, int> iPair;

using namespace std;

int yy[4] = { 0,0,1,-1 };
int xx[4] = { 1,-1,0,0 };
int n, m;
std::vector<std::vector<int>> dp;
std::vector<int> wall_vec;
std::vector<string> str_vec;
bool visited[MAX];

// 영역 안에 들어가있는지 체크
bool check(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}

// dfs
void dfs(int r, int c) {
	for (int i = 0; i < 4; i++) {
		int ny = r + yy[i];
		int nx = c + xx[i];
		if (check(ny, nx) && dp[r][c] + 1 < dp[ny][nx] && str_vec[ny][nx] == '0') {
			dp[ny][nx] = dp[r][c] + 1;
			dfs(ny, nx);
		}
		// 벽을 만난 경우에는, 벽의 위치를 저장하는 벡터에 위치를 저장.
		if (check(ny, nx) && str_vec[ny][nx] == '1' && dp[r][c] + 1 < dp[ny][nx]) {
			visited[ny*m + nx] = true;
			dp[ny][nx] = dp[r][c] + 1;
			wall_vec.push_back(ny*m + nx);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> n >> m;
	str_vec.resize(n, "");
	dp.resize(n, std::vector<int>(m, MAX));

	memset(visited, false, sizeof(bool)*MAX);
	for (int i = 0; i < n; i++) {
		cin >> str_vec[i];
	}
	dp[0][0] = 1;
	dfs(0, 0); // 우선 벽을 만날 때까지 dfs
	// 벽을 기준으로 bfs
	for (auto it : wall_vec) {		
		str_vec[it / m][it % m] = '0';
		std::queue<iPair> bfs;
		bfs.push(make_pair(dp[it/m][it%m],it));
		while (!bfs.empty()) {
			iPair front = bfs.front();
			int r = front.second / m;
			int c = front.second % m;
			bfs.pop();
			// 목적지 도착한 경우 bfs 중지.
			if (r == n - 1 && c == m - 1) {
				break;
			}
			for (int i = 0; i < 4; i++) {
				int ny = r + yy[i];
				int nx = c + xx[i];
				if (check(ny, nx) && front.first + 1 < dp[ny][nx] && str_vec[ny][nx] == '0') {
					dp[ny][nx] = front.first + 1;
					bfs.push(make_pair(dp[ny][nx],ny*m + nx));
				}
			}
		}
		str_vec[it / m][it % m] = '1';
	}
	// dfs + bfs + dp 로 해서 목적지까지 최단거리 계산.
	if (dp[n - 1][m - 1] >= MAX)
		cout << "-1\n";
	else
		cout << dp[n - 1][m - 1] << "\n";
	return 0;
}