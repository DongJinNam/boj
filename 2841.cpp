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
			while (!line_stack[line].empty() && pret < top) { // ���� �۷� ��ȣ�� ū ���ҵ��� ���ÿ��� ��� ����
				line_stack[line].pop();
				ans++;
				if (!line_stack[line].empty()) top = line_stack[line].top(); // ���ÿ� �����ϳ��� �ִ� ��� top update
			}
			if (!line_stack[line].empty()) {
				top = line_stack[line].top();
				if (top != pret) { // stack�� top ���ҿ� pret ��ȣ�� �ٸ� ��쿡�� update
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