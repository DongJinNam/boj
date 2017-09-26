#include <stdio.h>

int main() {

	int n, i, j;
	int ans = 0, temp;
	bool bErr = false;
	scanf("%d", &n);

	while (n > 0) {		
		temp = n;
		bErr = false;
		while (temp > 0) {
			int mod = temp % 10;
			if (mod != 4 && mod != 7) {
				bErr = true;
				break;
			}
			temp /= 10;
		}
		if (bErr == false) {
			ans = n;
			break;
		}
		n--;
	}
	printf("%d", ans);
	return 0;
}