#include <stdio.h>

void go(int size, int start, int end) {
	int c = 6 - start - end;
	if (size == 0) {
		return;
	}
	go(size - 1, start, c);
	printf("%d %d\n", start, end);
	go(size - 1, c, end);
}

int main() {
	// 하노이탑 문제
	int N;
	long long ans;
	scanf("%d", &N);
	ans = (1 << N) - 1;
	printf("%lld\n", ans);
	go(N, 1, 3);
	return 0;
}