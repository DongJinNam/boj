#include <stdio.h>
#include <string.h>
#include <queue>

#define MAX 100001

int dp[MAX]; // dynamic programming
int before[MAX]; // 방문 흔적.
bool check[MAX]; // check array


void go(int target, int end) { // 재귀함수를 사용해서 시작점으로부터 목적지 전까지 경로를 출력한다.
	if (before[target] == end) {
		printf("%d ", end);
		return;
	}
	go(before[target], end);
	printf("%d ", before[target]);
}

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
				if (dp[front] + 1 < dp[front - 1]) {
					dp[front - 1] = dp[front] + 1;
					before[front - 1] = front;
				}
			}
			else {
				check[front - 1] = true; // 방문 완료
				dp[front - 1] = dp[front] + 1; // front - 1 까지 가는데 걸린 최소시간
				queue.push(front - 1); // 큐에 넣는다.
				before[front - 1] = front;
			}
		}
		if (front + 1 < MAX) { // + 1 이동
			if (check[front + 1]) {
				if (dp[front] + 1 < dp[front + 1]) {
					dp[front + 1] = dp[front] + 1;
					before[front + 1] = front;
				}
			}
			else {
				check[front + 1] = true;
				dp[front + 1] = dp[front] + 1;
				queue.push(front + 1);
				before[front + 1] = front;
			}
		}
		if ((front << 1) < MAX) { // 2배 이동
			if (check[front << 1]) {
				if (dp[front] + 1 < dp[front << 1]) {
					dp[front << 1] = dp[front] + 1;
					before[front << 1] = front;
				}
			}
			else {
				check[front << 1] = true;
				dp[front << 1] = dp[front] + 1;
				queue.push(front << 1);
				before[front << 1] = front;
			}
		}
	}
	printf("%d\n", dp[K]);
	if (dp[K] > 0) go(K, N); // 목적지까지 최소시간이 0인 경우는 추적하지 않는다.
	printf("%d\n", K);
	return 0;
}