#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

int arr[8];

int main() {

	int N;
	int i, j;
	int ans = 0, temp = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	std::sort(arr, arr + N);
	do {
		temp = 0;
		for (j = 0; j < N - 1; j++) {
			temp += std::abs(arr[j + 1] - arr[j]);
		}
		ans = (int) std::max(temp, ans);
	} while (std::next_permutation(arr, arr + N));

	printf("%d", ans);
	return 0;
}