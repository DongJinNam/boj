#include <stdio.h>
#include <algorithm>

int main() {

	int tc;
	int a, b;
	scanf("%d", &tc);
	// �̷��� Ǯ�� �ð��� �ʹ� �����ɸ���. (�����������)
	while (tc--) {
		scanf("%d %d", &a, &b);
		int test = 1;
		for (int i = 1; i <= b; i++) {
			test *= a;
			test %= 10;
		}		
		if (test != 0)
			printf("%d\n", test);
		else
			printf("10\n");
	}
	return 0;
}