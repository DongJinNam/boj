#include <stdio.h>
#include <vector>
#include <algorithm>

struct Cell {
	int r, c, v;
};

int n, m;
int a[500][500];
int d[500][500];
int yy[4] = { 0,0,-1,1 };
int xx[4] = { 1,-1,0,0 };

bool cmp(const Cell &u, const Cell &v) {
	return u.v < v.v;
}

int main() {

	int i, j;

	scanf("%d %d", &m, &n);
	std::vector<Cell> vec;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			vec.push_back({ i,j,a[i][j] });
		}
	}
	
	std::sort(vec.begin(), vec.end(), cmp);
	d[m - 1][n - 1] = 1;
	for (i = 0; i < vec.size(); i++) {
		int y = vec[i].r;
		int x = vec[i].c;
		for (j = 0; j < 4; j++) {
			int ny = y + yy[j];
			int nx = x + xx[j];
			if (0 <= ny && ny < m && 0 <= nx && nx < n) {
				if (a[ny][nx] < a[y][x]) {
					d[y][x] += d[ny][nx];
				}
			}
		}
	}
	printf("%d\n", d[0][0]);
	return 0;
}