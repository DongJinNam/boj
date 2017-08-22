#include <iostream>
#include <string>

using namespace std;

char board[21][21];
bool check[26]; // alphabet 방문 배열
int yy[4] = { 0,0,-1,1 };
int xx[4] = { 1,-1,0,0 };
int r, c;

bool pos_check(int y, int x) {
	return y >= 0 && y < r && x >= 0 && x < c;
}

int dfs(int dis, int y, int x) {	
	int ans = 0;
	int i, j;
	if (check[board[y][x] - 'A'] == true) { // 이미 방문한 문자인 경우, distance를 return
		return dis;
	}
	check[board[y][x] - 'A'] = true;
	for (i = 0; i < 4; i++) {
		int ny = y + yy[i];
		int nx = x + xx[i];
		if (pos_check(ny, nx)) {			
			int res = dfs(dis + 1, ny, nx);
			ans = res > ans ? res : ans;			
		}
	}
	check[board[y][x] - 'A'] = false;
	return ans;
}

int main() {
	std::ios::sync_with_stdio(false);	
	int i, j, ans = 0;
	cin >> r >> c;
	for (i = 0; i < r; i++) {
		string in;
		cin >> in;
		for (j = 0; j < c; j++) {
			board[i][j] = in[j];
		}
	}
	ans = dfs(0, 0, 0);
	cout << ans;
	return 0;
}