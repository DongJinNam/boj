#include <stdio.h>
#include <vector>
#include <algorithm>

// first 기준 오름차순 정렬, second 기준 오름차순 정렬
bool cmp(std::pair<int, int> lhs, std::pair<int,int> rhs) {
	if (lhs.first < rhs.first) return true;
	else if (lhs.first == rhs.first && lhs.second < rhs.second) return true;
	else return false;
}

int main() {

	int N;
	std::vector<std::pair<int, int>> vec;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		vec.push_back(std::pair<int, int>(y, x));
	}
	std::sort(vec.begin(), vec.end(), cmp);
	for (int i = 0; i < N; i++) {
		printf("%d %d\n", vec.at(i).second, vec.at(i).first);
	}
	return 0;
}