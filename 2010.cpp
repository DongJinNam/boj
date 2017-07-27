#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
	int N;
	int total = 0;
	int data;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {		
		scanf("%d", &data);
		total += data;
	}
	total -= (N - 1);
	printf("%d\n", total);
	return 0;
}