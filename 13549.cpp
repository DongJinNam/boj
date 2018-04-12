#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 250001

typedef long long ll;
typedef std::pair<int, int> iPair;

using namespace std;

ll src, dst;
std::vector<int> dp(MAX, -1);

int main() {
	scanf("%d %d", &src, &dst);

	if (src - dst > 0) {
		printf("%d\n", src - dst);
		return 0;
	}

	std::priority_queue<iPair> pq;
	pq.push({ 0,src });
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (dp[here] != -1) continue;
		dp[here] = cost;
		if (here == dst) break;
		if (here * 2 < MAX && dp[here * 2] == -1) {
			pq.push({ -cost,here * 2 });
		}
		if (here + 1 < MAX && dp[here + 1] == -1) {
			pq.push({ -cost-1,here + 1});
		}
		if (here - 1 >= 0 && dp[here - 1] == -1) {
			pq.push({ -cost - 1,here - 1 });
		}
	}
	printf("%d\n", dp[dst]);
	return 0;
}