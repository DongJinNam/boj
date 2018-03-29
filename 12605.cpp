#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int tc;
	int len;
	cin >> len;
	tc = len;
	while (tc--) {
		string line;
		while(getline(cin, line) && line == "");
		cout << "Case #" << len - tc << ": ";

		vector<string> tokens;
		int beg, end = line.length() - 1;
		for (int i = end; i >= 0; i--) {
			if (line[i] == ' ') {
				beg = i + 1;
				tokens.push_back(line.substr(beg, end - beg + 1));
				end = i - 1;
			}
		}
		beg = 0;
		tokens.push_back(line.substr(beg, end - beg + 1));
		for (auto str : tokens)
			cout << str << " ";
		cout << "\n";		
	}
	return 0;
}