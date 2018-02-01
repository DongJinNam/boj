#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int n;

	// �Է� ��쿡�� ���� ó���ϰ� �Ǹ� ���� �� �����ϴ� �κ� ���� 2 ������ ��ǻ� �ҽ��� ����
	while ((cin >> n) && !cin.eof()) {
		std::vector<int> num_vec(n);
		std::vector<int> dp;
		for (int i = 0; i < n; i++) {
			cin >> num_vec[i];
		}
		dp.push_back(num_vec[0]);
		for (int i = 0; i < n; i++) {
			if (dp.back() < num_vec[i]) {
				dp.push_back(num_vec[i]);
			}
			else {
				auto it = std::lower_bound(dp.begin(), dp.end(), num_vec[i]);
				*it = num_vec[i];
			}
		}
		cout << dp.size() << "\n";
	}
	return 0;
}