#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> arr(4);
	for (int i = 0; i < 4; i++)
		scanf("%d", &arr[i]);
	std::sort(arr.begin(), arr.end());

	printf("%d\n", arr[0] * arr[2]);
	return 0;
}