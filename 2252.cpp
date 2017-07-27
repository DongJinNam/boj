#include <stdio.h>
#include <queue>
#include <vector>

int in_deg[32001];
bool check[32001];

int main() {

	std::queue<int> bfs_q;
	std::vector<int> bfs_vec[32001];

	int from, to;
	int i, j, k;
	int N, M;
	int first;

	scanf("%d %d", &N, &M);
	while (M--) {
		scanf("%d %d", &from, &to);
		in_deg[to]++;
		bfs_vec[from].push_back(to);
	}

	for (i = 1; i <= N; i++) {
		if (in_deg[i] == 0) {
			bfs_q.push(i);
		}
	}
	while (!bfs_q.empty()) {
		int front = bfs_q.front();
		bfs_q.pop();
		printf("%d ", front);
		check[front] = true;
		for (i = 0; i < bfs_vec[front].size(); i++) {
			int at = bfs_vec[front][i];
			in_deg[at]--;
			if (in_deg[at] == 0 && check[at] == false) {
				bfs_q.push(at);
			}
		}		
	}
	return 0;
}