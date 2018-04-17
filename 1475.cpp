#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int dp[9] = { 0 };

int main() {
	int n, temp;
	int digit10 = 0;
	scanf("%d", &n);
	if (n == 0) {
		printf("1\n");
		return 0;
	}
	temp = n;
	while (temp > 0) {
		if (temp % 10 == 9) dp[6]++;
		else dp[temp % 10]++;
		temp /= 10;
	}	
	int max = 0;
	for (int i = 0; i < 9; i++) {
		if (i == 6) {
			if (dp[i] % 2 == 0) 
				max = std::max(dp[i] / 2, max);
			else
				max = std::max(dp[i] / 2 + 1, max);
		}
		else {
			max = std::max(dp[i], max);
		}		
	}
	printf("%d\n", max);
	return 0;
}