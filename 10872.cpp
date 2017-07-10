#include <stdio.h>

int main() {
	int data, i;
	unsigned long long result = 1;
	scanf("%d", &data);
	if (data == 0) printf("1\n");
	else {
		for (i = 2; i <= data; i++)
			result *= i;
		printf("%llu\n", result);
	}
	return 0;
}