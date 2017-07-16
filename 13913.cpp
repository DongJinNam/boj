#include <stdio.h>
#include <string.h>
#include <queue>

#define MAX 100001

int dp[MAX]; // dynamic programming
int before[MAX]; // �湮 ����.
bool check[MAX]; // check array


void go(int target, int end) { // ����Լ��� ����ؼ� ���������κ��� ������ ������ ��θ� ����Ѵ�.
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
		if (front - 1 >= 0) { // -1 �̵�
			if (check[front - 1]) { // �̹� ������ �ִ�.
				if (dp[front] + 1 < dp[front - 1]) {
					dp[front - 1] = dp[front] + 1;
					before[front - 1] = front;
				}
			}
			else {
				check[front - 1] = true; // �湮 �Ϸ�
				dp[front - 1] = dp[front] + 1; // front - 1 ���� ���µ� �ɸ� �ּҽð�
				queue.push(front - 1); // ť�� �ִ´�.
				before[front - 1] = front;
			}
		}
		if (front + 1 < MAX) { // + 1 �̵�
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
		if ((front << 1) < MAX) { // 2�� �̵�
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
	if (dp[K] > 0) go(K, N); // ���������� �ּҽð��� 0�� ���� �������� �ʴ´�.
	printf("%d\n", K);
	return 0;
}