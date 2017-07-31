#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int inf = 1000000001;

int main() {

	int N;
	int i, j;
	int len = 0;
	int max = 0;
	
	scanf("%d", &N);	

	std::vector<int> arr(N + 1);
	std::vector<int> dp(N, inf);

	for (i = 1; i <= N; i++) 
		scanf("%d", &arr[i]);
	
	dp[0] = arr[1];
	for (i = 2; i <= N; i++) {
		std::vector<int>::iterator low, high;
		int l_index;

		low = std::lower_bound(dp.begin(), dp.end(), arr[i]);
		l_index = low - dp.begin();
		dp[l_index] = arr[i];
		if (max < l_index) max = l_index;
	}
	printf("%d\n", max + 1);

	return 0;
}