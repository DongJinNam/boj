#include <stdio.h>

int dp[501][501];

int main() {
	int n;
	int l_x  = 500, r_x = 0, l_y = 500, r_y = 0;
	int i, j, k, x1, x2, y1, y2, ans = 0;

	scanf("%d", &n);

	while (n--) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		l_x = x1 < l_x ? x1 : l_x;
		l_y = y1 < l_y ? y1 : l_y;
		r_x = x2 > r_x ? x2 : r_x;
		r_y = y2 > r_y ? y2 : r_y;

		for (i = y1; i < y2; i++) {
			for (j = x1; j < x2; j++) {
				dp[i][j] = 1;
			}
		}
	}

	for (i = l_y; i < r_y; i++) {
		for (j = l_x; j < r_x; j++) {
			if (dp[i][j] > 0) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}