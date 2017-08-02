#include <stdio.h>
#include <vector>

using namespace std;

int ans[1001];
std::vector<int> arr[1001];

void find_ans(int index) {
	int first, second, third;
	int i, j, k;
	for (i = 0; i < 3; i++) {
		first = arr[index][i];
		for (j = i + 1; j < 4; j++) {
			second = arr[index][j];
			for (k = j + 1; k < 5; k++) {
				third = arr[index][k];
				ans[index] = ((first + second + third) % 10) > ans[index] ? ((first + second + third) % 10) : ans[index];
			}
		}
	}
}

int main() {

	int N;
	int i, j, k;
	int in;
	int max_index;	
	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= 5; j++) {
			scanf("%d", &in);
			arr[i].push_back(in);
		}
	}
	for (i = 1; i <= N; i++) 
		find_ans(i);
	max_index = N;
	for (i = N-1; i > 0; i--) 
		if (ans[i] > ans[max_index]) max_index = i;	
	printf("%d", max_index);
	return 0;
}