#include <stdio.h>

int main() {
	int n;
	int start = 1;
	scanf("%d", &n);
	if (n == 1) {
		printf("1\n");
		return 0;
	}
	int temp = 1;
	int count = 1;
	while (temp < n) {
		temp += 6 * count;
		count++;
	}
	printf("%d", count);
	return 0;
}