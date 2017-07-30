#include <stdio.h>

int main() {

	int N;
	int select = 1;
	int i, j;
	int from, to;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d %d", &from, &to);
		if (select == to) {
			select = from;
		}
		else if (select == from) {
			select = to;
		}
	}
	printf("%d", select);

	return 0;
}