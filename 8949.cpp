#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	string s1,s2;
	std::queue<int> queue;
	int i;
	cin >> s1 >> s2;
	if (s1.length() > s2.length()) {
		while (s2.length() < s1.length()) s2.insert(0, "0");
	}
	else if (s2.length() > s1.length()) {
		while (s1.length() < s2.length()) s1.insert(0, "0");		
	}
	for (i = 0; i < s1.length(); i++) {
		int i1 = s1[i] - '0';
		int i2 = s2[i] - '0';
		queue.push(i1 + i2);
	}
	while (!queue.empty()) {
		printf("%d", queue.front());
		queue.pop();
	}
	return 0;
}