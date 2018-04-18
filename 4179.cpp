#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

#define MAX_VAL 1000000000

typedef std::pair<int, int> iPair;

using namespace std;

char str[1001][1001];
int dp[1001][1001] = { 0 };
int r, c;
std::queue<iPair> m_q;
std::queue<iPair> f_q;
int yy[4] = { 0,0,1,-1 };
int xx[4] = { 1,-1,0,0 };

bool check(int ny, int nx, int ySize, int xSize) {
	return ny >= 0 && ny < ySize && nx >= 0 && nx < xSize;
}

int main() {
	scanf("%d %d ", &r, &c);
	for (int i = 0; i < r; i++)
		scanf("%s", str[i]);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			dp[i][j] = MAX_VAL;
			if (str[i][j] == 'J') {
				m_q.push(make_pair(0, i*c + j));
			}
			if (str[i][j] == 'F') {
				f_q.push(make_pair(0, i*c + j));
				dp[i][j] = 0;
			}
		}
	}

	int ans = -1;
	while (!m_q.empty() && ans == -1) {
		int fq = f_q.size();
		int mq = m_q.size();
		for (int i = 0; i < fq; i++) {
			int f_r = f_q.front().second / c;
			int f_c = f_q.front().second % c;
			int f_t = f_q.front().first;
			f_q.pop();
			for (int j = 0; j < 4; j++) {
				int ny = f_r + yy[j];
				int nx = f_c + xx[j];
				if (check(ny, nx, r, c) && str[ny][nx] == '.' && f_t + 1 < dp[ny][nx]) {
					dp[ny][nx] = f_t + 1;
					f_q.push(make_pair(f_t + 1, ny*c + nx));
				}
			}
		}
		for (int i = 0; i < mq; i++) {
			int time = m_q.front().first;
			int row = m_q.front().second / c;
			int col = m_q.front().second % c;
			m_q.pop();
			for (int j = 0; j < 4; j++) {
				int ny = row + yy[j];
				int nx = col + xx[j];
				if (!check(ny, nx, r, c)) {
					ans = time + 1;
					break;
				}
				if (check(ny, nx, r, c) && str[ny][nx] == '.' && time + 1 < dp[ny][nx]) {
					m_q.push(make_pair(time + 1, ny*c + nx));
				}
			}
		}
	}
	if (ans == -1)
		printf("IMPOSSIBLE\n");
	else
		printf("%d\n",ans);
	return 0;
}