#include <stdio.h>

using namespace std;

int board[51][51];

int main() {

	int n, m, max;
	int i, j, k;
	int ans = 1;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%1d", &board[i][j]);
		}
	}
	max = n < m ? n : m;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			for (k = 1; k < max; k++) {
				int r = -1, b = -1;
				if (j + k < m) 
					r = j + k;
				if (i + k < n)
					b = i + k;
				if (r != -1 && b != -1) {
					if (board[i][j] == board[i][r] && board[i][r] == board[b][r] && board[b][r] == board[b][j]) {
						ans = (k + 1)*(k + 1) > ans ? (k + 1)*(k + 1) : ans;
					}
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}