#include <iostream>
#include <string>

using namespace std;

int N;

int go(int size, string s) {
	int rtn = 0;
	if (size == N) {
		int total = 0;
		for (int i = 0; i < s.length(); i++) {
			int val = (int)(s[i] - '0');
			total += val;
		}
		if (total % 3 == 0) rtn++;
		return rtn;
	}
	for (int i = 0; i <= 2; i++) {
		char at = '0' + i;
		string next_s = s + at;
		rtn += go(size + 1, next_s);
	}
	return rtn;
}

// �ȴٺ��� ��õ�� �� (�ڸ� ������ �־����� 0,1,2�� ���� �� �ִ� 3�� ��� ���� ���ϱ�) (Small)
int main() {
	std::ios::sync_with_stdio(false);
	int ans = 0;
	int i, j;

	cin >> N;
	if (N > 1) {
		for (i = 1; i <= 2; i++) {
			char at = '0' + i;
			string s;
			s.push_back(at);
			ans += go(1, s);
		}
	}
	else {
		for (i = 0; i <= 2; i++) {
			char at = '0' + i;
			string s;
			s.push_back(at);
			ans += go(1, s);
		}
	}
	cout << ans << endl;
	return 0;
}