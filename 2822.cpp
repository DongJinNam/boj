#include <stdio.h>
#include <algorithm>
#include <vector>

bool cmp(std::pair<int, int> lhs, std::pair<int, int> rhs) {
	if (lhs.first < rhs.first) return true;
	else if (lhs.first == rhs.first && lhs.second < rhs.second) return true;
	else return false;
}

int main() {
	int in, sum = 0;
	std::vector<std::pair<int,int>> arr(8);
	std::vector<int> order(5);
	for (int i = 0; i < 8; i++) {
		scanf("%d", &in);
		arr[i].first = in;
		arr[i].second = i + 1;
	}
	std::sort(arr.begin(), arr.end(), cmp);
	for (int i = 3; i < 8; i++) {
		order[i - 3] = arr[i].second;
		sum += arr[i].first;
	}	
	std::sort(order.begin(), order.end());
	printf("%d\n", sum);
	for (int i = 0; i < 4; i++) {
		printf("%d ", order[i]);
	}
	printf("%d\n", order[4]);
	return 0;
}