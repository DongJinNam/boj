#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
	char arr[8], arr2[8], arr3[8], arr4[8];
	int i, len[4];
	int first, second, third, forth;
	unsigned long long result1, result2;

	scanf("%s", arr);
	scanf("%s", arr2);
	scanf("%s", arr3);
	scanf("%s", arr4);

	len[0] = strlen(arr);
	len[1] = strlen(arr2);
	len[2] = strlen(arr3);
	len[3] = strlen(arr4);
	
	first = atoi(arr);
	second = atoi(arr2);
	result1 = first * pow(10, len[1]) + second;

	third = atoi(arr3);
	forth = atoi(arr4);
	result2 = third * pow(10, len[3]) + forth;

	printf("%llu\n", result1 + result2);
	return 0;
}