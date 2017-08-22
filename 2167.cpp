#include <stdio.h>

int sum[301][301];

int main() {

	int n, m, k;
	int i, j;
	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			scanf("%d", &sum[i][j]);
			if (j > 1) sum[i][j] += sum[i][j - 1];
		}
	}
	scanf("%d", &k);
	while (k--) {
		int f_x, f_y, t_x, t_y;
		scanf("%d %d %d %d", &f_y, &f_x, &t_y, &t_x);

		int ans = 0;
		for (i = f_y; i <= t_y; i++) {
			ans += sum[i][t_x];
			if (f_x > 1) ans -= sum[i][f_x - 1];
		}
		printf("%d\n", ans);
	}
	return 0;
}