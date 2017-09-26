#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef std::pair<int, int> iPair;

bool is_trash_dp[101][101];

int yy[4] = { 0,0,-1,1 };
int xx[4] = { 1,-1,0,0 };
int dp[101][101]; // 영역 표시

int main() {

	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	int i, j, row, col;
	std::vector<iPair> trash_vec;

	for (i = 0; i < k; i++) {
		scanf("%d %d", &row, &col);
		is_trash_dp[row][col] = true;
		trash_vec.push_back(make_pair(row, col));
	}

	int g_cnt = 0;
	int max = 0; // 한 그룹당 최대 쓰레기 개수
	int g_size = 0; // 그룹 당 쓰레기 개수
	for (i = 0; i < trash_vec.size(); i++) {
		iPair pos = trash_vec[i];
		if (dp[pos.first][pos.second] == 0) {
			g_cnt++;
			g_size = 0;
			std::queue<iPair> bfs;
			dp[pos.first][pos.second] = g_cnt;
			bfs.push(make_pair(pos.first, pos.second));
			while (!bfs.empty()) {
				iPair front = bfs.front();
				bfs.pop();
				g_size++;
				for (j = 0; j < 4; j++) {
					int ny = front.first + yy[j];
					int nx = front.second + xx[j];
					if (ny > 0 && ny <= n && nx > 0 && nx <= m && is_trash_dp[ny][nx] && dp[ny][nx] == 0) {
						dp[ny][nx] = g_cnt;
						bfs.push(make_pair(ny, nx));
					}
				}
			}
			max = g_size > max ? g_size : max;
		}		
	}
	printf("%d", max);
	return 0;
}