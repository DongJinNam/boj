#include <stdio.h>

int main() {
	int total = 0;
	int temp;
	scanf("%d", &total);
	for (int i = 0; i < 9; i++) {
		scanf("%d", &temp);
		total -= temp;
	}
	printf("%d\n", total);
	return 0;
}