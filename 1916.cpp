#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

typedef std::pair<int, int> iPair;
ll dp[1001];
bool check[1001];
int inf = 100000001;

int main() {

	int N, M;
	int i, j;
	int from, to, add;
	int start, end;
	std::vector<iPair> adj_vec[1001];

	scanf("%d", &N);
	scanf("%d", &M);

	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &from, &to, &add);
		adj_vec[from].push_back(make_pair(to, add));
	}
	scanf("%d %d", &start, &end);

	for (i = 1; i <= N; i++) {
		if (i != start) dp[i] = inf;
	}
	// priority queue를 사용한 다익스트라
	std::priority_queue<iPair> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		iPair x = pq.top();
		pq.pop();		
		if (-x.first > dp[x.second]) continue;
		for (i = 0; i < adj_vec[x.second].size(); i++) {
			int to = adj_vec[x.second][i].first;
			int add = adj_vec[x.second][i].second;
			if (dp[to] > dp[x.second] + add) {
				dp[to] = dp[x.second] + add;
				pq.push(make_pair(-dp[to], to));
			}
		}
	}
	printf("%lld\n", dp[end]);
	return 0;
}