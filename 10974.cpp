#include <stdio.h>
#include <algorithm>
#include <vector>

int main() {
	int N, i;
	scanf("%d", &N);
	std::vector<int> arr(N);
	for (i = 0; i < N; i++)
		arr[i] = i + 1;
	do {
		for (i = 0; i < N; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	} while (std::next_permutation(arr.begin(), arr.end()));
	return 0;
}