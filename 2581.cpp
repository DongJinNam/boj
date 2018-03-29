#include <iostream>
#include <vector>
#include <math.h>

#define MAX 10000

using namespace std;

int main() {
	// 에라토스테세스의 채
	std::vector<int> dp(10001, 1);
	dp[0] = -1;
	dp[1] = -1;
	for (int i = 2; i <= sqrt(MAX); i++) {
		if (dp[i] == 1) {
			for (int j = i + i; j <= MAX; j += i) {
				dp[j] = 0;
			}
		}
	}

	int beg, end;
	int sum = 0;
	int min = MAX + 1;
	cin >> beg >> end;
	for (int i = beg; i <= end; i++) {
		if (dp[i] == 1) {
			min = i < min ? i : min;
			sum += i;
		}
	}
	if (min == MAX + 1) {
		cout << -1 << "\n";
	}
	else {
		cout << sum << "\n";
		cout << min << "\n";
	}
	return 0;
}