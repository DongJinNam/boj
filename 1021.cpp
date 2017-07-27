#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int arr[201][4]; // 점수 기록판
int check[101][4]; // n번째 수가 unique 하다면 check[n] = true, otherwise check[n] = false;

int main() {

	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d %d", &arr[i][1], &arr[i][2], &arr[i][3]);
	}
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= N; j++) {
			check[arr[j][i]][i]++;
		}
	}
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= 3; j++) {
			if (check[arr[i][j]][j] == 1) sum += arr[i][j];
		}
		printf("%d\n", sum);
	}
	return 0;
}