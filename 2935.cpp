#include <iostream>
#include <string>
#include <cstring> // strcmp

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);

	string s1, o_s, s2; // o_s : 연산자 문자열
	string total = ""; // 출력할 문자열
	int len_limit; // loop 처리 과정에서 loop limit
	int diff; // s1과 s2의 차이.
	cin >> s1 >> o_s >> s2;

	if (strcmp(o_s.c_str(), "*") == 0) {		
		if (s1.length() > s2.length()) {
			total = s1;
			len_limit = s2.length();
		}
		else {
			total = s2;
			len_limit = s1.length();
		}
		// 작은 문자열의 길이 - 1만큼 결과 문자열에 0을 추가한다.
		for (int i = 0; i < len_limit - 1; i++)
			total += "0";
	}
	else {		
		if (s1.length() > s2.length()) {
			total = s1;
			diff = s1.length() - s2.length();
			len_limit = s1.length();
		}
		else {
			total = s2;
			diff = s2.length() - s1.length();
			len_limit = s2.length();
		}
		for (int i = diff; i < len_limit; i++) {
			char val;
			if (s1.length() > s2.length()) val = s1[i] + s2[i - diff] - '0';
			else val = s1[i - diff] + s2[i] - '0';
			total[i] = val;
		}
	}
	cout << total << "\n";
	return 0;
}