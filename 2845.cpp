#include <stdio.h>

int main() {

	int L, P;
	int base;
	int arr[5];
	scanf("%d %d", &L, &P);
	base = L * P;
	
	for (int i = 0; i < 5; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i] - base);
	}
	printf("\n");
	return 0;
}