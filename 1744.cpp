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
	
	// ��� Ȥ�� 0 ó��
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
	// ���� ó��
	for (i = 0; i < arr_m.size(); i += 2) {
		int val1 = arr_m[i];
		if (i == arr_m.size() - 1) {
			if (zero_index == -1) ans += val1; // ��� ���Ϳ��� 0���ִ� ��� 0�� �����༭ ������ ���ֹ���.
		}
		else {
			int val2 = arr_m[i + 1];
			ans += (val1*val2);
		}
	}
	printf("%d", ans);
	return 0;
}