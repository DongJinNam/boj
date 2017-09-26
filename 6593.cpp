#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <string.h>

typedef std::pair<int, int> iPair;

using namespace std;

struct three_dim {
	int h; // 높이
	int r; // 행
	int c; // 열
};

int inf = 1000000000;

int dp[31][31][31]; // 층, 행, 열
int yy[4] = { 0,0,-1,1 };
int xx[4] = { 1,-1,0,0 };
int hh[2] = { 1, -1 };

int main() {
	std::ios::sync_with_stdio(false);
	int l, r, c;
	int i, j, k;
	while (1) {
		std::vector<string> str_vec[31];

		cin >> l >> r >> c;

		if (l == 0 && r == 0 && c == 0) break; // 종료		

		int pos_h, pos_r, pos_c; // 시작점의 높이, 행, 열
		int end_h, end_r, end_c; // 끝점의 높이, 행, 열
		for (i = 1; i <= l; i++) {
			for (j = 0; j < r; j++) {
				string s;
				cin >> s;
				str_vec[i].push_back(s);
				for (k = 0; k < s.length(); k++) {
					if (s[k] == 'S') {
						pos_h = i;
						pos_r = j;
						pos_c = k;
					}
					if (s[k] == 'E') {
						end_h = i;
						end_r = j;
						end_c = k;
					}
					dp[i][j][k] = inf;
				}				
			}
			//cout << "\n";
		}

		std::queue<std::pair<int,three_dim>> bfs;
		three_dim tmp;
		dp[pos_h][pos_r][pos_c] = 0;
		tmp.h = pos_h;
		tmp.r = pos_r;
		tmp.c = pos_c;
		bfs.push(make_pair(0, tmp));
		while (!bfs.empty()) {
			int add = -bfs.front().first;
			three_dim front_dim = bfs.front().second;
			bfs.pop();

			if (front_dim.h == end_h && front_dim.r == end_r && front_dim.c == end_c) break;
			if (add > dp[front_dim.h][front_dim.r][front_dim.c]) continue;

			// 위,아래,좌,우
			for (i = 0; i < 4; i++) {
				int nr = front_dim.r + yy[i];
				int nc = front_dim.c + xx[i];
				if (nr >= 0 && nr < r && nc >= 0 && nc < c && (str_vec[front_dim.h][nr][nc] == '.' || str_vec[front_dim.h][nr][nc] == 'E') && (add + 1) < dp[front_dim.h][nr][nc]) {
					three_dim in;
					dp[front_dim.h][nr][nc] = add + 1;
					in.h = front_dim.h;
					in.r = nr;
					in.c = nc;
					bfs.push(make_pair(-dp[in.h][in.r][in.c], in));
				}
			}
			// 상하
			for (i = 0; i < 2; i++) {
				int nh = front_dim.h + hh[i];
				if (nh > 0 && nh <= l && (str_vec[nh][front_dim.r][front_dim.c] == '.' || str_vec[nh][front_dim.r][front_dim.c] == 'E') && (add + 1) < dp[nh][front_dim.r][front_dim.c]) {
					three_dim in;
					dp[nh][front_dim.r][front_dim.c] = add + 1;
					in.h = nh;
					in.r = front_dim.r;
					in.c = front_dim.c;
					bfs.push(make_pair(-dp[in.h][in.r][in.c], in));
				}
			}
		}

		if (dp[end_h][end_r][end_c] == inf) cout << "Trapped!\n";
		else cout << "Escaped in " << dp[end_h][end_r][end_c] << " minute(s).\n";
	}

	return 0;
}