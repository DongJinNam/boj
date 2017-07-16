#include <stdio.h>
#include <string.h>

#define MAX 101

int board[MAX][MAX];
bool bCheck[MAX][MAX];
bool bVisited[MAX];
int N;

void dfs(int prev, int start) {
	for (int i = 1; i <= N; i++) {
		if (bCheck[start][i] == false && board[start][i] > 0) {
			bCheck[start][i] = true;
			bVisited[i] = true;
			dfs(prev, i);
		}
	}
}

int main() {
	int i, j, k;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			int i_data;
			scanf("%d", &i_data);
			if (i_data == 1) {
				board[i][j] = true;
			}
		}
	}
	for (i = 1; i <= N; i++) {
		memset(bCheck, false, sizeof(bool)*MAX*MAX); // 방문 내역 기록을 위해 만듬
		memset(bVisited, false, sizeof(bool)*MAX); // 시작점을 기준으로해서 dfs를 돌릴때 방문한 점들을 모두 check 한다.
		dfs(i,i);
		for (j = 1; j <= N; j++) {
			if (bVisited[j]) printf("1 ");
			else printf("0 ");
		}
		printf("\n");
	}
	return 0;
}