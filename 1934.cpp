#include <stdio.h>
#include <math.h>

int gcd(int a, int b) {
	if (b == 0) return a;	
	else return gcd(b, a%b);	
}

int main() {

	int tc;
	int i, j;
	int data, data2, g, result, temp;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &data, &data2);
		if (data2 > data) {
			temp = data2;
			data2 = data;
			data = temp;
		}
		g = gcd(data, data2);
		result = data * data2 / g;
		printf("%d\n", result);
	}
	return 0;
}