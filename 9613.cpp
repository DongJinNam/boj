#include <stdio.h>
#include <math.h>
#include <vector>

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int main() {
	int tc;
	int i, j;
	int data, data2, g, temp;
	int cnt;
	unsigned long long result;
	std::vector<int> vec;
	std::vector<int> gcdvec;

	scanf("%d", &tc);
	while (tc--) {
		// 초기화 내용
		vec.clear(); // vector 초기화
		gcdvec.clear(); // map 초기화
		result = 0; // 결과값 0 초기화

		scanf("%d", &cnt);
		for (i = 0; i < cnt; i++) {
			scanf("%d", &data);
			vec.push_back(data);
		}
		for (i = 0; i < cnt - 1; i++) {			
			for (j = i + 1; j < cnt; j++) {
				data = vec.at(i);
				data2 = vec.at(j);
				if (data2 > data) {
					temp = data2;
					data2 = data;
					data = temp;
				}
				g = gcd(data, data2);
				gcdvec.push_back(g);
			}
		}
		for (i = 0; i < gcdvec.size(); i++) 
			result += gcdvec.at(i);	
		printf("%llu\n", result);
	}
	return 0;
}