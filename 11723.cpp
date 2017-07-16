#include <stdio.h>
#include <string.h>

int main() {	
	// �̹����� cin ���� �ð� �ʰ��� �߻��Ѵ�. �׷��� ������, printf, scanf �� ����ؾ� �Ѵ�.
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