#include <stdio.h>
#include <queue>

int main() {

	int N, i, j;
	int opt;
	int ans;
	std::priority_queue<int> pq;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &opt); 
		if (opt == 0) {
			if (pq.empty()) printf("0\n");			
			else {
				ans = pq.top();
				pq.pop();
				printf("%d\n", ans);
			}
		}
		else {
			pq.push(opt);
		}		
	}
	return 0;
}