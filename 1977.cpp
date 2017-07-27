#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int mul_arr[101];

int main() {

	int N, M;
	int i, j;
	int ans = 0, min = 10001;
	scanf("%d", &M);
	scanf("%d", &N);	

	for (int i = 1; i <= (int)sqrt(N); i++)
		mul_arr[i] = i*i;

	bool bFirst = true;
	for (int i = 1; i <= (int)sqrt(N); i++) {
		if (M <= mul_arr[i] && mul_arr[i] <= N) {
			if (bFirst) {
				min = mul_arr[i];
				bFirst = false;
			}
			ans += mul_arr[i];
		}
	}

	if (ans > 0)
		printf("%d\n%d\n", ans, min);
	else
		printf("-1\n");
	return 0;
}