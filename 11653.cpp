#include <stdio.h>

int main() {
	int data, i;
	scanf("%d", &data);
	for (i = 2; i * i <= data; i++) {
		while (data % i == 0) {
			printf("%d\n", i);
			data /= i;
		}
	}
	if (data > 1) printf("%d\n", data);
	return 0;
}