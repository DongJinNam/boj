#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

typedef std::pair<int, int> iPair;

struct comp {
	bool operator() (const iPair &left, const iPair &right) {
		return left.first > right.first ? true : false;
	}
};
int main() {
	// prim's algorithm 사용법
	int ans = 0;
	int V, E;
	int i, j, k;
	int from, to, add;
	std::vector<iPair> adj_node[10001];
	std::vector<bool> inMST(10001, false);
	std::vector<int> key(10001, INT_MAX);
	std::priority_queue <iPair, std::vector<iPair>, comp> pq;


	scanf("%d %d", &V,&E);

	for (i = 0; i < E; i++) {
		scanf("%d %d %d", &from, &to, &add);
		adj_node[from].push_back(std::make_pair(to, add));
		adj_node[to].push_back(std::make_pair(from, add));
	}

	key[1] = 0;
	pq.push(make_pair(0, 1));
	while (!pq.empty()) {
		int v = pq.top().second;
		int w = pq.top().first;

		pq.pop();

		if (inMST[v]) continue; // 이미 방문한 점인 경우 pass.

		inMST[v] = true;
		ans += w;

		for (i = 0; i < adj_node[v].size(); i++) {
			int dest = adj_node[v][i].first;
			int weight = adj_node[v][i].second;

			if (!inMST[dest] && key[dest] > weight) {
				key[dest] = weight;
				pq.push(make_pair(weight, dest));
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}