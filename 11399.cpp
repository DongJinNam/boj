#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
	int N;
	int index, data, total = 0, temp = 0;
	int i, j, k;
	std::vector<std::pair<int, int>> vecOfData;
	std::vector<std::pair<int, int>>::iterator tempIt;
	
	index = 1;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &data);
		vecOfData.push_back(std::pair<int, int>(data, index));
		index++;
	}

	auto cmp = [](std::pair<int, int> const &a, std::pair<int, int> const &b) {
		return a.first != b.first ? a.first < b.first : a.second < b.second;
	};
	std::sort(vecOfData.begin(), vecOfData.end(), cmp); // map sort
	for (tempIt = vecOfData.begin(); tempIt != vecOfData.end(); tempIt++) {
		temp += tempIt->first;
		total += temp;
	} // waiting value 더하기
	
	printf("%d\n", total); // 총값 출력
	return 0;
}