#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef std::pair<int, int> iPair;

bool check[101][101];
int N, M, K;
int yy[4] = { 0,0,-1,1 };
int xx[4] = { 1,-1,0,0 };

bool pos_check(int y, int x) {
	return y >= 0 && y < M && x >= 0 && x < N;
}

int main() {	
	int i, j, a;
	int x1, y1, x2, y2;
	std::vector<int> area_vec;
	scanf("%d %d %d", &M, &N, &K);

	for (i = 0; i < K; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (j = y1; j < y2; j++) {
			for (a = x1; a < x2; a++) {
				check[j][a] = true;
			}
		}
	}
	
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			if (check[i][j] == false) {

				std::queue<iPair> bfs;
				bfs.push(make_pair(i, j));
				int visitCount = 0;
				while (!bfs.empty()) {
					iPair front = bfs.front();
					bfs.pop();

					if (check[front.first][front.second]) continue;

					check[front.first][front.second] = true;
					visitCount++;
					for (a = 0; a < 4; a++) {
						int n_y = front.first + yy[a];
						int n_x = front.second + xx[a];
						if (pos_check(n_y, n_x)) {
							bfs.push(make_pair(n_y, n_x));
						}
					}
				}
				area_vec.push_back(visitCount);
			}
		}
	}
	std::sort(area_vec.begin(), area_vec.end());
	printf("%d\n", area_vec.size());
	for (i = 0; i < area_vec.size(); i++) {
		printf("%d ", area_vec[i]);
	}
	return 0;
}