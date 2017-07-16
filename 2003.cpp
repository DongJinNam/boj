#include <stdio.h>
#include <vector>

int main() {
	int N;
	long long M, total = 0, cnt = 0;
	int i_data;
	int i, j;

	scanf("%d %lld", &N, &M);

	std::vector<long long> arr(N);

	for (i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}

	total = 0;
	cnt = 0;
	for (i = 0; i < N; i++) {
		total = 0;
		for (j = i; j < N; j++) {			
			if (total > M) break; // 큰 경우
			total += arr[j];
			if (total == M) { // 목표와 일치하는 경우
				cnt++; // 카운트 증가				
				break;
			}			
		}
	}
	printf("%lld\n", cnt);
	return 0;
}