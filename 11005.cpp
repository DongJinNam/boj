#include <stdio.h>
#include <math.h>
#include <stack>

int main() {

	unsigned long long N;
	int B, remainder;
	std::stack<char> stackOfChar;
	char ch;

	scanf("%llu %d", &N, &B);

	while (N > 0) {		
		remainder = N % B;
		N /= B;
		if (remainder >= 10)
			ch = (char)remainder + 55;
		else
			ch = (char)remainder + 48;
		stackOfChar.push(ch);
	}
	while (!stackOfChar.empty()) {
		ch = stackOfChar.top();
		stackOfChar.pop();
		printf("%c", ch);
	}
	printf("\n");
	return 0;
}