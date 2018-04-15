#include <stdio.h>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> iPair;
typedef long long ll;

using namespace std;

int main() {
	ll n;
	ll left = 10000, right = -10000;
	std::vector<ll> a;
	std::vector<iPair> c_vec(8001, make_pair(0,0));	
	scanf("%lld", &n);

	for (int i = 0; i < 8001; i++) {
		c_vec[i].first = 0;
		c_vec[i].second = i - 4000;
	}

	a.resize(n, 0);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		c_vec[a[i] + 4000].first++;
		left = a[i] < left ? a[i] : left;
		right = a[i] > right ? a[i] : right;
	}
	// »ê¼úÆò±Õ
	ll avg = 0;
	for (int i = 0; i < n; i++) {
		avg += a[i];
	}
	avg *= 10;
	avg /= n;

	if (avg > 0) avg += 5;
	else if (avg < 0) avg -= 5;
	else avg = 0;

	avg /= 10;
	printf("%lld\n", avg);

	// Áß¾Ó°ª.
	std::sort(a.begin(), a.end());
	int mid = (a.size() + 1) / 2;
	if (a.size() % 2 > 0)
		printf("%lld\n", a[mid-1]);
	else 
		printf("%lld\n", (a[mid-1] + a[mid]) / 2);

	// ÃÖºó°ª
	std::sort(c_vec.begin(), c_vec.end(), [](const iPair &a, const iPair &b) {
		if (a.first > b.first) return true;
		else if (a.first == b.first) return a.second < b.second;
		else return false;
	});
	int mode_count = 0;
	int comp = c_vec[0].first;
	for (int i = 0; i < c_vec.size(); i++) {
		if (comp == c_vec[i].first) mode_count++;
		else break;
	}
	if (mode_count > 1)
		printf("%d\n", c_vec[1].second);
	else
		printf("%d\n", c_vec[0].second);

	// ¹üÀ§
	printf("%d\n", right - left);
	return 0;
}