#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>

#define MAX 501

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);
	int tc = 0;

	while (1) {
		int n, m;
		cin >> n >> m;

		if (n == 0 && m == 0) break;

		std::vector<int> adj_vec[MAX];
		std::vector<bool> bVisited(MAX, false);

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			adj_vec[a].push_back(b);
			adj_vec[b].push_back(a);
		}

		int count = 0;
		// we can find existing graph cycle by using dfs.
		for (int i = 1; i < n+1; i++) {
			if (!bVisited[i]) {
				bool bCycle = false;
				std::stack<int> dfs;
				dfs.push(i);
				while (!dfs.empty()) {
					int top = dfs.top();
					dfs.pop();
					if (!bVisited[top]) {
						bVisited[top] = true;
					}
					else {
						bCycle = true;
					}
					for (int j = 0; j < adj_vec[top].size(); j++) {
						int to = adj_vec[top].at(j);
						if (!bVisited[to]) {
							dfs.push(to);
						}
					}
				}
				if (!bCycle) count++;
			}
		}

		cout << "Case " << ++tc << ": ";
		if (count > 1)
			cout << "A forest of " << count << " trees.\n";
		else if (count == 1)
			cout << "There is one tree.\n";
		else
			cout << "No trees.\n";

	}

	return 0;
}