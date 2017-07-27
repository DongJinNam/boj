#include <stdio.h>

int main() {
	int tc;
	int price;
	int opt_cnt;
	int q, p;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &price);
		scanf("%d", &opt_cnt);
		for (int i = 0; i < opt_cnt; i++) {
			scanf("%d %d", &q, &p);
			price += q * p;
		}
		printf("%d\n", price);
	}
	return 0;
}