#include <stdio.h>

int main() {
	int x[3], y[3];
	int ans;
	for (int i = 0; i < 3; i++)
		scanf("%d %d", &x[i], &y[i]);
	
	// CGW
	// 벡터를 이용한 삼각형 면적 구하기 방식을 통해 시계 반시계 방향 판독 가능
	ans = (x[0] * y[1] + x[1] * y[2] + x[2]*y[0]) - (x[1] * y[0] + x[2] * y[1] + x[0] * y[2]);
	if (ans > 0) printf("1\n"); // 반시계
	else if (ans < 0) printf("-1\n"); // 시계
	else printf("0\n"); // 일직선
	return 0;
}