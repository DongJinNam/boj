#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef std::pair<int, int> iPair;

const int maxSize = 1501;
std::vector<std::vector<iPair>> from(maxSize, std::vector<iPair>(maxSize, make_pair(0,0)));
std::vector<std::vector<int>> board(maxSize, std::vector<int>(maxSize, -1));
std::vector<std::vector<int>> dp(maxSize, std::vector<int>(maxSize, -1));

bool check(int i, int j, int size) {
	return i >= 0 && i < size && j >= 0 && j < size;
}

int getTotal(int n, int row, int col) {	
	// dp 배열 초기화
	std::queue<iPair> bfs;
	bfs.push(iPair(0, 0));
	dp[0][0] = board[0][0];
	int total = 0;
	while (!bfs.empty()) {
		iPair front = bfs.front();
		bfs.pop();

		int cur_x = front.second, cur_y = front.first;
		int n1_x, n1_y, n2_x, n2_y;
		n1_x = front.second + 1;
		n1_y = front.first;
		n2_x = front.second;
		n2_y = front.first + 1;

		if (check(n1_y, n1_x, n) && dp[cur_y][cur_x] + board[n1_y][n1_x] > dp[n1_y][n1_x]) {
			bfs.push(iPair(n1_y, n1_x));
			dp[n1_y][n1_x] = dp[cur_y][cur_x] + board[n1_y][n1_x];
			from[n1_y][n1_x] = make_pair(cur_y, cur_x);
		}
		if (check(n2_y, n2_x, n) && dp[cur_y][cur_x] + board[n2_y][n2_x] > dp[n2_y][n2_x]) {
			bfs.push(iPair(n2_y, n2_x));
			dp[n2_y][n2_x] = dp[cur_y][cur_x] + board[n2_y][n2_x];
			from[n2_y][n2_x] = make_pair(cur_y, cur_x);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			total += dp[i][j];
		}
	}
	return total;
}

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	int total = getTotal(n,0,0);
	cout << total << "\n";
	for (int i = 0; i < n; i++) {
		char in;
		int row, col;
		int result;
		while ((in = getchar()) && (in != 'U' && in != 'D')) {}
		cin >> row >> col;
		if (in == 'U') 
			board[row - 1][col - 1]++;
		else
			board[row - 1][col - 1]--;
		result = getTotal(n,row-1,col-1);
		cout << result << "\n";
	}
	return 0;
}