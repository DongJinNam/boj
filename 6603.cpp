#include <stdio.h>

int arr[13];
bool check[13];
int k;

void go(int start, int size) {
	if (size == 0) {
		for (int i = 0; i < k; i++) {
			if (check[i]) printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = start; i < k; i++) {
		check[i] = true;
		go(i+1, size-1);
		check[i] = false;
	}
}

int main() {
	int i, j;
	while (1) {
		scanf("%d", &k);
		if (k == 0) break;
		for (i = 0; i < k; i++) 
			scanf("%d", &arr[i]);
		go(0, 6);
		printf("\n");
	}
	return 0;
}