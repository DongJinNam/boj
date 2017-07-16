#include <stdio.h>
#include <string>
#include <bitset>

int arr[20];
std::bitset<20> bit; // bitset ����ؼ� �����ذ���.

int main() {

	int i, j, k;
	int N, S;

	long long total = 0;
	int cnt = 0; // ���� S�� �Ǵ� �κ����� ����

	scanf("%d %d", &N, &S);

	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < (1 << N); i++) {
		bit = i;
		total = 0;
		if (i > 0) {
			for (j = 0; j < N; j++) {
				if (bit[j]) {
					total += arr[j];
				}
			}
			if (total == S) cnt++;
		}		
	}
	printf("%d\n", cnt);
	return 0;
}