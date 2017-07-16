#include <stdio.h>
#include <string.h>

int main() {	
	// 이문제는 cin 사용시 시간 초과가 발생한다. 그렇기 때문에, printf, scanf 를 사용해야 한다.
	int M;
	int i_data;
	unsigned long long data = 0;
	char str[7];

	scanf("%d", &M);
	while (M--) {
		scanf("%s", str);
		if (!strcmp(str, "all")) {
			data = (1 << 20) - 1;
		}
		else if (!strcmp(str, "empty")) {
			data = 0;
		}
		else if (!strcmp(str, "add")) {
			scanf("%d", &i_data);
			data |= (1 << i_data - 1);
		}
		else if (!strcmp(str, "remove")) {
			scanf("%d", &i_data);
			data &= ~(1 << i_data - 1);
		}
		else if (!strcmp(str, "check")) {
			scanf("%d", &i_data);
			if (data & (1 << i_data - 1)) printf("1\n");
			else printf("0\n");
		}
		else if (!strcmp(str, "toggle")) {
			scanf("%d", &i_data);
			data ^= (1 << i_data - 1);
		}	
	}
	return 0;
}