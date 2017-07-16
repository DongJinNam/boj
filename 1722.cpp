#include <stdio.h>
#include <vector>

using namespace std;

std::vector<long long> arrOfFact; // factorial 수를 담는 vector
std::vector<long long> vecOfNum; // 1 ~ N 까지의 수를 담는 vector

// factorial recursive function
long long factorial(int n) {
	if (n == 1) {
		return 1;
	}
	return n * factorial(n - 1);
}

int main() {

	int N, select;
	int i, j, k, i_data, index;
	long long order;
	long long valueOfDiv;

	scanf("%d", &N);
	scanf("%d", &select);

	arrOfFact.push_back(1);
	for (i = 1; i <= N; i++) {
		arrOfFact.push_back(factorial(i));
		vecOfNum.push_back(i);
	}

	if (select == 1) {// order 번째 수열을 나타내는 N개 수 출력
		index = N - 1;
		scanf("%lld", &order);

		valueOfDiv = arrOfFact[index];
		while (!vecOfNum.empty()) {			
			long long result = (order-1) / valueOfDiv;
			int pop = vecOfNum[result];
			vecOfNum.erase(vecOfNum.begin() + result);

			if (!vecOfNum.empty()) printf("%d ", pop);
			else printf("%d\n ", pop);

			order -= (result * valueOfDiv);
			if (index > 0) valueOfDiv = arrOfFact[--index];
		}
	}
	else if (select == 2) { // N개 수가 주어질 때 이것은 몇번째 순열인가.
		order = 0;
		for (i = N - 1; i >= 0; i--) {
			scanf("%d", &i_data);
			for (j = 0; j < vecOfNum.size(); j++) {
				if (i_data == vecOfNum.at(j)) {
					index = j;
					vecOfNum.erase(vecOfNum.begin() + j);
					break;
				}
			}
			order += index * arrOfFact[i];
		}
		printf("%lld\n", ++order);
	}
	return 0;
}