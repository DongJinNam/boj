#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<std::vector<int>> board;
int max = 1;
int n;

// prev 이전 단계 (0 : 좌, 1 : 우, 2 : 상, 3 : 하)
int recur(int stage, std::vector<std::vector<int>> &dp) {
	if (stage >= 5) {
		int ans = 0;
		for (int i = 0; i < dp.size(); i++) {
			for (int j = 0; j < dp.size(); j++) {
				ans = std::max(ans, dp[i][j]);
			}
		}
		return ans;
	}

	int ans = 0;
	for (int k = 0; k < 4; k++) {
		std::vector<std::vector<int>> copy_vec(n, std::vector<int>(n, 0));
		if (k == 0) {
			for (int i = 0; i < n; i++) {
				std::vector<int> line;
				std::vector<bool> visited;
				for (int j = n - 1; j >= 0; j--) {
					if (dp[i][j] != 0) {
						if (line.size() && visited.size() && line.back() == dp[i][j] && visited[visited.size() - 1] == false) {
							line[line.size() - 1] <<= 1;
							visited[visited.size() - 1] = true;
						}
						else {
							line.push_back(dp[i][j]);
							visited.push_back(false);
						}
					}
				}
				for (int j = 0; j < line.size(); j++) {
					copy_vec[i][n - line.size() + j] = line[line.size() - 1 - j];
				}
			}
		}
		else if (k == 1) {
			for (int i = 0; i < n; i++) {
				std::vector<int> line;
				std::vector<bool> visited;
				for (int j = 0; j < n; j++) {
					if (dp[i][j] != 0) {
						if (line.size() && visited.size() && line.back() == dp[i][j] && visited[visited.size() - 1] == false) {
							line[line.size() - 1] <<= 1;
							visited[visited.size() - 1] = true;
						}
						else {
							line.push_back(dp[i][j]);
							visited.push_back(false);
						}
					}
				}
				for (int j = 0; j < line.size(); j++)
					copy_vec[i][line.size() - 1 - j] = line[line.size() - 1 - j];
			}
		}
		else if (k == 2) {
			for (int j = 0; j < n; j++) {
				std::vector<int> line;
				std::vector<bool> visited;
				for (int i = n - 1; i >= 0; i--) {
					if (dp[i][j] != 0) {
						if (line.size() && visited.size() && line.back() == dp[i][j] && visited[visited.size() - 1] == false) {
							line[line.size() - 1] <<= 1;
							visited[visited.size() - 1] = true;
						}
						else {
							line.push_back(dp[i][j]);
							visited.push_back(false);
						}
					}
				}
				for (int i = 0; i < line.size(); i++)
					copy_vec[n - line.size() + i][j] = line[line.size() - 1 - i];
			}
		}
		else {
			for (int j = 0; j < n; j++) {
				std::vector<int> line;
				std::vector<bool> visited;
				for (int i = 0; i < n; i++) {
					if (dp[i][j] != 0) {
						if (line.size() && visited.size() && line.back() == dp[i][j] && visited[visited.size() - 1] == false) {
							line[line.size() - 1] <<= 1;
							visited[visited.size() - 1] = true;
						}
						else {
							line.push_back(dp[i][j]);
							visited.push_back(false);
						}
					}
				}
				for (int i = 0; i < line.size(); i++)
					copy_vec[line.size() - 1 - i][j] = line[line.size() - 1 - i];
			}
		}
		ans = std::max(ans, recur(stage + 1, copy_vec));
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	board.resize(n, std::vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	int ans = recur(0, board);
	printf("%d\n", ans);
	return 0;
}