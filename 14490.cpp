#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 최대공약수 구하기.
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	std::ios::sync_with_stdio(false);
	string in;
	string out = "";
	cin >> in;

	std::size_t colonPos = in.find(":");
	int num1 = std::stoi(in.substr(0, colonPos));
	int num2 = std::stoi(in.substr(colonPos+1, in.length() - colonPos));
	int gcd_val;
	if (num1 > num2)
		gcd_val = gcd(num1, num2);
	else
		gcd_val = gcd(num2, num1);
	num1 /= gcd_val;
	num2 /= gcd_val;

	out += std::to_string(num1);
	out += ":";
	out += std::to_string(num2);

	cout << out << "\n";
	return 0;
}