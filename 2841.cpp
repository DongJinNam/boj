#include <iostream>
#include <stack>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::stack<int> line_stack[7];

	int n, p;
	int i, j, k;
	int ans = 0;
	cin >> n >> p;

	for (i = 0; i < n; i++) {
		int line, pret;
		cin >> line >> pret;

		if (line_stack[line].empty()) {
			line_stack[line].push(pret);
			ans++;
		}
		else {
			int top = line_stack[line].top();
			while (!line_stack[line].empty() && pret < top) { // 현재 퍼렛 번호가 큰 원소들은 스택에서 모두 제거
				line_stack[line].pop();
				ans++;
				if (!line_stack[line].empty()) top = line_stack[line].top(); // 스택에 원소하나라도 있는 경우 top update
			}
			if (!line_stack[line].empty()) {
				top = line_stack[line].top();
				if (top != pret) { // stack의 top 원소와 pret 번호가 다른 경우에만 update
					line_stack[line].push(pret);
					ans++;
				}
			}
			else {
				line_stack[line].push(pret);
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}