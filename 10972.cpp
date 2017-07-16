#include <stdio.h>
#include <algorithm>
#include <vector>

int main() {
	int N;
	int i, j, k;
	scanf("%d", &N);

	std::vector<int> vec(N);
	for (i = 0; i < N; i++)
		scanf("%d", &vec[i]);

	if (std::next_permutation(vec.begin(), vec.end())) { // 다음순열이 있다면.
		for (int tmp : vec) {
			printf("%d ", tmp);
		}
		printf("\n");
	}
	else { // 다음순열이 없는 경우
		printf("-1\n");
	}
	return 0;
}