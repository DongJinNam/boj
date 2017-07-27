#include <stdio.h>
#include <algorithm>
#include <deque>

using namespace std;

int board[101][101];
int dp[101][101];
bool check[101][101];
int N, M; // 세로 크기, 가로 크기
int yyy[4] = { 0,0,1,-1 };
int xxx[4] = { 1,-1,0,0 };

typedef std::pair<int, int> iPair;

bool check_pos(int y, int x) {
	return 0 < y && y <= N && 0 < x && x <= M;
}

int main() {
	scanf("%d %d", &M, &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &board[i][j]);
		}
	}

	std::deque<iPair> q;

	q.push_back({ 1,1 });
	check[1][1] = true;

	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			if (check_pos(yy + yyy[i], xx + xxx[i])) {
				int new_y = yy + yyy[i];
				int new_x = xx + xxx[i];
				if (check[new_y][new_x] == false) {
					check[new_y][new_x] = true;
					if (board[new_y][new_x] == 0) {						
						dp[new_y][new_x] = dp[yy][xx];
						q.push_front({ new_y,new_x });
					}
					else {						
						dp[new_y][new_x] = dp[yy][xx] + 1;
						q.push_back({ new_y,new_x });
					}
				}
			}
		}
	}
	printf("%d\n", dp[N][M]);
	return 0;
}