#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

#define V_MAX 30001

using namespace std;

typedef std::pair<int, int> iPair;
int inf = 1000000000; // �Ѱ�ġ
bool check[V_MAX]; // �湮 ���� üũ �迭
std::vector<int> dp(V_MAX, inf); // DP�� ���
std::vector<iPair> adj_vec[V_MAX]; // ��带 �������� ���� ���, Edge�� ����ġ�� ���� ����

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

	std::priority_queue<iPair> pq; // �켱���� ť�� ����� BFS�� ���ؼ� ��� ������ ���� �ִ� ��θ� ���� �� �ִ�.
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