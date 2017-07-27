#include <stdio.h>
#include <bitset>

int main() {
	int x;
	std::bitset<7> b_set;
	scanf("%d", &x);
	b_set = x;	
	printf("%d\n", b_set.count());
	return 0;
}