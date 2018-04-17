#include <stdio.h>
#include <vector>
#include <algorithm>

typedef long long ll;

#define MAX 1000000007
#define MAX_LEN 4000001

ll fact[MAX_LEN], inv[MAX_LEN];
int n, k;
// square and multiply, 페르마의 소정리 (a * a^p-2 = 1 (mod p))
ll power(ll a, ll b) {
	ll ret = 1;
	while (b > 0) {
		if (b % 2) {
			ret *= a;
			ret %= MAX;
		}
		a *= a;
		a %= MAX;
		b /= 2;
	}
	return ret;
}

int main() {	
	scanf("%d %d", &n,&k);

	fact[1] = 1;
	for (int i = 2; i <= n; i++)
		fact[i] = (fact[i - 1] * i) % MAX;
	inv[n] = power(fact[n], MAX - 2);
	for (int i = n - 1; i >= 0; i--)
		inv[i] = (inv[i + 1] * (i + 1)) % MAX;

	ll ans = fact[n];
	ans = (ans * inv[n - k]) % MAX;
	ans = (ans * inv[k]) % MAX;
	printf("%lld\n", ans);
	return 0;
}