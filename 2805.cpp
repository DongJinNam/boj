#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int inf = 2000000000; // maximum
// ���� �ڸ���
int main() {
	int n,m,i;
	cin >> n >> m;
	std::vector<int> vec(n, 0);
	for (i = 0; i < n; i++)
		cin >> vec[i];
	int left = 0;	
	int right = inf;
	int mid;
	int prt = 0;
	ll total = 0, ans = 0, diff = inf;
	// �̺�Ž�� ����
	while (left < right && ans != m) {
		mid = (left + right) / 2;
		ans = 0;
		for (i = 0; i < n; i++) {
			if (vec[i] - mid >= 0) { // mid ������ ���Ұ��� ū ���, �����ϰ� ���� ���� ���Ѵ�.
				ans += (vec[i] - mid);
			}
		}
		if (ans >= m) {
			left = mid + 1;
			if (ans - m < diff) { // ���̰� �ּ��ΰ��
				diff = ans - m;
				prt = mid; // ��°�
			}
		}
		else {
			right = mid;
		}		
	}
	cout << prt;
	return 0;
}