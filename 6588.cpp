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
	while (1) {
		scanf("%d", &data);
		if (data == 0) break;
		bool bFind = false;
		for (i = 1; i < pn; i++) {
			if (prime[i] > data) break;
			if (bCheck[data - prime[i]] == false) { // �� �� �Ҽ��� ���
				printf("%d = %d + %d\n", data, prime[i], data - prime[i]);
				bFind = true;
				break;
			}
		}
		if (!bFind) printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}