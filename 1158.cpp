#include <stdio.h>
#include <string.h>
#include <queue>

int main() {
	int N, M;
	int i;
	int limit = 0;
	std::queue<int> queue;
	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
		queue.push(i + 1);
	
	printf("<");
	while (!queue.empty()) {
		limit++;
		if (limit > M) limit = 1;		
		if (limit == M) {
			int front = queue.front();
			queue.pop();	
			if (queue.empty()) printf("%d>\n",front);
			else printf("%d, ", front);
		}
		else {
			int front = queue.front();
			queue.pop();
			queue.push(front);
		}
	}	
	return 0;
}