#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct pos_state {
	int dep;
	int y;
	int x;
};

int board[1001][1001];
int dp[1001][1001];
int yy[4] = { 0,0,1,-1 };
int xx[4] = { 1,-1,0, 0 };
int inf = 1000000000;
int m, n;

bool pos_check(int i, int j) {
	return i > 0 && i <= n && j > 0 && j <= m && board[i][j] == 0; // 위치 조건 + 아직 익지 않은 지역
}
// 토마토 문제
int main() {
	std::ios::sync_with_stdio(false);
	int ans = 0, i, j;
	
	int tomato_cnt = 0, except_cnt = 0;
	std::queue<pos_state> bfs;

	cin >> m >> n;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cin >> board[i][j];

			pos_state temp;
			if (board[i][j] == 1) {
				temp.dep = 0;
				temp.y = i;
				temp.x = j;
				bfs.push(temp);
			}
			else {
				if (board[i][j] == -1) except_cnt++;				
			}
			dp[i][j] = inf;
		}
	}

	// 시작 전 토마토가 모두 익은 경우.
	if (m*n - except_cnt == tomato_cnt) {
		cout << ans;
		return 0;
	}

	int max = 0;
	while (!bfs.empty()) {
		pos_state first = bfs.front();
		bfs.pop();

		if (first.dep > dp[first.y][first.x]) continue;
		
		dp[first.y][first.x] = first.dep;
		max = dp[first.y][first.x] > max ? dp[first.y][first.x] : max;
		tomato_cnt++; // 익은 토마토 개수 세기

		for (i = 0; i < 4; i++) {
			if (pos_check(first.y + yy[i], first.x + xx[i]) && dp[first.y + yy[i]][first.x + xx[i]]  > first.dep + 1) {
				pos_state temp;
				temp.dep = first.dep + 1;
				temp.y = first.y + yy[i];
				temp.x = first.x + xx[i];
				dp[temp.y][temp.x] = temp.dep;
				bfs.push(temp);
			}
		}
	}

	if (m*n - except_cnt != tomato_cnt) {
		ans = -1; // 모든 가능 영역에서 토마토가 익지 않은 경우
	}
	else {
		ans = max; // 모든 가능 영역에서 토마토가 익은 경우
	}
	cout << ans;	
	return 0;
}