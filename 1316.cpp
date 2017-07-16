#include <string.h>
#include <string>
#include <iostream>

using namespace std;

bool alpha[26]; // index 별 알파벳이 단어내에서 존재하면 true, 그렇지 않음 false

int main() {
	std::ios::sync_with_stdio(false);
	int N;
	int cnt = 0;
	cin >> N;
	while (N--) {
		std::string s;
		cin >> s;

		memset(alpha, false, sizeof(bool) * 26); // 메모리 초기화
		bool bError = false;
		char prev = s.at(0);
		for (char c : s) {
			if (alpha[c - 'a'] == false) {
				alpha[c - 'a'] = true;
			}
			else {
				if (prev != c) {
					bError = true;
					break;
				}				
			}		
			prev = c;
		}
		if (!bError) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}