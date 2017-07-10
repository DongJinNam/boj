#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define MAX 1000000

int prime[MAX + 1]; // 소수들을 담는 배열
bool bCheck[MAX + 1]; // index가 소수면 false, 소수가 아니면 true (단, index >= 2 전제하에)

int main() {
	int data;
	unsigned long long i, j;
	int pn = 0; // 소수 개수
	for (i = 2; i <= MAX; i++) { // 에라토스테네스의 체
		if (bCheck[i] == false) {
			prime[pn++] = i;
			for (j = i * i; j <= MAX; j += i) {
				bCheck[j] = true; // bCheck[i] : true -> 소수가 아님. bCheck[i] : false : 소수
			}
		}
	}

	int data1, data2;
	int start;
	scanf("%d %d", &data1, &data2);

	for (i = 0; i < pn; i++) {
		if (data1 <= prime[i]) {
			start = i;
			break;
		}
	}
	for (i = start; i < pn; i++) {
		if (data2 < prime[i]) {
			break;
		}
		printf("%d\n", prime[i]);
	}
	return 0;
}