#include <stdio.h>

int main() {
	int x[3], y[3];
	int ans;
	for (int i = 0; i < 3; i++)
		scanf("%d %d", &x[i], &y[i]);
	
	// CGW
	// ���͸� �̿��� �ﰢ�� ���� ���ϱ� ����� ���� �ð� �ݽð� ���� �ǵ� ����
	ans = (x[0] * y[1] + x[1] * y[2] + x[2]*y[0]) - (x[1] * y[0] + x[2] * y[1] + x[0] * y[2]);
	if (ans > 0) printf("1\n"); // �ݽð�
	else if (ans < 0) printf("-1\n"); // �ð�
	else printf("0\n"); // ������
	return 0;
}