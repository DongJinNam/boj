#include <iostream>
#include <string>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	// �Ҿ���� ��ȣ
	string s;
	int i;
	cin >> s;

	int prev_index = 0;
	int total = 0, i_temp = 0;
	bool m_find = false;
	bool bMinus = false;

	// -�߰��������� ���� ��� ���Ѵ�.
	for (i = 0; i < s.length(); i++) {
		if (i == s.length() - 1) {
			string temp = s.substr(prev_index, i - prev_index + 1);
			total += stoi(temp);
			break;
		}
		if (s[i] == '+') {
			string temp = s.substr(prev_index, i - prev_index);
			prev_index = i + 1;
			total += stoi(temp);
			bMinus = false;
		}
		else if (s[i] == '-') {
			if (i - prev_index > 0) {
				string temp = s.substr(prev_index, i - prev_index);
				total += stoi(temp);
			}
			bMinus = true;
			prev_index = i + 1;
			break;
		}
	}

	i++;
	i_temp = 0;
	// -�߰� ���Ŀ��� +�߰��� ���� ��� ������ �Ѵ�.
	for (i; i < s.length(); i++) {
		if (i == s.length() - 1) {
			string temp = s.substr(prev_index, i - prev_index + 1);
			i_temp += stoi(temp);
			total -= i_temp;
			break;
		}
		if (s[i] == '+') {
			string temp = s.substr(prev_index, i - prev_index);
			i_temp += stoi(temp);
			prev_index = i + 1;
		}
		else if (s[i] == '-') {
			string temp = s.substr(prev_index, i - prev_index);
			i_temp += stoi(temp);
			total -= i_temp;
			prev_index = i + 1;
			i_temp = 0;
		}
	}
	printf("%d\n", total);
	return 0;
}