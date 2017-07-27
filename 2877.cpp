#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

ll arr[100];

int main() {
	// N번째로 작은 수를 구하기 (4,7)
	ll N, tn;
	ll idx = 1;
	scanf("%lld", &N);

	tn = N;
	arr[0] = 0;
	while (tn > 0) {
		tn -= (1 << idx);
		arr[idx] = arr[idx - 1] + (1 << idx);
		idx++;
	}
	idx--;

	tn = N;
	for (int i = idx - 1; i >= 0; i--) {
		ll diff = arr[i + 1] - arr[i];
		ll diff2 = tn - arr[i];
		if (diff2 <= diff >> 1) {
			printf("4");
			tn -= (1 << i);
		}
		else {
			printf("7");
			tn -= (1 << (i + 1));
		}
	}
	printf("\n");
	return 0;
}