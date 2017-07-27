#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool check[1001]; // 소수이면 false, 소수가 아니면 true

// 에라토스테네스의 체
int main() {
	int n, k;
	int cnt = 0, ans = 0;
	bool bFind = false;

	scanf("%d %d", &n, &k);

	for (int i = 2; i <= n; i++) {
		if (bFind) break;
		if (check[i] == false) {
			for (int j = i; j <= n; j+=i) {
				if (check[j] == false) cnt++;
				if (i != j) check[j] = true;				
				if (cnt == k) {
					ans = j;
					bFind = true;
					break;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}