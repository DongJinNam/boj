#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
	unsigned long long N = 0;
	int B, remainder, len, num;
	int i;
	char ch;
	char arr[101];

	scanf("%s %d", &arr, &B);
	len = strlen(arr);
	for (i = len - 1; i >= 0; i--) {
		ch = arr[i];
		if ('0' <= ch && ch <= '9') num = (int)ch - 48;
		else num = (int)ch - 55;
		N += num * pow(B, len - 1 - i);
	}
	printf("%llu\n",N);
	return 0;
}