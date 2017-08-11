#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool check[101];

int main() {
	std::ios::sync_with_stdio(false);
	int N;
	int M;
	int i, j, from, to, ans = 0;
	std::vector<int> adj_comp[101];
	std::queue<int> bfs;

	cin >> N;
	cin >> M;

	for (i = 0; i < M; i++) {
		cin >> from >> to;
		adj_comp[from].push_back(to);
		adj_comp[to].push_back(from);
	}

	bfs.push(1);
	while (!bfs.empty()) {
		int front = bfs.front();
		bfs.pop();
		if (check[front]) continue;

		check[front] = true;
		ans++;
		for (i = 0; i < adj_comp[front].size(); i++) {
			int at = adj_comp[front][i];
			bfs.push(at);
		}
	}
	cout << ans - 1 << endl;
	return 0;
}