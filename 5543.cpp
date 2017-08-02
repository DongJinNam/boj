#include <stdio.h>
#include <algorithm>

int main() {
	int arr[3];
	int coke, cida;
	int ans = 0;
	for (int i = 0; i < 3; i++) 
		scanf("%d", &arr[i]);	
	scanf("%d", &coke);
	scanf("%d", &cida);
	std::sort(arr, arr + 3);
	ans += arr[0];
	if (coke < cida)
		ans += coke;
	else
		ans += cida;
	printf("%d", ans-50);
	return 0;
}