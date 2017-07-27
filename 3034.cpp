#include <stdio.h>

int main() {
	int N, W, H;
	int i, in_data;
	scanf("%d %d %d", &N, &W, &H);
	for (i = 0; i < N; i++) {
		scanf("%d", &in_data);
		if (W*W + H*H >= in_data * in_data) printf("DA\n");
		else printf("NE\n");
	}
	return 0;
}