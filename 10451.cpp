#include <stdio.h>
#include <string.h>

int cnt = 0; // 순열 사이클 개수
int arr[1001];
bool check[1001]; // 방문한 점인지 아닌지.

void go(int data, int end) {
	if (data == end) {
		cnt++;
		return;
	}
	go(arr[data], end);
	check[data] = true;
}

int main() {
	int tc;
	int i, j, k;

	scanf("%d", &tc);
	while (tc--) {

		int arr_cnt;
		scanf("%d", &arr_cnt);
		for (i = 1; i <= arr_cnt; i++)
			scanf("%d", &arr[i]);

		cnt = 0;
		memset(check, false, sizeof(bool) * 1001);

		for (i = 1; i <= arr_cnt; i++) {
			if (check[i] == false) {
				go(arr[i], i);
				check[i] = true;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}