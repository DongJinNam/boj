#include <stdio.h>
#include <bitset>
#include <string>

int main() {
	int i, j;
	int N;
	int cnt = 0;
	long long result = 0;

	std::string s;	
	std::bitset<32> bits;

	scanf("%d", &N);
	bits = N;
	while (N > 0) {
		N >>= 1;
		cnt++;
	}		
	s = bits.to_string();

	for (i = 0; i < cnt; i++) {
		if (s.at(31 - i) == '1')
			result += (1 << (cnt - 1 - i));
	}
	printf("%lld\n", result);
	return 0;
}