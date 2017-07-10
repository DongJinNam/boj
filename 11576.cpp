#include <vector>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int A, B;
	int m, i, j;
	int remainder; // ³ª¸ÓÁö
	unsigned long long result, data;
	std::vector<int> in_vec;
	std::vector<int> out_vec;

	cin >> A >> B;
	cin >> m;
	for (i = 0; i < m; i++) {
		cin >> data;
		in_vec.push_back(data);
	}
	result = 0;
	for (i = 0; i < in_vec.size(); i++) 		
		result += in_vec.at(i) * std::pow(A, m - i - 1);	
	i = 0;
	while (result > 0) {
		remainder = result % B;
		result /= B;
		out_vec.push_back(remainder);
		i++;
	}
	for (i = out_vec.size() - 1; i  >= 0; i--) {
		printf("%d ", out_vec.at(i));
	}
	printf("\n");
	return 0;
}