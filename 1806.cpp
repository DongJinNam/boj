#include <stdio.h>
#include <algorithm>
#include <vector>
#include <limits.h>

int main() {
	int N, i, j, k;
	long long S, sum = 0;
	int l, r, cnt = 0, min = 0;


	scanf("%d %lld", &N, &S);

	std::vector<int> arr(N);
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	l = 0;
	r = 0;
	sum = arr[0];
	min = N + 1;
	// 부분합 구하기
	while (l <= r && r < N) {
		if (sum < S) {
			r++;
			if (r < N) sum += arr[r];
		}
		else if (sum == S) {
			// min 비교
			min = (r - l + 1) < min ? (r - l + 1) : min;
			r++;
			if (r < N) sum += arr[r];
		}
		else {
			min = (r - l + 1) < min ? (r - l + 1) : min;
			sum -= arr[l];
			l++;
		}
	}
	if (min == N+1) printf("0\n");
	else printf("%d\n", min);
	return 0;
}