#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef std::pair<int, int> iPair;

int board[8][8] = { 0 };
int yy[4] = { 0,0,1,-1 };
int xx[4] = { 1,-1,0,0 };
int n, m;
std::vector<iPair> pos_vec;
std::vector<iPair> virus_vec;

bool check(int ny, int nx, int r, int c) {
	return ny >= 0 && ny < r && nx >= 0 && nx < c;
}

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) pos_vec.push_back(make_pair(i, j));
			if (board[i][j] == 2) virus_vec.push_back(make_pair(i, j));
		}
	}
	for (int i = 0; i < pos_vec.size(); i++) {
		iPair f = pos_vec[i];
		for (int j = i + 1; j < pos_vec.size(); j++) {
			iPair s = pos_vec[j];
			for (int k = j + 1; k < pos_vec.size(); k++) {
				iPair t = pos_vec[k];
				board[f.first][f.second] = 1;
				board[s.first][s.second] = 1;
				board[t.first][t.second] = 1;

				// bfs;
				std::queue<iPair> q;
				std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
				for (iPair pos : virus_vec) {
					q.push(pos);
					visited[pos.first][pos.second] = true;
				}
				int v_count = 0;
				while (!q.empty()) {
					iPair front = q.front();
					q.pop();
					for (int d = 0; d < 4; d++) {
						int ny = front.first + yy[d];
						int nx = front.second + xx[d];
						if (check(ny, nx, n, m) && board[ny][nx] == 0 && !visited[ny][nx]) {
							q.push(make_pair(ny, nx));
							visited[ny][nx] = true;
							v_count++;
						}
					}
				}
				ans = pos_vec.size() - 3 - v_count > ans ? pos_vec.size() - 3 - v_count : ans;
				board[f.first][f.second] = 0;
				board[s.first][s.second] = 0;
				board[t.first][t.second] = 0;
			}
		}
	}
	cout << ans << "\n";


	return 0;
}