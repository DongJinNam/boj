#include <iostream>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	for (int i = 1000; i < 10000; i++) {

		int num = i;
		int ans_10 = 0, ans_12 = 0, ans_16 = 0;
		int temp = i;

		while (temp > 0) {
			int rm = temp % 10;
			temp /= 10;
			ans_10 += rm;
		}

		temp = i;
		while (temp > 0) {
			int rm = temp % 12;
			temp /= 12;
			ans_12 += rm;
		}

		temp = i;
		while (temp > 0) {
			int rm = temp % 16;
			temp /= 16;
			ans_16 += rm;
		}
		if (ans_10 == ans_12 && ans_12 == ans_16) {
			cout << i << "\n";
		}
	}
	return 0;
}