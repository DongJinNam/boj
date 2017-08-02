#include <stdio.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>

int main() {

	int N;
	int i, j;
	int select;
	int num = 0;
	bool bSuccess = true;
	scanf("%d", &N);

	std::vector<int> arr(N);
	std::queue<char> opt_q;
	std::stack<int> stack;
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	select = 0;
	while (opt_q.size() < 2*N && num <= N) {

		if (stack.empty()) {
			stack.push(++num);
			opt_q.push('+');
		}
		else {
			if (stack.top() == arr[select]) {
				stack.pop();
				opt_q.push('-');
				select++;
			}
			else {
				stack.push(++num);
				opt_q.push('+');
			}
		}
	}
	if (num > N) {
		printf("NO");
	}
	else {
		while (!opt_q.empty()) {
			char front = opt_q.front();
			opt_q.pop();
			printf("%c\n", front);
		}
	}
	return 0;
}