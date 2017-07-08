#include <stdio.h>
#include <map>
#include <stack>
#include <queue>
#include <string.h>
#include <algorithm>

bool bVisited[1001];
std::map<int, int> dataMap[1001];

void dfs(int x) {
	bVisited[x] = true;
	printf("%d ", x);
	std::map<int, int>::iterator tempIt;
	for (tempIt = dataMap[x].begin(); tempIt != dataMap[x].end(); tempIt++) {
		int to = tempIt->first;
		if (bVisited[to] == false) {
			dfs(to);
		}
	}	
}

int main() {
	int N, M, start;
	int i, j, k, from, to, temp;	
	std::queue<int> bfsQueue;
	std::map<int, int>::iterator tempIt;

	scanf("%d %d %d", &N, &M, &start);	

	for (i = 0; i < M; i++) {
		scanf("%d %d", &from, &to);
		dataMap[from].insert(std::pair<int, int>(to, 1));
		dataMap[to].insert(std::pair<int, int>(from, 1));
	}

	// dfs
	dfs(start);
	printf("\n");
	memset(bVisited, false, sizeof(bool) * 1001);
	// bfs
	bVisited[start] = true;
	bfsQueue.push(start);
	while (!bfsQueue.empty()) {
		int point = bfsQueue.front();
		bfsQueue.pop();
		printf("%d ", point);
		for (tempIt = dataMap[point].begin(); tempIt != dataMap[point].end(); tempIt++) {
			int to = tempIt->first;
			if (bVisited[to] == false) {
				bVisited[to] = true;
				bfsQueue.push(to);
			}
		}
	}
	printf("\n");
	return 0;
}