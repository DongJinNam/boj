#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

std::vector<int> adj_vec[2001];
bool check[2001];

int dfs(int start, int count) {
	if (count == 4) {
		return 1;
	}
	if (count > 4) return -1;	
	int rtn = -1;
	for (int i = 0; i < adj_vec[start].size(); i++) {
		int at = adj_vec[start][i];
		if (check[at] == false) {
			check[start] = true;
			rtn = dfs(at, count + 1);
			check[start] = false;
		}
		if (rtn == 1) break;
	}
	return rtn;
}

int main() {

	int N, M;
	int i, j;
	int from, to;
	int ans;

	scanf("%d %d", &N, &M);

	for (i = 0; i < M; i++) {
		scanf("%d %d", &from, &to);
		adj_vec[from].push_back(to);
		adj_vec[to].push_back(from);
	}	

	for (i = 0; i < N; i++) {
		check[i] = true;
		ans = dfs(i, 0);
		check[i] = false;
		if (ans > 0) break;
	}

	if (ans > 0) printf("1");
	else printf("0");
	return 0;
}