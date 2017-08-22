#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

typedef std::pair<int, int> iPair;

int dp[101];

int main() {

	int n,m;
	int from, to;
	int i, j;
	std::vector<int> adj_vec[101];

	scanf("%d", &n);
	scanf("%d %d", &from, &to);
	scanf("%d", &m);
	while (m--) {
		int con1, con2;
		scanf("%d %d", &con1, &con2);
		adj_vec[con1].push_back(con2);
		adj_vec[con2].push_back(con1);
	}

	std::queue<iPair> bfs;
	bfs.push(make_pair(0,from));
	while (!bfs.empty()) {
		iPair front = bfs.front();
		bfs.pop();

		if (dp[front.second] > 0) continue;		
		dp[front.second] = front.first;

		for (i = 0; i < adj_vec[front.second].size(); i++) {
			int at = adj_vec[front.second][i];
			if (dp[at] == 0) {				
				bfs.push(make_pair(front.first + 1, at));
			}
		}
	}
	if (dp[to] == 0) printf("-1");
	else printf("%d", dp[to]);
	return 0;
}