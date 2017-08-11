#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef std::pair<int, int> iPair;
int inf = 1000000000;

int main() {
	// topological sort
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int N, K;
		int i, j;
		int from, to;
		int target;

		scanf("%d %d", &N, &K);

		std::vector<int> time_vec(N + 1,0);
		std::vector<int> dp(N + 1, inf);
		std::vector<int> adj_vec[1001];
		std::vector<int> in_deg(N + 1,0);

		for (i = 1; i <= N; i++)
			scanf("%d", &time_vec[i]);
		for (i = 1; i <= K; i++) {
			scanf("%d %d", &from,&to);
			adj_vec[from].push_back(to);
			in_deg[to]++;
		}
		scanf("%d", &target);

		std::priority_queue<iPair> bfs;
		
		for (i = 1; i <= N; i++) {
			if (in_deg[i] == 0) {
				bfs.push(make_pair(-time_vec[i], i));
			}
		}

		while (!bfs.empty()) {
			iPair front = bfs.top();
			bfs.pop();
			if (-front.first > dp[front.second]) continue;

			dp[front.second] = -front.first;
			for (i = 0; i < adj_vec[front.second].size(); i++) {
				int at = adj_vec[front.second][i];
				in_deg[at]--;
				if (in_deg[at] == 0) {
					bfs.push(make_pair(-(dp[front.second] + time_vec[at]), at));
				}
			}			
		}	
		printf("%d\n", dp[target]);
	}

	return 0;
}