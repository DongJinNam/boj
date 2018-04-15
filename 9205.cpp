#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

typedef std::pair<int, int> iPair;

using namespace std;

int diff(int a, int b) {
	return a - b > 0 ? a - b : b - a;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		iPair home, fest;
		std::vector<iPair> com_vec;
		std::vector<bool> visited;
		scanf("%d", &n);
		scanf("%d %d", &home.second, &home.first);
		for (int i = 0; i < n; i++) {
			iPair com_i;
			scanf("%d %d", &com_i.second, &com_i.first);
			com_vec.push_back(com_i);
		}
		scanf("%d %d", &fest.second, &fest.first);

		bool bFind = false;
		visited.resize(n, false);

		std::queue<iPair> q;
		q.push(home);
		while (!q.empty()) {
			iPair front = q.front();
			int diffY = 0;
			int diffX = 0;
			int dis = diffY + diffX;
			q.pop();

			for (int i = 0; i < com_vec.size(); i++) {
				diffY = diff(front.first, com_vec[i].first);
				diffX = diff(front.second, com_vec[i].second);
				dis = diffY + diffX;
				if (dis <= 1000 && visited[i] == false) {
					q.push(com_vec[i]);
					visited[i] = true;
				}
			}

			diffY = diff(front.first, fest.first);
			diffX = diff(front.second, fest.second);
			dis = diffY + diffX;
			if (dis <= 1000) {
				bFind = true;
				break;
			}
		}
		if (bFind)
			printf("happy\n");
		else
			printf("sad\n");
	}
	return 0;
}