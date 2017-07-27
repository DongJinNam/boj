#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(std::pair<int, int> lhs, std::pair<int, int> rhs) {
	if (lhs.second < rhs.second) return true;
	else if (lhs.second == rhs.second && lhs.first < rhs.first) return true;
	else return false;
}

int main() {
	std::ios::sync_with_stdio(false);
	int N, M;
	std::vector<std::pair<int, int>> ord_vec;
	cin >> N >> M;
	while (N--) {
		string s;
		int table_num, time;
		int select = -1; // ¼±ÅÃÇÒ index
		cin >> s;
		if (strcmp(s.c_str(), "order") == 0) {
			cin >> table_num >> time;
			ord_vec.push_back(std::pair<int, int>(table_num, time));
		}
		else if (strcmp(s.c_str(), "sort") == 0) {
			std::sort(ord_vec.begin(), ord_vec.end(), cmp);
		}
		else if (strcmp(s.c_str(), "complete") == 0) {
			cin >> table_num;
			for (int i = 0; i < ord_vec.size(); i++) {
				if (table_num == ord_vec[i].first) {
					select = i;
					break;
				}
			}
			if (select >= 0) ord_vec.erase(ord_vec.begin() + select);
		}

		if (ord_vec.empty()) {
			cout << "sleep" << endl;
		}
		else {
			for (int i = 0; i < ord_vec.size(); i++) {
				cout << ord_vec[i].first << " ";
			}
			cout << endl;
		}
	}
	return 0;
}