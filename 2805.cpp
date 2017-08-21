#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int inf = 2000000000; // maximum
// 나무 자르기
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
	// 이분탐색 문제
	while (left < right && ans != m) {
		mid = (left + right) / 2;
		ans = 0;
		for (i = 0; i < n; i++) {
			if (vec[i] - mid >= 0) { // mid 값보다 원소값이 큰 경우, 제거하고 남은 값을 더한다.
				ans += (vec[i] - mid);
			}
		}
		if (ans >= m) {
			left = mid + 1;
			if (ans - m < diff) { // 차이가 최소인경우
				diff = ans - m;
				prt = mid; // 출력값
			}
		}
		else {
			right = mid;
		}		
	}
	cout << prt;
	return 0;
}