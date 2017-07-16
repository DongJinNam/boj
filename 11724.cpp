#include <stdio.h>
#include <string.h>

#define MAX 1001

bool board[MAX][MAX]; // Adjacency Matrix
bool visited[MAX]; // 방문 여부 체크
int check[MAX]; // 어느 구성요소에 속하는지 표시
int N;

void dfs(int count, int start) {
	for (int i = 1; i <= N; i++) {
		if (visited[i] == false && board[start][i] == true) {
			visited[i] = true;
			check[i] = count;
			dfs(count,i);
		}
	}
}

int main() {

	int M;
	int i;
	int cnt = 0; // 연결 요소 개수
	scanf("%d %d", &N, &M);

	for (i = 0; i < M; i++) {
		int data1, data2;
		scanf("%d %d", &data1, &data2);
		board[data1][data2] = true;
		board[data2][data1] = true;
	}
	for (i = 1; i <= N; i++) {
		if (check[i] == 0) {
			memset(visited, false, sizeof(bool)*MAX);
			visited[i] = true;
			check[i] = ++cnt;
			dfs(cnt,i);
		}
	}
	printf("%d\n", cnt);
	return 0;
}