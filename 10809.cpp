#include <stdio.h>
#include <string.h>

int dp[26];

int main() {
	
	char arr[101];
	int i, j, len;

	scanf("%s", arr);

	len = strlen(arr);
	for (i = 0; i < 26; i++) {
		dp[i] = -1;
	}
	for (i = 0; i < len; i++) {
		char comp = arr[i];
		int index = (int)comp - 'a';
		if (dp[index] == -1) dp[index] = i;
	}
	for (i = 0; i < 26; i++) {
		printf("%d ", dp[i]);
	}
	printf("\n");
	return 0;
}