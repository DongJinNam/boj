#include <stdio.h>
#include <string.h>
#include <algorithm>

int main() {
	unsigned long long i, j;
	unsigned long long cnt_2 = 0, cnt_5 = 0;
	unsigned long long n, m;
	scanf("%llu %llu", &n, &m);
	for (i = 2; i <= n; i *= 2) {
		cnt_2 += n / i;
	}
	for (i = 2; i <= n - m; i *= 2) {
		cnt_2 -= (n - m) / i;
	}
	for (i = 2; i <= m; i *= 2) {
		cnt_2 -= m / i;
	}
	for (i = 5; i <= n; i *= 5) {
		cnt_5 += n / i;
	}
	for (i = 5; i <= n - m; i *= 5) {
		cnt_5 -= (n - m) / i;
	}
	for (i = 5; i <= m; i *= 5) {
		cnt_5 -= m / i;
	}
	printf("%llu\n", std::min(cnt_2, cnt_5));
	return 0;
}