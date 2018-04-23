#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int both_size = 0;

	std::map<string, int> dic; // 듣도 못한 사람

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		dic.insert(std::pair<string, int>(name, 1));
	}
	for (int i = 0; i < m; i++) {
		string name;
		cin >> name;
		auto it = dic.find(name);
		if (it != dic.end()) {
			it->second++;
			both_size++;
		}
	}
	cout << both_size << "\n";
	for (auto it : dic) {
		if (it.second > 1) cout << it.first << "\n";
	}
	return 0;
}