#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);

	string s;
	cin >> s;	
	int target = stoi(s);
	int i, j;
	int prt = 0;
	bool bTrue = false;
	// brute force
	for (i = target - 54; i < target; i++) {
		int temp = i;
		int digit = 0;
		int ans = 0;
		int comp = 0;
		std::stack<int> stack;		
		while (temp > 0) {
			stack.push(temp % 10);
			temp /= 10;
			digit++;
		}
		while (!stack.empty()) {
			int top = stack.top();
			ans += top * std::pow(10,(digit-1));
			comp += top * std::pow(10, (digit - 1));
			comp += top;
			digit--;
			stack.pop();
		}
		if (comp == target) {
			bTrue = true;
			prt = ans;
			break;
		}
	}
	if (bTrue) cout << prt;
	else cout << "0";
	return 0;
}