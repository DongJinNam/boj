#include <iostream>
#include <stack>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	std::stack<int> stk_9;
	cin >> n;
	while (n > 0) {
		stk_9.push(n % 9);
		n /= 9;
	}
	while (!stk_9.empty()) {
		int top = stk_9.top();
		stk_9.pop();
		cout << top;
	}
	return 0;
}