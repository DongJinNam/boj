#include <stdio.h>
#include <string.h>

int main() {
	char arr[101];
	int i, len;

	fgets(arr, 101, stdin);

	len = strlen(arr);

	for (i = 0; i < len; i++) {
		unsigned char cur = arr[i];
		unsigned char ch = arr[i];

		if ('A' <= cur && cur <= 'Z') {
			ch = (char)cur + 13;
			if (ch > 'Z') ch = (char)ch - 26;
		}
		else if ('a' <= cur && cur <= 'z') {
			ch = (char)cur + 13;
			if (ch > 'z') ch = (char)ch - 26;
		}
		printf("%c", ch);
	}
	printf("\n");
	return 0;
}