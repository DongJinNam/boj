#include <iostream>
#include <queue>
#include <vector>

typedef std::pair<int, int> iPair;

using namespace std;

int inf = 1000000000;

int main() {
	std::ios::sync_with_stdio(false);
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;

	std::vector<int> dp(f + 1, inf);
	std::queue<iPair> bfs;

	dp[s] = 0;
	bfs.push(make_pair(0, s));
	while (!bfs.empty()) {
		int add = -bfs.front().first;
		int to = bfs.front().second;
		bfs.pop();

		if (to == g) break;
		if (add > dp[to]) continue;

		if (to + u <= f && dp[to] + 1 < dp[to + u]) {
			dp[to + u] = dp[to] + 1;
			bfs.push(make_pair(-dp[to + u], to + u));
		}
		if (to - d > 0 && dp[to] + 1 < dp[to - d]) {
			dp[to - d] = dp[to] + 1;
			bfs.push(make_pair(-dp[to - d], to - d));
		}
	}
	if (dp[g] != inf) cout << dp[g];
	else cout << "use the stairs";
	return 0;
}