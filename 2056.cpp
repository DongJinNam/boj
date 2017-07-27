#include <stdio.h>
#include <vector>
#include <queue>

int work_time[10001];
int in_deg[10001];
int finish_time[10001];
bool check[10001];
std::vector<int> link_vec[10001];

int main() {

	int N;
	int i, j, k;
	int total = 0;
	int ans = 0;
	std::queue<int> bfs_q;
	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		scanf("%d %d", &work_time[i], &in_deg[i]);
		for (j = 0; j < in_deg[i]; j++) {
			int data;
			scanf("%d", &data);
			link_vec[data].push_back(i);
		}
	}

	for (i = 1; i <= N; i++) {
		if (in_deg[i] == 0) {
			bfs_q.push(i);
			finish_time[i] = work_time[i];
		}
	}
	// topological sort
	while (!bfs_q.empty()) {
		int front = bfs_q.front();
		bfs_q.pop();
		check[front] = true;
		for (i = 0; i < link_vec[front].size(); i++) {
			int at = link_vec[front][i];
			in_deg[at]--;
			if (finish_time[at] < finish_time[front] + work_time[at]) // bfs + dp
				finish_time[at] = finish_time[front] + work_time[at];
			if (in_deg[at] == 0 && check[at] == false) 
				bfs_q.push(at);			
		}
	}

	for (i = 1; i <= N; i++) {
		if (finish_time[i] > ans) ans = finish_time[i];
	}

	printf("%d\n", ans);
	return 0;
}