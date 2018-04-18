#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define MAX_VAL 1000000001

typedef std::pair<int, int> iPair;

using namespace std;

int n, m;
int board[50][50] = { 0 };
int sum[100][13] = { 0 };
int yy[4] = { 0,0,1,-1 };
int xx[4] = { 1,-1,0,0 };
bool bReverse = false;
int depth = 0;
std::vector<iPair> ch_vec;
std::vector<iPair> me_vec;

bool check(int ny, int nx, int y_l, int x_l) {
	return ny >= 0 && ny < y_l && nx >= 0 && nx < x_l;
}

int go(int count, int start) {
	if (count == depth) { // count값이 목표에 도달한 경우
		int ans = 0;		
		for (int i = 0; i < me_vec.size(); i++) {
			int val = MAX_VAL;
			for (int j = 0; j < ch_vec.size(); j++) {
				int r = ch_vec[j].first;
				int c = ch_vec[j].second;
				if (board[r][c] == 2) {
					val = std::min(val, sum[i][j]);
				}
			}
			ans += val;
		}
		return ans;
	}
	int ans = MAX_VAL;
	for (int i = start; i < ch_vec.size(); i++) {
		int r = ch_vec[i].first;
		int c = ch_vec[i].second;

		if (bReverse) board[r][c] = 2;
		else board[r][c] = 0;

		ans = std::min(ans, go(count + 1, i + 1));

		if (bReverse) board[r][c] = 0;
		else board[r][c] = 2;
	}
	return ans;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] == 2) ch_vec.push_back(make_pair(i, j));
			else if (board[i][j] == 1) me_vec.push_back(make_pair(i, j));
		}		
	}
	// 우선 전체 1인 점에 대해서 모든 2에 도달할 때까지 bfs를 돌린다.
	for (int i = 0; i < me_vec.size(); i++) {
		int r = me_vec[i].first;
		int c = me_vec[i].second;
		std::queue<iPair> q;
		std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
		q.push(make_pair(0, r*n + c));
		visited[r][c] = true;
		while (!q.empty()) {
			int cost = q.front().first;
			int cur_r = q.front().second / n;
			int cur_c = q.front().second % n;
			q.pop();
			if (board[cur_r][cur_c] == 2) {
				for (int j = 0; j < ch_vec.size(); j++) {
					auto p = ch_vec[j];
					if (p.first == cur_r && p.second == cur_c) {
						sum[i][j] = cost; // i번째 1이 j번째 2를 방문했을 때 최소 cost
						break;
					}
				}
			}
			for (int j = 0; j < 4; j++) {
				int ny = cur_r + yy[j];
				int nx = cur_c + xx[j];
				if (check(ny, nx, n, n) && !visited[ny][nx]) {
					visited[ny][nx] = true;
					q.push(make_pair(cost + 1, ny*n + nx));
				}
			}
		}
	}

	// n개에서 c개를 뽑는 경우의 수. 다만 n - c > c인 경우, 원래 2인 점을 모두 0으로 바꾸고 조합 과정을 진행한다.
	if (ch_vec.size() - m > m) {
		bReverse = true;
		depth = m;
		for (int i = 0; i < ch_vec.size(); i++) {
			int r = ch_vec[i].first;
			int c = ch_vec[i].second;
			board[r][c] = 0;
		}
	}
	else {
		depth = ch_vec.size() - m;
	}
	printf("%d\n", go(0, 0));
	return 0;
}