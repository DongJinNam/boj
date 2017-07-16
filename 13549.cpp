#include <stdio.h>
#include <string.h>
#include <queue>

#define MAX 100001

int dp[MAX]; // dynamic programming
bool check[MAX]; // check array

int main() {

	int N, K;
	std::queue<int> queue;
	int cnt = 0; // cnt

	scanf("%d %d", &N, &K);

	dp[N] = 0;
	check[N] = true;
	queue.push(N);
	while (!queue.empty()) {	// using BFS
		int front = queue.front();
		queue.pop();
		if (front - 1 >= 0) { // -1 이동
			if (check[front - 1]) { // 이미 흔적이 있다.
				dp[front - 1] = dp[front] + 1 < dp[front - 1] ? dp[front] + 1 : dp[front - 1]; // 배열 업데이트 할지말지 결정
			}
			else {
				check[front - 1] = true; // 방문 완료
				dp[front - 1] = dp[front] + 1; // front - 1 까지 가는데 걸린 최소시간
				queue.push(front - 1); // 큐에 넣는다.
			}
		}
		if (front + 1 < MAX) { // + 1 이동
			if (check[front + 1]) {
				dp[front + 1] = dp[front] + 1 < dp[front + 1] ? dp[front] + 1 : dp[front + 1];
			}
			else {
				check[front + 1] = true;
				dp[front + 1] = dp[front] + 1;
				queue.push(front + 1);
			}
		}
		if ((front << 1) < MAX) { // 2배 이동
			if (check[front << 1]) {
				dp[front << 1] = dp[front] + 1 < dp[front << 1] ? dp[front] + 1 : dp[front << 1];
			}
			else {
				check[front << 1] = true;
				dp[front << 1] = dp[front] + 1;
				queue.push(front << 1);
			}
		}
	}
	printf("%d\n", dp[K]);
	return 0;
}