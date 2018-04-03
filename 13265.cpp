#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

typedef std::pair<int, int> iPair;

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);
	int tc;
	cin >> tc;
	while(tc--) {
		int n, m;
		cin >> n >> m;

		std::vector<std::vector<int>> con(n + 1, std::vector<int>(0, 0)); // ������ �������� ���� ������ ��� ����
		std::vector<int> color_vec(n+1,-1); // ������ ��� ���� ����ߴ���
		std::vector<iPair> edgelist;

		// edge ���� �Է�
		for (int i = 0; i < m; i++) {
			int from, to;
			cin >> from >> to;
			con[from].push_back(to);
			con[to].push_back(from);
			edgelist.push_back(iPair(from, to));
		}

		// ���������� bfs
		for (int i = 1; i < color_vec.size(); i++) {
			if (color_vec[i] == -1) {
				std::queue<iPair> bfs;
				bfs.push(iPair(i, 0));
				color_vec[i] = 0;
				while (!bfs.empty()) {
					iPair front = bfs.front();
					int start = front.first;
					int color = front.second;
					bfs.pop();
					for (int j = 0; j < con[start].size(); j++) {
						int at = con[start].at(j);
						if (color_vec[at] < 0) {
							bfs.push(iPair(at, (color + 1) % 2));
							color_vec[at] = (color + 1) % 2;
						}
					}
				}
			}
		}

		// ��ĥ�ϱ� ���� ���� check
		bool bPossible = true;
		for (int i = 0; i < edgelist.size(); i++) {
			if (color_vec[edgelist[i].first] == color_vec[edgelist[i].second]) {
				bPossible = false;
				break;
			}
		}
		for (int i = 1; i < color_vec.size(); i++) {
			if (color_vec[i] == -1) {
				bPossible = false;
				break;
			}
		}
		if (bPossible) cout << "possible\n";
		else cout << "impossible\n";
	}
	return 0;
}