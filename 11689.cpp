#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

typedef long long ll;

struct element {
	ll num, pos, state;
	element(ll num, ll pos, ll state) : num(num), pos(pos), state(state) {}
};

std::vector<ll> vec;

int main() {
	ll N;
	ll cnt;
	ll tn,i,j,idx = 0;
	std::queue<element> ele_queue;

	scanf("%lld", &N);
	if (N == 1) {
		printf("1\n");
		return 0;
	}
	tn = N;
	for (i = 2; i*i <= N; i++) {
		while (!(tn % i)) {
			tn /= i;
			vec.push_back(i);
		}
	}
	if (tn != 1) vec.push_back(tn);
	std::sort(vec.begin(), vec.end());
	vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
	for (auto next : vec) {
		element ele(next,idx++,1);
		ele_queue.push(ele);
	}

	ll ans = N;
	// 포함 배제 원리 원칙을 사용해서 문제를 해결하도록 한다. (서로소 개수 세기)
	while (ele_queue.size()) {
		ll here = ele_queue.front().num;
		ll pos = ele_queue.front().pos;
		ll state = ele_queue.front().state;
		ele_queue.pop();

		if (state)
			ans -= N / here;
		else
			ans += N / here;

		for (i = pos + 1; i < vec.size(); i++) {
			ll next = here * vec[i];
			if (next <= N) {
				element ele(next, i, state ^ 1);
				ele_queue.push(ele);
			}
			else break;
		}
	}	
	printf("%lld\n", ans);
	return 0;
}