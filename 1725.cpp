#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

int main() {
	// histogram
	stack<int> stack;
	int n, i, j;
	int max = 0, count = 0, top = 0;
	scanf("%d", &n);
	vector<int> num_arr(n + 1, 0);
	for (i = 0; i < n; i++) 
		scanf("%d", &num_arr[i]);

	stack.push(num_arr[0]);
	for (i = 1; i < n; i++) {
		top = stack.top();
		if (top > num_arr[i]) { // 스택의 top값이 원소값보다 큰 경우
			count = 0;		
			while (!stack.empty()) {
				top = stack.top();
				if (top <= num_arr[i]) break; // 스택 top값이 원소값보다 큰 경우일 때 최대 넓이 계산.
				stack.pop();
				count++;
				max = top * count > max ? top * count : max;
			}
			for (j = 0; j < count; j++) 
				stack.push(num_arr[i]); // 추후를 고려하여, num_arr[i]값만큼의 원소값을 모두 stack에 넣어줌.			
		}
		stack.push(num_arr[i]);
	}
	count = 0;
	while (!stack.empty()) { // stack에 남은 원소들 처리.
		top = stack.top();
		stack.pop();
		count++;
		max = top * count > max ? top * count : max;
	}
	printf("%d", max);
	return 0;
}