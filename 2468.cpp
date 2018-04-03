#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 101

typedef std::pair<int, int> iPair;

using namespace std;

int arr[MAX][MAX] = { 0 };
int xx[4] = { 1,-1,0,0 };
int yy[4] = { 0,0,1,-1 };

bool check(int ny, int nx, int row, int col) {
	return ny >= 0 && ny < row && nx >= 0 && nx < col;
}

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);
	int n;
	int max = 0; // 많은 영역 area
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	for (int h = 0; h < MAX; h++) {
		std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
		int area = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j] && arr[i][j] > h) {
					std::queue<iPair> bfs;
					bfs.push(iPair(i, j));
					visited[i][j] = true;
					while (!bfs.empty()) {
						iPair front = bfs.front();
						bfs.pop();
						for (int k = 0; k < 4; k++) {
							int ny = front.first + yy[k];
							int nx = front.second + xx[k];
							if (check(ny, nx, n, n) && !visited[ny][nx] && arr[ny][nx] > h) {
								bfs.push(iPair(ny, nx));
								visited[ny][nx] = true;
							}
						}
					}
					area++;
				}
			}
		}
		max = area > max ? area : max;
	}
	cout << max << "\n";
	return 0;
}