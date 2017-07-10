#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define MAX 1000000

int prime[MAX + 1]; // �Ҽ����� ��� �迭
bool bCheck[MAX + 1]; // index�� �Ҽ��� false, �Ҽ��� �ƴϸ� true (��, index >= 2 �����Ͽ�)

int main() {
	int data;
	unsigned long long i, j;
	int pn = 0; // �Ҽ� ����
	for (i = 2; i <= MAX; i++) { // �����佺�׳׽��� ü
		if (bCheck[i] == false) {
			prime[pn++] = i;
			for (j = i * i; j <= MAX; j += i) {
				bCheck[j] = true; // bCheck[i] : true -> �Ҽ��� �ƴ�. bCheck[i] : false : �Ҽ�
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