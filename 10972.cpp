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

	if (std::next_permutation(vec.begin(), vec.end())) { // ���������� �ִٸ�.
		for (int tmp : vec) {
			printf("%d ", tmp);
		}
		printf("\n");
	}
	else { // ���������� ���� ���
		printf("-1\n");
	}
	return 0;
}