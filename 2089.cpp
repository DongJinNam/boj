#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stack>

int main() {
	int N;
	std::stack<int> rmstk; // -2�� ���������� �������� ��Ƶδ� ����.
	scanf("%d", &N);	
	if (N == 0) {
		printf("0\n");
	}
	else {
		while (N != 1) {
			int a_N = abs(N);
			if (a_N % 2 == 0) {
				rmstk.push(0);
			}
			else {
				rmstk.push(1);
			}
			if (N > 0) { // N ���
				N = N / -2;
			}
			else { // N ����
				if (a_N % 2 == 1) a_N++; // Ȧ���� ��� 1 ������Ŵ
				N = a_N / 2;
			}
		}
		printf("1");
		while (!rmstk.empty()) {
			printf("%d", rmstk.top());
			rmstk.pop();
		}
		printf("\n");
	}
	return 0;
}