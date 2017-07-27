#include <stdio.h>
int main() {
	int min = 100, sum = 0;
	int arr[7];
	for (int i = 0; i < 7; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] % 2 == 1) {
			min = arr[i] < min ? arr[i] : min;
			sum += arr[i];
		}
	}	
	if (sum > 0)
		printf("%d\n%d\n", sum, min);
	else
		printf("-1\n");
	return 0;
}