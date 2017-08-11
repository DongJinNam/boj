#include <stdio.h>
#include <algorithm>
#include <vector>

typedef long long ll;

int main() {
	int N;
	ll i, j, left, right, mid;
	ll limit_val;
	ll total = 0;
	ll max = 0;
	scanf("%d", &N);

	std::vector<ll> num_arr(N, 0);
	for (i = 0; i < N; i++) {
		scanf("%lld", &num_arr[i]);
		total += num_arr[i];
		max = num_arr[i] > max ? num_arr[i] : max;
	}
	scanf("%lld", &limit_val);
	// 예외처리
	if (limit_val >= total) {
		printf("%lld", max);
		return 0;
	}

	// 이분 탐색
	left = 0;
	right = 2100000000;	
	while(left < right) {
		total = 0;
		mid = ((left + right) >> 1);
		for (i = 0; i < N; i++) {
			if (num_arr[i] <= mid) 
				total += num_arr[i];
			else 
				total += mid;			
		}
		if (total <= limit_val) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	printf("%lld\n", left - 1);
	return 0;
}