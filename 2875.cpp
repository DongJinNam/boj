#include <stdio.h>

int main() {

	int N, M, K;
	int i, j;
	int ans = 0;
	scanf("%d %d %d", &N, &M, &K);

	int temp = 0;
	for (i = 0; i <= K; i++) {
		int girl = N - i;
		int man = M - (K - i);
		temp = 0;
		while (girl > 1 && man > 0) {
			girl -= 2;
			man -= 1;
			temp++;
		}
		ans = temp > ans ? temp : ans;
	}
	printf("%d", ans);
	return 0;
}