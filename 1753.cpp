#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

#define V_MAX 30001

using namespace std;

typedef std::pair<int, int> iPair;
int inf = 1000000000; // 한계치
bool check[V_MAX]; // 방문 여부 체크 배열
std::vector<int> dp(V_MAX, inf); // DP의 결과
std::vector<iPair> adj_vec[V_MAX]; // 노드를 기준으로 인접 노드, Edge의 가중치를 담은 벡터

int main() {

	int V, E;
	int i, j;
	int start, from, to, add;

	scanf("%d %d", &V, &E);
	scanf("%d", &start);

	for (i = 0; i < E; i++) {
		scanf("%d %d %d", &from, &to, &add);
		adj_vec[from].push_back(make_pair(to, add));
	}

	std::priority_queue<iPair> pq; // 우선순위 큐를 사용한 BFS를 통해서 노드 각각에 대한 최단 경로를 구할 수 있다.
	pq.push(make_pair(0, start));
	dp[start] = 0;

	while (!pq.empty()) {
		iPair x = pq.top();
		pq.pop();
		if (check[x.second]) continue;
		check[x.second] = true;
		for (i = 0; i < adj_vec[x.second].size(); i++) {
			to = adj_vec[x.second][i].first;
			add = adj_vec[x.second][i].second;
			if (dp[to] > dp[x.second] + add) {
				dp[to] = dp[x.second] + add;
				pq.push(make_pair(-dp[to], to));
			}
		}
	}
	for (i = 1; i <= V; i++) {
		if (dp[i] >= inf) printf("INF\n", dp[i]);
		else printf("%d\n", dp[i]);
	}
	return 0;
}