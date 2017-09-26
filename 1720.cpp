#include <stdio.h>

typedef long long ll;

ll a[31];
ll d[31];

int main() {

	int n;
	int i, j;
	scanf("%d", &n);
	a[1] = 1; // ´ëÄª Æ÷ÇÔ
	a[2] = 3;
	for (i = 3; i <= 30; i++) {
		a[i] = a[i - 1] + a[i - 2] * 2LL;
	}

	d[1] = 1; // ³ë ´ëÄª
	d[2] = 3;

	for (i = 3; i <= 30; i++) {
		ll b = 0;
		if (i % 2 == 1)  b = a[(i - 1) / 2];
		else b = a[i / 2] + 2 * a[(i - 2) / 2];
		d[i] = (a[i] + b) / 2;
	}
	printf("%lld\n", d[n]);
	return 0;
}