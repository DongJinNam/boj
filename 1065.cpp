#include <stdio.h>
#include <algorithm>
#include <math.h>

int main() {

	int i, input, total = 0;

	scanf("%d", &input);

	if (input < 100)
		printf("%d\n", input);
	else {
		total = 99;
		for (i = 100; i <= input; i++) {
			int arr[3], temp = i, n = 2;
			while (n > 0) {
				arr[2 - n] = temp / pow(10, n);
				temp -= arr[2 - n] * pow(10, n);
				n--;
			}
			arr[2] = temp;
			if (arr[2] - arr[1] == arr[1] - arr[0]) total++;
		}
		printf("%d\n", total);
	}
	return 0;
}