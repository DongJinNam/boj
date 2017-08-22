#include <stdio.h>

typedef long long ll;

int main() {
	ll n, rmd;
	int ans = 0;
	scanf("%lld", &n);

	rmd = n % 5;
	if (rmd == 0 || rmd == 2) ans = 0;
	else ans = 1;
	if (ans == 1) printf("SK");
	else printf("CY");
	return 0;
}