#include <stdio.h>
#include <algorithm>

int main() {
	long long arr[3];
	while (1) {
		scanf("%lld %lld %lld", &arr[0], &arr[1], &arr[2]);
		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) break;

		std::sort(arr, arr + 3);		
		if (arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2]) printf("right\n");
		else printf("wrong\n");		
	}
	return 0;
}