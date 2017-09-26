#include <stdio.h>

int main() {

	int n;
	int i, j;
	int total = 0;
	int max = 0;
	int data = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &data);
		total += data;
		max = data > max ? data : max;
	}
	total -= max;
	printf("%d", total);
	return 0;
}