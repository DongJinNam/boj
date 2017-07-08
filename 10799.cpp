#include <stdio.h>
#include <string.h>
#include <stack>
#include <algorithm>

char arr[100001]; // �Է¹��� ���ڿ�

int main() {

	int total = 0, extra = 0; // �� ����� ������ ����, ������ ���� ����
	int depth = 0, index = 0, temp = 0; // ����, �ε���, �ӽ� ����
	char before, b, c; // ���� ����, stack�� top ����, ���� ����
	std::stack<char> stack; // �踷��� �������� ����� stack

	scanf("%s", &arr);

	c = arr[index];
	extra = 0;
	while (arr[index] != '\0') {
		c = arr[index];
		if (c == '(') { // ����
			depth++; // ��ǻ� stack size�� ���� ����
			stack.push('(');
		}
		else { // �ݱ�
			b = stack.top();
			stack.pop();			
			depth--; // ��ǻ� stack size�� ���� ����
			if (before == '(') {
				total += (depth + extra);
				extra = 0;
			}
			else {				
				extra++;
			}			
		}
		before = arr[index];
		index++;
	}
	total += extra;
	printf("%d\n", total);
	return 0;
}