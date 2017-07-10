#include <stdio.h>

int main() {
	int data, i;
	int cnt_5 = 0;
	scanf("%d", &data);
	if (data == 0) printf("0\n");
	else {
		i = 1;
		do {
			i *= 5;
		} while (i < data);
		if (data < 5) printf("0\n");
		else {
			for (i = 5; i <= data; i *= 5) {
				cnt_5 += (data / i);
			}
			printf("%d\n", cnt_5);
		}		
	}
	return 0;
}