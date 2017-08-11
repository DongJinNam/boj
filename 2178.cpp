#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef std::pair<int, int> iPair;

short check[101][101];
bool board[101][101];
int yy[4] = { 0,0,1,-1 };
int xx[4] = { 1,-1,0,0};
int inf = 30001;
int N;
int M;
bool pos_check(int y, int x) {
	return y > 0 && y <= N && x > 0 && x <= M;
}

int main() {
	std::ios::sync_with_stdio(false);
	// 메모리 초과 주의 (bfs)
	int i, j, from, to, ans = 0;
	std::queue<iPair> bfs;

	cin >> N >> M;

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			char ch;
			cin >> ch;
			if (ch == '1') board[i][j] = true;
			else board[i][j] = false;
			check[i][j] = inf;
		}
	}
	check[1][1] = 1;
	bfs.push(make_pair(1, 1));
	while (!bfs.empty()) {
		int y = bfs.front().first;
		int x = bfs.front().second;
		bfs.pop();
		for (i = 0; i < 4; i++) {
			int n_y = y + yy[i];
			int n_x = x + xx[i];
			if (pos_check(n_y, n_x) && board[n_y][n_x] == true) {							
				if (check[y][x] + 1 < check[n_y][n_x]) {
					bfs.push(make_pair(n_y, n_x));
					check[n_y][n_x] = check[y][x] + 1;
				}
			}
		}

	}
	cout << check[N][M] << endl;
	return 0;
}