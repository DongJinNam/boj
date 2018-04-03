#include <stdio.h>
#include <queue>
#include <algorithm>

#define MAX 1001

typedef std::pair<int, int> iPair;

using namespace std;

char str[MAX][MAX];
int yy[4] = { 0,0,1,-1 };
int xx[4] = { 1,-1,0,0 };

bool areaCheck(int ny, int nx, int row, int col) {
	return ny >= 0 && ny < row && nx >= 0 && nx < col;
}

int main() {
	int h, w, n;
	int time = 0;
	int beg_i = -1, beg_j = -1;
	int i, j;
	scanf("%d %d %d\n", &h, &w, &n);
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			char ch;
			while (scanf("%c", &ch) && ch == '\n');
			str[i][j] = ch;
			if (str[i][j] == 'S') {
				beg_i = i;
				beg_j = j;
			}
		}
	}
	for (i = 1; i <= n; i++) {
		std::queue<iPair> bfs;
		std::vector<std::vector<bool>> visited(h, std::vector<bool>(w, false));
		bfs.push(iPair(beg_i*w+beg_j, time));
		visited[beg_i][beg_j] = true;
		bool bFind = false;
		while (!bFind && !bfs.empty()) {
			iPair front = bfs.front();
			int row = front.first / w;
			int col = front.first % w;
			bfs.pop();
			for (j = 0; j < 4; j++) {
				int ny = row + yy[j];
				int nx = col + xx[j];
				if (areaCheck(ny, nx, h, w) && !visited[ny][nx] && str[ny][nx] != 'X') {
					if (str[ny][nx] >= '1' && str[ny][nx] <= '9' && i == (int)str[ny][nx] - '0') {
						bFind = true;
						beg_i = ny;
						beg_j = nx;
						time = front.second + 1;
						break;
					}
					else {
						bfs.push(iPair(ny*w + nx, front.second + 1));
						visited[ny][nx] = true;
					}
				}
			}
		}
	}
	printf("%d\n", time);
	return 0;
}