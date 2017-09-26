#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int main() {

	int n;
	int i, j;
	std::queue<int> q;
	scanf("%d", &n);

	for (i = 1; i <= n; i++) q.push(i);
	bool bPush = false;
	while (q.size() > 1) {
		int top = q.front();
		q.pop();
		if (!bPush) bPush = true;
		else {
			q.push(top);
			bPush = false;
		}
	}
	printf("%d", q.front());	
	return 0;
}