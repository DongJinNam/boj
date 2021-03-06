#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	string s1, s2, total;
	int arr[10002] = { 0 }; // input 값 : 0 < x < 10^10000
	cin >> s1 >> s2;
	
	// 끝자리부터 계산하기 위해서 reverse 진행
	std::reverse(s1.begin(), s1.end());
	std::reverse(s2.begin(), s2.end());

	// 두 문자열 크기 중 큰 값과 작은 값을 뽑아낸다.
	int max = s1.length() > s2.length() ? s1.length() : s2.length();
	int min = s1.length() < s2.length() ? s1.length() : s2.length();

	// 큰 값을 기준으로 loop 실행
	for (int i = 0; i < max; i++) {
		int i1, i2, sum;
		if (i < min) {
			i1 = (int)(s1[i] - '0');
			i2 = (int)(s2[i] - '0');
		}
		else {
			if (s1.length() > min) {
				i1 = (int)(s1[i] - '0');
				i2 = 0;
			}
			else {
				i1 = 0;
				i2 = (int)(s2[i] - '0');
			}
		}
		sum = i1 + i2 + arr[i];
		arr[i] = (sum % 10);
		if (sum >= 10) arr[i + 1]++;		
	}	
	// 출력할 total 문자열 설정.
	for (int i = 0; i < max; i++) {
		total.push_back((char)(arr[i] + '0'));
	}
	// 마지막 자리에 올림 자리 수가 있다면 같이 추가.
	if (arr[max] > 0) total.push_back((char)(arr[max] + '0'));
	// reverse 를 통해서 큰 숫자 자리부터 출력할 수 있도록 함.
	std::reverse(total.begin(), total.end());
	cout << total << "\n";
    return 0;
}
