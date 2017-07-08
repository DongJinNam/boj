#include <stdio.h>
#include <string.h>

#define MAX_COUNT 10001

unsigned short arrOfCount[MAX_COUNT];

int main() {
	int count, i, data;
	scanf("%d", &count);
	memset(arrOfCount, 0, sizeof(unsigned short)*MAX_COUNT);
	for (i = 0; i < count; i++) {
		scanf("%d", &data);
		arrOfCount[data]++;
	}
	i = 0;
	data = 1;
	while (i < count) {
		if (arrOfCount[data] > 0) {
			printf("%d ", data);
			arrOfCount[data]--;
			i++;
		}
		else {
			while (arrOfCount[data] == 0)
				data++;
		}		
	}
	printf("\n");
	return 0;
}