#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stack>

int main() {
	int N;
	std::stack<int> rmstk; // -2로 나눌때마다 나머지를 모아두는 스택.
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
			if (N > 0) { // N 양수
				N = N / -2;
			}
			else { // N 음수
				if (a_N % 2 == 1) a_N++; // 홀수인 경우 1 증가시킴
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