#include <iostream>
#include <string>
#include <cstring> // strcmp

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);

	string s1, o_s, s2; // o_s : ������ ���ڿ�
	string total = ""; // ����� ���ڿ�
	int len_limit; // loop ó�� �������� loop limit
	int diff; // s1�� s2�� ����.
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
		// ���� ���ڿ��� ���� - 1��ŭ ��� ���ڿ��� 0�� �߰��Ѵ�.
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