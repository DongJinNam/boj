#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
	int N, data;
	int cor_cnt = 0; // correct count
	std::vector<int> vec_mem;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		cor_cnt = 0;
		for (int j = 1; j <= 10; j++) {
			scanf("%d", &data);
			if (data == ((j - 1) % 5) + 1) cor_cnt++;
		}
		if (cor_cnt == 10) vec_mem.push_back(i);
	}
	for (int i = 0; i < vec_mem.size(); i++)
		printf("%d\n", vec_mem[i]);
	return 0;
}