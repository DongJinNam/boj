#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stack>

char arr[1000001];

int main() {
	char ch;
	int index = 0, len = 0, add = 0, i;
	std::stack<char> stack_8; // 8진수 수를 담는 stack
	while ((ch = getchar()) && ch != '\n') {
		arr[index] = ch;
		index++;
	}
	len = strlen(arr);
	index = 0;
	add = 0;	
	for (i = len - 1; i >= 0; i--) {
		index++;
		if (index > 3) {
			ch = (char)add + 48;
			stack_8.push(ch);
			index = 1;
			add = 0;
		}
		if (arr[i] == '1') add += pow(2, index - 1);
	}
	if (add > 0) {
		ch = (char)add + 48;
		stack_8.push(ch);
	}
	while (!stack_8.empty()) {
		ch = stack_8.top();
		stack_8.pop();
		printf("%c", ch);
	}
	printf("\n");
	return 0;
}