#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

#define N_MAX 200001
#define H_MAX 500001

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);
	int n, h;
	std::vector<int> ans_vec;
	std::vector<int> h_vec;
	std::vector<int> h2_vec;
	cin >> n >> h;
	h_vec.resize(h + 1, 0);
	h2_vec.resize(h + 1, 0);
	ans_vec.resize(h + 1, 0);
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (i % 2 == 0) {
			h_vec[temp]++;
		}
		else {
			h2_vec[h - temp]++;
		}
	}
	ans_vec[0] = INT_MAX;
	ans_vec[1] = n / 2;
	ans_vec[h] = n / 2;
	for (int i = 2; i < h; i++) {
		ans_vec[i] = ans_vec[i - 1];
		ans_vec[i] -= h_vec[i - 1];
		ans_vec[i] += h2_vec[i - 1];
	}
	std::sort(ans_vec.begin(), ans_vec.end());
	int min = ans_vec[0];
	int count = 0;
	for (int i = 0; i < ans_vec.size(); i++) {
		if (min == ans_vec[i])
			count++;
		else
			break;
	}
	cout << min << " " << count << "\n";
	return 0;
}