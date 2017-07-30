#include <string>
#include <iostream>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	string id;
	cin >> id;
	for (int i = 0; i < 3; i++) {
		if (i != 1) cout << ":fan::fan::fan:" << endl;
		else cout << ":fan::" << id << "::fan:" << endl;		
	}
	return 0;
}