#include <stdio.h>
#include <algorithm>
#include <queue>

typedef std::pair<int, int> iPair;

using namespace std;

int main() {

	int tc;
	int i, j;
	scanf("%d", &tc);
	while (tc--) {
		int N, select;
		scanf("%d %d", &N, &select);

		std::vector<int> vec(N);
		std::queue<iPair> q;
		std::priority_queue<int> pq;
		for (i = 0; i < N; i++) {
			scanf("%d", &vec[i]);
			q.push(make_pair(vec[i], i));
			pq.push(vec[i]);
		}

		int max = pq.top();
		int ord = 1;
		pq.pop();
		while (!q.empty()) {
			iPair front = q.front();
			q.pop();
			if (front.first == max) {
				if (select == front.second) break;
				ord++;
				max = pq.top();
				pq.pop();
			}
			else {
				q.push(front);
			}
		}
		printf("%d\n", ord);
	}
	return 0;
}