#include <stdio.h>
#include <string.h>
#include <stack>
#include <algorithm>

char arr[100001]; // 입력받을 문자열

int main() {

	int total = 0, extra = 0; // 총 생기는 조각의 개수, 여분의 조각 개수
	int depth = 0, index = 0, temp = 0; // 깊이, 인덱스, 임시 변수
	char before, b, c; // 이전 문자, stack의 top 문자, 현재 문자
	std::stack<char> stack; // 쇠막대기 문제에서 사용할 stack

	scanf("%s", &arr);

	c = arr[index];
	extra = 0;
	while (arr[index] != '\0') {
		c = arr[index];
		if (c == '(') { // 열기
			depth++; // 사실상 stack size라 봐도 무방
			stack.push('(');
		}
		else { // 닫기
			b = stack.top();
			stack.pop();			
			depth--; // 사실상 stack size라 봐도 무방
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