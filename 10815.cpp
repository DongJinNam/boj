#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <vector>

bool dp[10000001]; // 양수
bool dp2[10000001]; // 음수

int main() {

	int N, M;
	int data;
	std::vector<int> ans_vec;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &data);
		if (data >= 0) {
			dp[data] = true;
		}
		else {
			data = (int) std::abs(data);
			dp2[data] = true;
		}
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &data);
		if (data >= 0) {
			if (dp[data] == true) ans_vec.push_back(1);
			else ans_vec.push_back(0);
		}
		else {
			data = (int)std::abs(data);
			if (dp2[data] == true) ans_vec.push_back(1);
			else ans_vec.push_back(0);
		}
	}
	for (int i = 0; i < M; i++) {
		printf("%d ", ans_vec[i]);
	}
	printf("\n");
	return 0;
}