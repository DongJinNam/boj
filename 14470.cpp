#include <stdio.h>

using namespace std;

int main() {
	int ans = 0;
	int a, b, c, d, e;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	if (a < 0) {
		ans += c * -a;
		ans += d;
		ans += b * e;
	}
	else {
		ans += (b - a)*e;
	}
	printf("%d\n", ans);
	return 0;
}