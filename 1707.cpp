#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int group[20001]; // i번째 노드가 몇번째 그룹에 속하는지.
std::vector<int> adj_vec[20001];// 인접 리스트

void dfs(int node, int val) {
	group[node] = val;
	for (int i = 0; i < adj_vec[node].size(); i++) {
		int at = adj_vec[node][i];
		if (group[at] == 0) {
			dfs(at, 3 - val);
		}
	}
}
// 이분 그래프 문제
int main() {
	std::ios::sync_with_stdio(false);
	int tc, i, j;
	cin >> tc; // 테스트 케이스
	while (tc--) {
		int v_cnt, e_cnt;
		int from, to;
		bool ans = true;
		cin >> v_cnt >> e_cnt; // vertex 개수, edge 개수
		for (i = 1; i <= v_cnt; i++) {
			adj_vec[i].clear(); // 인접리스트, group 배열 초기화
			group[i] = 0;
		}
		for (i = 0; i < e_cnt; i++) {
			cin >> from >> to;
			adj_vec[from].push_back(to);
			adj_vec[to].push_back(from);
		}
		for (i = 1; i <= v_cnt; i++) {
			if (group[i] == 0) dfs(i, 1); // 아직 그룹 번호가 주어지지 않은 경우 dfs 탐색
		}
		for (i = 1; i <= v_cnt; i++) {
			if (!ans) break;
			for (j = 0; j < adj_vec[i].size(); j++) {
				int at = adj_vec[i][j];
				if (group[i] == group[at]) { // 연결된 간선 중에 두 노드의 그룹 번호가 같다면 이분 그래프가 아니다.
					ans = false;
					break;
				}
			}
		}
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}