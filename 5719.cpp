#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

#define V_MAX 501
#define E_MAX 10001
#define INF 1000000001

typedef std::pair<int, int> iPair;

using namespace std;

std::vector<int> dp;
std::vector<std::vector<int>> connected;
std::vector<std::vector<bool>> visited;
int n, m, from, to, b, e;

void djikstra() {
	std::priority_queue<iPair> pq;
	dp.clear();
	dp.resize(n, -1);
	pq.push(iPair(0, b));
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int from = pq.top().second;
		pq.pop();

		if (dp[from] != -1) continue;
		dp[from] = cost;

		for (int i = 0; i < n; i++) {
			if (connected[from][i] == -1) continue;
			if (dp[i] != -1) continue;
			pq.push(iPair(-cost - connected[from][i], i));
		}
	}	
}

void erase() {
	std::queue<int> bfs;
	bfs.push(e);
	while (!bfs.empty()) {
		int front = bfs.front();
		bfs.pop();
		for (int i = 0; i < n; i++) {
			if (dp[front] == dp[i] + connected[i][front] && connected[i][front] != -1) {
				connected[i][front] = -1;
				bfs.push(i);
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);

	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		cin >> b >> e;
		
		connected.clear();
		connected.resize(n, std::vector<int>(n, -1));
		visited.clear();
		visited.resize(n, std::vector<bool>(n, false));
		dp.resize(n, -1);
		
		for (int i = 0; i < m; i++) {
			int src, dst, wei;
			cin >> src >> dst >> wei;
			connected[src][dst] = wei;			
		}		

		djikstra();
		erase();
		djikstra();
		cout << dp[e] << "\n";
	}
	return 0;
}