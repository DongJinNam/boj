#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int sum[100001] = { 0 };
int num[100001] = { 0 };

int main() {
	std::ios::sync_with_stdio(false);
	int N;
	ll total = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		if (i > 0) sum[i] = sum[i - 1] + num[i];
		else sum[i] = num[i];
	}
	for (int i = 0; i < N - 1; i++) 
		total += (ll)num[i] * (sum[N - 1] - sum[i]);	
	cout << total << "\n";
	return 0;
}

