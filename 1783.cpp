#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int N, M;
	int ans = 0;
	scanf("%d %d", &N, &M);

	if (N == 1) ans = 1;
	else if (N == 2) {
		ans = std::min(4, (M+1)/2);
	}
	else {
		if (M < 7) {
			ans = std::min(4, M);
		}
		else {
			ans = M - 2;
		}
	}
	printf("%d", ans);
	return 0;
}