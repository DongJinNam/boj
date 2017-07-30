#include <stdio.h>

int main() {

	int total = 1000;
	int in;
	int ans = 0;
	int arr[6] = { 500,100,50,10,5,1 };

	scanf("%d", &in);
	total -= in;

	for (int i = 0; i < 6; i++) {
		if (total == 0) break;

		int val = total / arr[i];
		total -= val * arr[i];
		ans += val;
	}
	printf("%d", ans);
	return 0;
}