#include <stdio.h>
#include <math.h>

int main() {
	int sem;
	int sub_cnt, c_sum;
	int c;
	double gpa, grade, total;

	scanf("%d", &sem);

	for (int i = 0; i < sem; i++) {
		scanf("%d", &sub_cnt);
		total = 0.0;
		gpa = 0;
		c_sum = 0;
		for (int j = 0; j < sub_cnt; j++) {
			scanf("%d %lf", &c, &grade);
			total += grade * c;
			c_sum += c;
		}

		double temp;
		temp = total / c_sum * pow(10, 2);
		temp = floor(temp + 0.5);
		temp *= pow(10, -2);

		gpa = temp;
		printf("%d %.1lf\n", c_sum, gpa);
	}

	return 0;
}