#include <stdio.h>
#include <vector>
#include <algorithm>

bool cmp(std::pair<int, int> lp, std::pair<int, int> rp) {
	if (lp.first < rp.first) return true;
	else if (lp.first == rp.first && lp.second < rp.second) return true;
	else return false;
}

int main() {
	int N;
	int x, y;
	std::vector<std::pair<int, int>> vec;
	scanf("%d", &N);

	vec.resize(N);
	for (int i = 0; i < N; i++) {		
		scanf("%d %d", &x, &y);
		vec[i].first = x;
		vec[i].second = y;
	}
	std::sort(vec.begin(), vec.end(), cmp);
	for (int i = 0; i < N; i++) 
		printf("%d %d\n", vec[i].first, vec[i].second);
	return 0;
}