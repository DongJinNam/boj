#include <iostream>
#include <vector>

using namespace std;

int arr[11]; // 11개의 숫자를 담는 배열
int op_cnt_arr[4]; // 식에서 +,-,*,/의 개수
int op_arr[10]; // 완전탐색 과정에서 사용할 index별 연산자 값을 담는 배열
// 1 : +, 2 : -, 3 : *, 4 : /

int min_val = 1000000000; // 최대값
int max_val = -1000000000; // 최소값

void getResult(int n, int count, int plus, int sub, int mul, int div) {
	if (plus == 0 && sub == 0 && mul == 0 && div == 0) {
		int total = arr[0]; // max_val, min_val 값에 따라서 update 할 값.
		for (int i = 1; i < n; i++) {
			switch (op_arr[i-1]) {
			case 1:
				total += arr[i];
				break;
			case 2:
				total -= arr[i];
				break;
			case 3:
				total *= arr[i];
				break;
			case 4:
				total /= arr[i];
				break;
			}
		}		
		min_val = total < min_val ? total : min_val;
		max_val = total > max_val ? total : max_val;
	}
	if (plus > 0) {
		op_arr[count] = 1;
		getResult(n, count + 1, plus - 1, sub, mul, div);
		op_arr[count] = 0;
	}
	if (sub > 0) {
		op_arr[count] = 2;
		getResult(n, count + 1, plus, sub-1, mul, div);
		op_arr[count] = 0;
	}
	if (mul > 0) {
		op_arr[count] = 3;
		getResult(n, count + 1, plus, sub, mul-1, div);
		op_arr[count] = 0;
	}
	if (div > 0) {
		op_arr[count] = 4;
		getResult(n, count + 1, plus, sub, mul, div-1);
		op_arr[count] = 0;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op_cnt_arr[i];
	}
	getResult(n, 0, op_cnt_arr[0], op_cnt_arr[1], op_cnt_arr[2], op_cnt_arr[3]);
	cout << max_val << "\n" << min_val << "\n";
	return 0;
}