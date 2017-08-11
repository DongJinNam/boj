#include <iostream>

using namespace std;

char arr[4] = { '+', '-', '*','/' };

int main() {
	std::ios::sync_with_stdio(false);
	int n1, n2, n3;
	int i;
	int select = -1;
	string ans;
	cin >> n1 >> n2 >> n3;

	for (i = 0; i < 4; i++) {
		switch (arr[i]) {
		case '+':
			if (n1 + n2 == n3) select = i;		
			break;
		case '-':
			if (n1 - n2 == n3) select = i;
			break;
		case '*':
			if (n1 * n2 == n3) select = i;
			break;
		case '/':
			if (n1 / n2 == n3) select = i;
			break;
		}
	}

	if (select != -1) {
		cout << n1 << arr[select] << n2 << "=" << n3;
		return 0;
	}

	for (i = 0; i < 4; i++) {
		switch (arr[i]) {
		case '+':
			if (n1 == n2 + n3) select = i;
			break;
		case '-':
			if (n1 == n2 - n3) select = i;
			break;
		case '*':
			if (n1 == n2 * n3) select = i;
			break;
		case '/':
			if (n1 == n2 / n3) select = i;
			break;
		}
	}
	cout << n1 << "=" << n2 << arr[select] << n3;
	return 0;
}