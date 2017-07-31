#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const int &a, const int &b) {
	return a > b ? true : false;
}

int main() {
	int N;
	int ans = 0;
	int i, j, data;
	std::vector<int> arr;
	std::vector<int> arr_m;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &data);
		if (data >= 0) arr.push_back(data);
		else arr_m.push_back(data);
	}

	if (arr.size() > 0) std::sort(arr.begin(), arr.end(), cmp);
	if (arr_m.size() > 0) std::sort(arr_m.begin(), arr_m.end());
	
	// 양수 혹은 0 처리
	int zero_index = -1;
	for (i = 0; i < arr.size(); i += 2) {
		int val1 = arr[i];
		if (val1 == 0) {
			zero_index = i;
			break;
		}
		if (i == arr.size() - 1) {
			ans += val1;
		}
		else {
			int val2 = arr[i + 1];
			if (val2 == 0) {
				ans += val1;
				zero_index = i+1;
				break;
			}
			if (val1 <= 1 || val2 <= 1)
				ans += (val1 + val2);
			else
				ans += (val1*val2);
		}
	}
	// 음수 처리
	for (i = 0; i < arr_m.size(); i += 2) {
		int val1 = arr_m[i];
		if (i == arr_m.size() - 1) {
			if (zero_index == -1) ans += val1; // 양수 벡터에서 0이있는 경우 0을 곱해줘서 음수를 없애버림.
		}
		else {
			int val2 = arr_m[i + 1];
			ans += (val1*val2);
		}
	}
	printf("%d", ans);
	return 0;
}