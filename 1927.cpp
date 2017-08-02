#include <stdio.h>
#include <queue>

int main() {
	int N;
	int i, j;
	int data;
	int ans;
	std::priority_queue<int> pq;

	scanf("%d", &N);
	while (N--) {
		scanf("%d", &data);
		if (data == 0) {
			if (pq.empty()) 
				ans = 0;
			else {
				ans = -pq.top();
				pq.pop();
			}
			printf("%d\n", ans);
		}
		else {
			pq.push(-data);
		}		
	}
	return 0;
}