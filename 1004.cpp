#include <stdio.h>
#include <math.h>

int main() {
	int tc;
	int N;
	int x1, x2, y1, y2;
	int cx1, cy1;
	double d1, d2, r;

	scanf("%d", &tc);
	while (tc--) {
		int ans = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &N);
		while (N--) {
			scanf("%d %d %lf", &cx1, &cy1, &r);
			d1 = sqrt(pow(cx1 - x1, 2) + pow(cy1 - y1, 2));
			d2 = sqrt(pow(cx1 - x2, 2) + pow(cy1 - y2, 2));
			if (d1 < r && d2 > r) ans++;
			if (d1 > r && d2 < r) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}