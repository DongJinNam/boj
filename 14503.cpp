#include <iostream>
#include <queue>

typedef std::pair<int, int> iPair;

using namespace std;

bool check[51][51]; // �ش� ������ �湮�ߴ��� ǥ���ϴ� �迭
int board[51][51] = { 0 }; // �ش� ������ �湮 ������ ������ (0), ������(1)
int dir_x[4] = {0,1,0,-1}; // 0 : ��, 1 : ��, 2 : ��, 3 : ��
int dir_y[4] = {-1,0,1,0}; // 0 : ��, 1 : ��, 2 : ��, 3 : ��

// �Ű����� row, col�� ���� �ȿ� �ִ��� �Ǻ��ϴ� �Լ�
bool isArea(int row, int col, int ySize, int xSize) {
	return row >= 0 && row < ySize && col >= 0 && col < xSize;
}

int main() {
	std::ios::sync_with_stdio(false);
	int N, M; // ��, ��
	int row, col, dir; // ���� ��, ���� ��, ���� ����
	int count = 0; // û���� ������ ����

	cin >> N >> M;
	cin >> row >> col >> dir;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	// queue�� ����� bfs
	std::queue<iPair> bfs;	
	bfs.push(iPair(row, col));
	check[row][col] = true;
	count++;
	while (!bfs.empty()) {
		iPair pos = bfs.front(); // ���� ����
		bool bCan = false; // �������� �� �� ������ �̵� �����ϸ� true, �׷��� ������ false
		bfs.pop();
		for (int i = 0; i < 4; i++) {
			dir--; // ���� ���� switch
			if (dir < 0) dir = 3;
			int n_y = pos.first + dir_y[dir];
			int n_x = pos.second + dir_x[dir];
			// �̵� �����ϰ�, �ش� ��ǥ���� �湮 ������ ���� ���.
			if (isArea(n_y, n_x, N, M) && board[n_y][n_x] == 0 && check[n_y][n_x] == false) {
				bCan = true;
				bfs.push(iPair(n_y, n_x));
				check[n_y][n_x] = true;
				count++;
				break;
			}
		}
		// �������� �̵��� �õ��Ͽ����� ������ �õ��ؾ� �ϴ� ���
		if (!bCan) {
			int n_y = pos.first + dir_y[(dir + 2) % 4];
			int n_x = pos.second + dir_x[(dir + 2) % 4];
			if (board[n_y][n_x] == 1) { // ���� �õ��� �Ұ����� ��.
				break; // �۵� ����.
			}
			// ���� �õ��� �����ϸ� ������ ������ ��ġ�� queue�� �ִ´�.
			bfs.push(iPair(n_y, n_x));
		}
	}	
	cout << count << "\n";
	return 0;
}