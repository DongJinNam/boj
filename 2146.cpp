#include <iostream>
#include <queue>

#define MAX 1000000001

typedef std::pair<int, int> iPair;

using namespace std;

int xx[4] = { 1,-1,0,0 };
int yy[4] = { 0,0,1,-1 };
int n;
int area_count = 0;
int min_val = 1000000001;
std::vector<std::vector<int>> dp;
std::vector<std::vector<int>> area;

bool check(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < n;
}

void bfs(int row, int col) {
	std::queue<iPair> bfs;
	bfs.push(make_pair(row, col));

	while (!bfs.empty()) {
		iPair front = bfs.front();
		int r = front.first;
		int c = front.second;
		bfs.pop();

		if (area[r][c] > 0) continue;
		area[r][c] = area_count;

		for (int i = 0; i < 4; i++) {
			int ny = r + yy[i];
			int nx = c + xx[i];
			if (check(ny, nx) && dp[ny][nx] > 0 && area[ny][nx] < 0) {
				bfs.push(make_pair(ny, nx));
			}
		}
	}
}

int find_bfs(int row, int col) {
	std::queue<iPair> bfs;
	std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
	int ans = MAX;
	bool bFind = false;
	bfs.push(make_pair(0,row*n+col));

	while (!bFind && !bfs.empty()) {
		iPair front = bfs.front();
		int cost = front.first;
		int r = front.second / n;
		int c = front.second % n;
		bfs.pop();

		if (visited[r][c] == true) continue;
		visited[r][c] = true;

		for (int i = 0; i < 4; i++) {
			int ny = r + yy[i];
			int nx = c + xx[i];
			if (check(ny, nx) && visited[ny][nx] == false && area[ny][nx] != area[row][col]) {
				if (area[ny][nx] > 0 && area[ny][nx] != area[row][col]) {
					ans = cost;
					bFind = true;
					break;
				}
				else {
					bfs.push(make_pair(cost+1, ny*n+nx));
				}				
			}
		}
	}
	return ans;
}

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> n;

	dp.resize(n, std::vector<int>(n, 0));
	area.resize(n, std::vector<int>(n, -1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dp[i][j];
		}
	}

	// area 설정
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] > 0 && area[i][j] < 0) {
				area_count++;
				bfs(i, j);
			}
		}
	}

	// area 설정
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] > 0 && area[i][j] > 0) {
				int ans = find_bfs(i, j);
				min_val = ans < min_val ? ans : min_val;
			}
		}
	}
	cout << min_val << "\n";
	return 0;
}