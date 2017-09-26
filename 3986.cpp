#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int n, i ,j;
	int ans = 0;
	cin >> n;

	for (i = 0; i < n; i++) {
		string s;		
		std::stack<char> ch_stk;
		cin >> s;

		bool is_legal = true;
		int str_len = s.length();

		for (j = 0; j < str_len; j++) {
			char ch = s[j];

			if (ch_stk.size() > str_len - j) {
				is_legal = false;
				break;
			}
			if (ch_stk.size() == 0) ch_stk.push(ch);
			else if (ch_stk.top() == ch) ch_stk.pop();
			else ch_stk.push(ch);
		}
		if (!ch_stk.empty()) is_legal = false;
		if (is_legal) ans++;
	}
	cout << ans;
	return 0;
}

