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

		std::vector<std::vector<int>> con(n + 1, std::vector<int>(0, 0)); // 정점을 기준으로 연결 정보를 담는 벡터
		std::vector<int> color_vec(n+1,-1); // 점마다 어느 색을 기록했는지
		std::vector<iPair> edgelist;

		// edge 정보 입력
		for (int i = 0; i < m; i++) {
			int from, to;
			cin >> from >> to;
			con[from].push_back(to);
			con[to].push_back(from);
			edgelist.push_back(iPair(from, to));
		}

		// 순차적으로 bfs
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

		// 색칠하기 가능 여부 check
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