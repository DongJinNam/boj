#include <stdio.h>
#include <queue>

int main() {
	int N, M;
	int cnt = 0,i,j;
	int front;
	std::queue<int> queue;

	scanf("%d %d", &N, &M);	
	for (i = 1; i <= N; i++)
		queue.push(i);

	printf("<");
	while (!queue.empty()) {
		cnt++;
		if (cnt > M) cnt = 1;
		front = queue.front();
		queue.pop();
		if (cnt == M) {
			if (!queue.empty()) printf("%d, ", front);
			else printf("%d", front);
		}
		else {
			queue.push(front);
		}
	}
	printf(">\n");
	return 0;
}