#include <stdio.h>
#include <string.h>
#include <stack>

char arr[600000];

int main() {

	int N;
	int i, j, k, temp, index = 0, len = 0;
	std::stack<char> left, right;
	char c, in, ch;

	scanf("%s", &arr);
	len = strlen(arr);
	for (i = 0; i < len; i++) {
		left.push(arr[i]);
	}

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf(" %c", &c);
		switch (c) {
		case 'P':
			scanf(" %c", &in);
			left.push(in);
			break;
		case 'L':
			if (!left.empty()) {
				ch = left.top();
				left.pop();
				right.push(ch);
			}
			break;
		case 'D':
			if (!right.empty()) {
				ch = right.top();
				right.pop();
				left.push(ch);
			}
			break;
		case 'B':
			if (!left.empty()) {
				ch = left.top();
				left.pop();
			}
			break;
		}
	}
	while (!left.empty()) {
		c = left.top();		
		right.push(c);
		left.pop();
	}
	while (!right.empty()) {
		c = right.top();
		printf("%c", c);
		right.pop();
	}
	printf("\n");
	return 0;
}