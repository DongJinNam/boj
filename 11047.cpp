#include <stdio.h>
#include <vector>

using namespace std;

int main() {

	int N, K;
	int i, j;
	int ans = 0;
	std::vector<int> money_vec(10);
	scanf("%d %d", &N, &K);
	for (i = 0; i < N; i++)
		scanf("%d", &money_vec[i]);

	for (i = N - 1; i >= 0; i--) {
		if (K == 0) break;
		int count = K / money_vec[i];
		K -= (money_vec[i] * count);
		ans += count;		
	}
	printf("%d\n", ans);
	return 0;
}