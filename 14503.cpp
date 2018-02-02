#include <iostream>
#include <queue>

typedef std::pair<int, int> iPair;

using namespace std;

bool check[51][51]; // 해당 지점을 방문했는지 표시하는 배열
int board[51][51] = { 0 }; // 해당 지점이 방문 가능한 점인지 (0), 벽인지(1)
int dir_x[4] = {0,1,0,-1}; // 0 : 북, 1 : 동, 2 : 남, 3 : 서
int dir_y[4] = {-1,0,1,0}; // 0 : 북, 1 : 동, 2 : 남, 3 : 서

// 매개변수 row, col이 영역 안에 있는지 판별하는 함수
bool isArea(int row, int col, int ySize, int xSize) {
	return row >= 0 && row < ySize && col >= 0 && col < xSize;
}

int main() {
	std::ios::sync_with_stdio(false);
	int N, M; // 행, 열
	int row, col, dir; // 현재 행, 현재 열, 현재 방향
	int count = 0; // 청소한 점들의 개수

	cin >> N >> M;
	cin >> row >> col >> dir;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	// queue를 사용한 bfs
	std::queue<iPair> bfs;	
	bfs.push(iPair(row, col));
	check[row][col] = true;
	count++;
	while (!bfs.empty()) {
		iPair pos = bfs.front(); // 현재 지점
		bool bCan = false; // 동서남북 중 한 점으로 이동 가능하면 true, 그렇지 않으면 false
		bfs.pop();
		for (int i = 0; i < 4; i++) {
			dir--; // 왼쪽 방향 switch
			if (dir < 0) dir = 3;
			int n_y = pos.first + dir_y[dir];
			int n_x = pos.second + dir_x[dir];
			// 이동 가능하고, 해당 목표점이 방문 가능한 점인 경우.
			if (isArea(n_y, n_x, N, M) && board[n_y][n_x] == 0 && check[n_y][n_x] == false) {
				bCan = true;
				bfs.push(iPair(n_y, n_x));
				check[n_y][n_x] = true;
				count++;
				break;
			}
		}
		// 동서남북 이동을 시도하였으나 후진을 시도해야 하는 경우
		if (!bCan) {
			int n_y = pos.first + dir_y[(dir + 2) % 4];
			int n_x = pos.second + dir_x[(dir + 2) % 4];
			if (board[n_y][n_x] == 1) { // 후진 시도도 불가능할 시.
				break; // 작동 중지.
			}
			// 후진 시도가 가능하면 후진할 지점의 위치를 queue에 넣는다.
			bfs.push(iPair(n_y, n_x));
		}
	}	
	cout << count << "\n";
	return 0;
}