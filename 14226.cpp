#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 2002

typedef std::pair<int, int> iPair;

using namespace std;

bool check(int val, int area) {
	return val > 0 && val < area;
}

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);

	int s;
	int ans = MAX;
	cin >> s;

	std::vector<std::vector<int>> dp(MAX, std::vector<int>(MAX, MAX));
	std::vector<std::vector<bool>> visited(MAX, std::vector<bool>(MAX, false));
	std::queue<iPair> bfs;

	bfs.push(iPair(1, 0));
	dp[1][0] = 0;
	visited[1][0] = true;
	while (!bfs.empty()) {
		iPair front = bfs.front();
		int cur = front.first;
		int clip = front.second;
		bfs.pop();

		if (cur == s) {
			break;
		}

		for (int i = 0; i < 3; i++) {
			switch (i) {
			case 0:
				if (!visited[cur][cur] && dp[cur][clip] + 1 < dp[cur][cur]) {
					bfs.push(iPair(cur, cur));
					visited[cur][cur] = true;
					dp[cur][cur] = dp[cur][clip] + 1;
				}
				break;
			case 1:
				if (check(cur+clip,2*s) && !visited[cur + clip][clip] && dp[cur][clip] + 1 < dp[cur + clip][clip]) {
					bfs.push(iPair(cur+clip, clip));
					visited[cur+clip][clip] = true;
					dp[cur+clip][clip] = dp[cur][clip] + 1;
				}
				break;
			case 2:
				if (check(cur - 1, 2 * s) && !visited[cur - 1][clip] && dp[cur][clip] + 1 < dp[cur-1][clip]) {
					bfs.push(iPair(cur-1, clip));
					visited[cur-1][clip] = true;
					dp[cur-1][clip] = dp[cur][clip] + 1;
				}
				break;
			}
		}
	}

	int min = dp[s][0];
	for (int i = 1; i < 2 * s; i++) {
		min = dp[s][i] < min ? dp[s][i] : min;
	}
	cout << min << "\n";
	return 0;
}