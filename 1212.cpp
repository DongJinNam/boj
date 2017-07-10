#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stack>

char arr[1000001];

int main() {
	char ch;
	int index = 0, len = 0, add = 0, i;
	std::stack<char> stack_2; // 2진수 수를 담는 stack
	while ((ch = getchar()) && ch != '\n') {
		arr[index] = ch;
		index++;
	}
	len = strlen(arr);
	index = 0;
	add = 0;
	if (len == 1 && arr[0] == '0') printf("0"); // 예외처리
	for (i = len - 1; i >= 0; i--) {
		int num = (int)arr[i] - 48;
		int rmCnt = 3; // num을 3번까지 못나눈 경우, 남은 카운트만큼 스택에 '0'을 넣는다.
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
	while (!stack_2.empty()) { // 2진수 '0' or '1' 문자가 들어있는 stack
		ch = stack_2.top();
		stack_2.pop();
		printf("%c", ch);
	}
	printf("\n");
	return 0;
}