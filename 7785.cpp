#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	std::map<string, int> dic; // ÃâÅð±Ù ·Î±×

	cin >> n;
	for (int i = 0; i < n; i++) {
		string name, sEnter;
		cin >> name >> sEnter;
		auto it = dic.find(name);
		if (strcmp(sEnter.c_str(), "enter") == 0) {
			if (it != dic.end())
				it->second++;
			else
				dic.insert(std::pair<string, int>(name, 1));
		}
		else {
			if (it != dic.end())
				it->second--;
		}
	}
	for (auto it = dic.rbegin(); it != dic.rend(); it++) {
		if (it->second == 1) cout << it->first << "\n";
	}
	return 0;
}