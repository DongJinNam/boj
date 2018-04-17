#include <iostream>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> iPair;

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);
	int n;
	std::vector<iPair> pos_vec;
	cin >> n;
	pos_vec.resize(n, make_pair(0, 0));
	for (int i = 0; i < n; i++) {
		cin >> pos_vec[i].first;
		pos_vec[i].second = 0;
	}
	int next = 0;
	for (int i = 0; i < n-1; i++) {
		int val = pos_vec[next].first;
		int prev = next;
		int count = 0;
		int cur = next % n;
		pos_vec[next].second = 1;
		if (val > 0) {
			while (count < val) {
				cur = (cur + 1) % n;
				if (pos_vec[cur].second == 0) {
					count++;
				}				
			}
			next = cur;
		}
		else {
			while (count < -val) {
				cur = (cur - 1) % n;
				if (cur < 0) cur = (n + cur) % n;
				if (pos_vec[cur].second == 0) {
					count++;
				}
			}
			next = cur;
		}
		cout << prev + 1 << " ";
	}
	cout << next + 1 << "\n";
	return 0;
}