#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MIN -1

typedef std::pair<int, int> iPair;

using namespace std;

int xx[4] = { 1,-1,0,0 };
int yy[4] = { 0,0,1,-1 };
std::vector<std::vector<int>> board;
std::vector<std::vector<int>> dp;
int n;
int ans = MIN;

// 해당 점이 영역 안에 있는지 체크
bool check(int ny, int nx, int n) {
	return ny >= 0 && ny < n && nx >= 0 && nx < n;
}

// 해당 row, col을 기준으로 좌우상하만 체크
int dfs(int r, int c) {
	for (int i = 0; i < 4; i++) {
		int ny = r + yy[i];
		int nx = c + xx[i];
		if (check(ny, nx, n) && board[r][c] < board[ny][nx] && dp[ny][nx] < dp[r][c] + 1) {
			dp[ny][nx] = dp[r][c] + 1;
		}
	}
	return dp[r][c];
}

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);
	
	std::vector<iPair> pos_vec;

	cin >> n;
	board.resize(n, std::vector<int>(n, 0));
	dp.resize(n, std::vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			dp[i][j] = 1;
			pos_vec.push_back(make_pair(board[i][j], i*n + j));
		}			
	}

	// 가중치를 기준으로 점 정렬
	std::sort(pos_vec.begin(), pos_vec.end(), [](const iPair &a, const iPair &b) {
		return a.first < b.first;
	});

	// 가중치 순서대로 좌우상하 dp + dfs
	for (auto it : pos_vec) {
		int r = it.second / n;
		int c = it.second % n;
		dfs(r, c);
	}

	// 최다 오래 살수있는 일 수 Check
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans = std::max(ans, dp[i][j]);
	cout << ans << "\n";
	return 0;
}