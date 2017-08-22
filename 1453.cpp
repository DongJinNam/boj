#include <iostream>

using namespace std;

bool check[101];

int main() {
	std::ios::sync_with_stdio(false);
	int n, i, j, in, ans = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> in;
		if (check[in]) ans++;
		else check[in] = true;		
	}
	cout << ans;
	return 0;
}