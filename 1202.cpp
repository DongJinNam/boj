#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef std::pair<int, int> iPair;
typedef long long ll;

int inf = 100000001;

bool cmp(iPair &left, iPair &right) {
	if (left.first < right.first) return true;
	else if (left.first == right.first && left.second < right.second) return true;
	else return false;
}

int main() {

	int N, K;
	int i, j;
	ll ans = 0;
	ll weight, price;
	scanf("%d %d", &N, &K);

	std::vector<iPair> dia_vec(N+K);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &weight, &price);
		dia_vec[i] = make_pair(weight, price);
	}
	for (i = 0; i < K; i++) {
		scanf("%d", &weight);
		dia_vec[N + i] = make_pair(weight, inf);
	}
	
	std::sort(dia_vec.begin(), dia_vec.end(), cmp);

	// priority queue를 사용한 greedy algorithm
	std::priority_queue<ll> pq;
	for (i = 0; i < N + K; i++) {
		iPair x = dia_vec[i];
		if (x.second == inf) {
			// 가방
			if (pq.size() > 0) {
				ll val = pq.top();
				ans += val;
				pq.pop();
			}
		}
		else {
			// 보물
			pq.push(x.second);
		}
	}
	printf("%lld\n", ans);
	return 0;
}