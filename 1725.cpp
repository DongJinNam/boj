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
		if (top > num_arr[i]) { // ������ top���� ���Ұ����� ū ���
			count = 0;		
			while (!stack.empty()) {
				top = stack.top();
				if (top <= num_arr[i]) break; // ���� top���� ���Ұ����� ū ����� �� �ִ� ���� ���.
				stack.pop();
				count++;
				max = top * count > max ? top * count : max;
			}
			for (j = 0; j < count; j++) 
				stack.push(num_arr[i]); // ���ĸ� ����Ͽ�, num_arr[i]����ŭ�� ���Ұ��� ��� stack�� �־���.			
		}
		stack.push(num_arr[i]);
	}
	count = 0;
	while (!stack.empty()) { // stack�� ���� ���ҵ� ó��.
		top = stack.top();
		stack.pop();
		count++;
		max = top * count > max ? top * count : max;
	}
	printf("%d", max);
	return 0;
}