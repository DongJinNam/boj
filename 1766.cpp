#include <stdio.h>
#include <queue>
#include <vector>

int in_deg[32001];
bool check[32001];

// min heap 사용법
struct comparator {
	bool operator() (int i, int j) {
		return i > j;
	}
};

int main() {

	// stl c++에서는 priority queue가 값이 큰것이 우선이다. 그래서 c++에서 아래와 같이 min heap을 사용해야 한다.
	std::priority_queue<int,std::vector<int>,comparator> minheap; // min heap 사용법
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
			minheap.push(i);
		}
	}
	while (!minheap.empty()) {
		int top = minheap.top();
		minheap.pop();
		printf("%d ", top);
		check[top] = true;
		for (i = 0; i < bfs_vec[top].size(); i++) {
			int at = bfs_vec[top][i];
			in_deg[at]--;
			if (in_deg[at] == 0 && check[at] == false) {
				minheap.push(at);
			}
		}
	}
	return 0;
}