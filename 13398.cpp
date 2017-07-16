#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>

#define MAX 100001

int left[MAX]; // index 위치에서 왼쪽으로 부터 오는 최대 연속합.
int right[MAX]; // index 위치에서 오른쪽으로 부터 오는 최대 연속합.
int arr[MAX];

int main() {

	int N;
	int i, j, k;
	long long total = LONG_MIN;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	// left 연속합 구하기
	left[0] = arr[0];
	for (i = 1; i < N; i++) {
		left[i] = left[i - 1] + arr[i] > arr[i] ? left[i - 1] + arr[i] : arr[i];
	}

	right[N - 1] = arr[N - 1];
	for (i = N - 2; i >= 0; i--) {
		right[i] = right[i + 1] + arr[i] > arr[i] ? right[i + 1] + arr[i] : arr[i];
	}

	if (N == 1) printf("0\n");
	else {
		// 가장 left, right 비교
		for (i = 0; i < N; i++) {
			if (i == 0) {
				total = right[1] > total ? right[1] : total;
			}
			else if (i == N - 1) {
				total = left[N - 2] > total ? left[N - 2] : total;
			}
			else {
				total = left[i - 1] + right[i + 1] > total ? left[i - 1] + right[i + 1] : total;
			}
			total = left[i] > total ? left[i] : total;
		}
		printf("%lld\n", total);
	}
	return 0;
}