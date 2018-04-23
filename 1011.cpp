#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> iPair;
typedef long long ll;

using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		ll x, y;
		ll diff;
		ll total = 0;
		scanf("%lld %lld", &x, &y);


		if (x + 1 == y) {
			printf("1\n");
			continue;
		}

		diff = y - x;		
		for (ll i = 1;; i++) {
			total += i;
			if (diff <= total) {
				printf("%lld\n", 2 * i - 1);
				break;
			}
			total += i;
			if (diff <= total) {
				printf("%lld\n", 2 * i);
				break;
			}
		}
	}
	return 0;
}