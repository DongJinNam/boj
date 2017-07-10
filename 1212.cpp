#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stack>

char arr[1000001];

int main() {
	char ch;
	int index = 0, len = 0, add = 0, i;
	std::stack<char> stack_2; // 2���� ���� ��� stack
	while ((ch = getchar()) && ch != '\n') {
		arr[index] = ch;
		index++;
	}
	len = strlen(arr);
	index = 0;
	add = 0;
	if (len == 1 && arr[0] == '0') printf("0"); // ����ó��
	for (i = len - 1; i >= 0; i--) {
		int num = (int)arr[i] - 48;
		int rmCnt = 3; // num�� 3������ ������ ���, ���� ī��Ʈ��ŭ ���ÿ� '0'�� �ִ´�.
		while (num > 0) {
			int remainder = num % 2;
			num /= 2;
			rmCnt--;
			if (remainder == 1) stack_2.push('1');
			else stack_2.push('0');			
		}
		if (i > 0) {
			while (rmCnt--)
				stack_2.push('0');
		}
	}
	while (!stack_2.empty()) { // 2���� '0' or '1' ���ڰ� ����ִ� stack
		ch = stack_2.top();
		stack_2.pop();
		printf("%c", ch);
	}
	printf("\n");
	return 0;
}