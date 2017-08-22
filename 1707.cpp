#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int group[20001]; // i��° ��尡 ���° �׷쿡 ���ϴ���.
std::vector<int> adj_vec[20001];// ���� ����Ʈ

void dfs(int node, int val) {
	group[node] = val;
	for (int i = 0; i < adj_vec[node].size(); i++) {
		int at = adj_vec[node][i];
		if (group[at] == 0) {
			dfs(at, 3 - val);
		}
	}
}
// �̺� �׷��� ����
int main() {
	std::ios::sync_with_stdio(false);
	int tc, i, j;
	cin >> tc; // �׽�Ʈ ���̽�
	while (tc--) {
		int v_cnt, e_cnt;
		int from, to;
		bool ans = true;
		cin >> v_cnt >> e_cnt; // vertex ����, edge ����
		for (i = 1; i <= v_cnt; i++) {
			adj_vec[i].clear(); // ��������Ʈ, group �迭 �ʱ�ȭ
			group[i] = 0;
		}
		for (i = 0; i < e_cnt; i++) {
			cin >> from >> to;
			adj_vec[from].push_back(to);
			adj_vec[to].push_back(from);
		}
		for (i = 1; i <= v_cnt; i++) {
			if (group[i] == 0) dfs(i, 1); // ���� �׷� ��ȣ�� �־����� ���� ��� dfs Ž��
		}
		for (i = 1; i <= v_cnt; i++) {
			if (!ans) break;
			for (j = 0; j < adj_vec[i].size(); j++) {
				int at = adj_vec[i][j];
				if (group[i] == group[at]) { // ����� ���� �߿� �� ����� �׷� ��ȣ�� ���ٸ� �̺� �׷����� �ƴϴ�.
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