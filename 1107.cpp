#include <stdio.h>
#include <cstdlib>
#include <cmath>

#define MAX 1000000

bool bBroken[10]; // 버튼 망가짐 true, 아님 false

int possible(int num) { // 자력으로 만들 수 있는지 판단
	int len = 0;
	if (num == 0) {
		if (bBroken[0]) return 0;
		else return 1;
	}
	while (num > 0) {
		if (bBroken[num % 10]) return 0;
		num /= 10;
		len++;
	}
	return len;
}

int main() {
	int N, M, data;
	int i, j, k;
	int ans;

	scanf("%d", &N);
	scanf("%d", &M);

	for (i = 0; i < M; i++) {
		scanf("%d", &data);
		bBroken[data] = true;
	}

	ans = std::abs(N - 100);

	for (i = 0; i <= MAX; i++) {
		int num = i;
		int len = possible(num);
		if (len > 0) {
			int press = std::abs(num - N);
			if (ans > press + len) {
				ans = press + len;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}