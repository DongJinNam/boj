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
			if (total > M) break; // ū ���
			total += arr[j];
			if (total == M) { // ��ǥ�� ��ġ�ϴ� ���
				cnt++; // ī��Ʈ ����				
				break;
			}			
		}
	}
	printf("%lld\n", cnt);
	return 0;
}