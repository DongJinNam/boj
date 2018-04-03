#include <stdio.h>
#include <algorithm>
#include <limits>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	double ans = (double) a / b;
	printf("%.10lf\n", ans);
	return 0;
}