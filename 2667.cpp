#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef std::pair<int, int> iPair;

int board[26][26];
int visit[26][26];
int N;
int yy[4] = { 0,0,-1,1 };
int xx[4] = { 1,-1,0,0 };

bool check(int y, int x) {
	return y > 0 && y <= N && x > 0 && x <= N;
}

// bfs를 활용한 단지번호붙이기
int bfs(int y, int x, int count) {

	int rtn = 0;

	std::queue<iPair> bfs;
	bfs.push(std::make_pair(y,x));

	while (!bfs.empty()) {

		iPair point = bfs.front();
		bfs.pop();

		if (visit[point.first][point.second] > 0) continue;
		visit[point.first][point.second] = count;
		rtn++;
		for (int i = 0; i < 4; i++) {
			if (check(point.first + yy[i],point.second + xx[i])) {
				int y = point.first + yy[i];
				int x = point.second + xx[i];
				if (board[y][x] == 1 && visit[y][x] == 0) {
					bfs.push(make_pair(y, x));
				}
			}
		}
	}
	return rtn;
}

int main() {

	int cnt = 0;
	int i, j, k;
	std::vector<int> cnt_vec;
	
	scanf("%d", &N);
	for (i = 1; i <= N; i++) 
		for (j = 1; j <= N; j++) 
			scanf("%1d", &board[i][j]);		
	
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (board[i][j] == 1 && visit[i][j] == 0) {
				int rtn = bfs(i,j,++cnt);
				cnt_vec.push_back(rtn);
			}
		}
	}

	std::sort(cnt_vec.begin(), cnt_vec.end());

	printf("%d\n", cnt_vec.size());
	for (auto at : cnt_vec)
		printf("%d\n", at);
	return 0;
}