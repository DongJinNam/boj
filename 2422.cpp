#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define MAX 201

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	int ans = 0;
	std::vector<int> edge_vec[MAX];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		edge_vec[i].resize(n + 1, 0);
	}
	for (int i = 0; i < m; i++) {
		int src, dst;
		cin >> src >> dst;
		edge_vec[src][dst] = 1;
		edge_vec[dst][src] = 1;
	}
	// i번째 사탕을 선택 시 경우의 수.
	for (int i = 1; i < n - 1; i++) {
		int select = 0;
		int result = 0;
		std::vector<int> ena_vec;
		for (int j = i + 1; j <= n; j++) {
			if (edge_vec[i][j] == 0)
				ena_vec.push_back(j);
		}
		for (int j = 0; j < ena_vec.size(); j++) {
			int comp1 = ena_vec[j];
			for (int k = j + 1; k < ena_vec.size(); k++) {
				int comp2 = ena_vec[k];
				if (edge_vec[comp1][comp2] == 0) select++;
			}
		}
		ans += select;
	}
	cout << ans << '\n';
	return 0;
}