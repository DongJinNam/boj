#include <stdio.h>

int num[100001];
int sum[100001];

using namespace std;

int main() {
	int n, m, i, j, from, to;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
		sum[i] = sum[i - 1] + num[i];
	}
	while (m--) {
		scanf("%d %d", &from, &to);;
		printf("%d\n", sum[to] - sum[from - 1]);
	}
	return 0;
}