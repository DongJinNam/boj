#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int main() {
	std::ios::sync_with_stdio(false);

	string s;
	int N;
	int F;
	int diff = 0;
	int ans = 0;
	int at, at2;
	cin >> s;
	cin >> F;

	N = stoi(s);
	at = (int) s[s.length() - 2] - '0';
	at2 = (int) s[s.length() - 1] - '0';
	diff = 10 * at + at2;

	N -= diff;
	for (int i = N; i < N + 100; i++) {
		if (i % F == 0) {
			ans = i - N;
			break;
		}
	}
	if (ans < 10) printf("0%d\n", ans);
	else printf("%d\n", ans);
	return 0;
}