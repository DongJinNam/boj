#include <stdio.h>
#include <algorithm>
#include <vector>

#define MAX 4000001

bool check[MAX]; // true : 소수 아님. false : 소수

int main() {
	int N; // input
	long long i, j, k;
	int l = 0, r = 0;
	int cnt = 0; // 경우의 수
	int pn = 0; // prime number count
	long long sum = 0; // 연속합	
	std::vector<int> vec;

	scanf("%d", &N);

	// 2 ~ N 까지 소수 설정
	for (i = 2; i <= N; i++) {
		if (check[i] == false) {
			vec.push_back(i);
			pn++;
			for (j = i; j <= N; j += i) {
				check[j] = true;
			}
		}
	}

	l = r = 0;
	sum = pn > 0 ? vec[0] : 0;
	while (l <= r && r < vec.size()) {
		if (sum < N) {
			r++;
			if (r < vec.size()) sum += vec[r];
		}
		else if (sum == N) {
			cnt++;
			r++;
			if (r < vec.size()) sum += vec[r];
		}
		else {
			sum -= vec[l];
			l++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}