#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>

bool bVisitied[10001];

void processing(int result, int index) {
	int temp;
	if (index == 0) {		
		for (int i = 0; i < 10; i++) {
			temp = result + (i << 1);			
			bVisitied[temp] = true;
		}
		return;
	}
	for (int i = 0; i < 10; i++) {
		temp = result + (pow(10, index) + 1) * i; // self number�� �ƴ� ���, bVisited array���� true�� ����
		processing(temp, index - 1);
	}
}

int main() {	
	int i;

	memset(bVisitied, false, sizeof(bool) * 10001); // array initialize
	processing(0, 3); // �Ű������� ������� �ʱⰪ, 10�� n����

	for (i = 1; i <= 10000; i++) {
		if (!bVisitied[i])
			printf("%d\n", i); // self number�� ��� bVisited array index���� false
	}
	return 0;
}