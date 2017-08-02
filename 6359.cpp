#include <stdio.h>
#include <string.h>

bool check[101];

int main() {
	int tc;
	int i, j;
	int n;
	int mem = 0;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		memset(check, false, sizeof(bool) * 101);
		mem = 0;
		for (i = 2; i <= n; i++) {
			for (j = i; j <= n; j += i) {
				check[j] = check[j] == true ? false : true;
			}
		}
		for (i = 1; i <= n; i++) {
			if (check[i] == false) mem++;
		}
		printf("%d\n", mem);
	}
	return 0;
}