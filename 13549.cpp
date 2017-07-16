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
		if (front - 1 >= 0) { // -1 �̵�
			if (check[front - 1]) { // �̹� ������ �ִ�.
				dp[front - 1] = dp[front] + 1 < dp[front - 1] ? dp[front] + 1 : dp[front - 1]; // �迭 ������Ʈ �������� ����
			}
			else {
				check[front - 1] = true; // �湮 �Ϸ�
				dp[front - 1] = dp[front] + 1; // front - 1 ���� ���µ� �ɸ� �ּҽð�
				queue.push(front - 1); // ť�� �ִ´�.
			}
		}
		if (front + 1 < MAX) { // + 1 �̵�
			if (check[front + 1]) {
				dp[front + 1] = dp[front] + 1 < dp[front + 1] ? dp[front] + 1 : dp[front + 1];
			}
			else {
				check[front + 1] = true;
				dp[front + 1] = dp[front] + 1;
				queue.push(front + 1);
			}
		}
		if ((front << 1) < MAX) { // 2�� �̵�
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