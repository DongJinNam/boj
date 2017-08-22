#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int board[16][3];
string colorMap[16];

int main() {
	std::ios::sync_with_stdio(false);
	board[0][0] = 255;
	board[0][1] = 255;
	board[0][2] = 255;
	colorMap[0] = "White";
	board[1][0] = 192;
	board[1][1] = 192;
	board[1][2] = 192;
	colorMap[1] = "Silver";
	board[2][0] = 128;
	board[2][1] = 128;
	board[2][2] = 128;
	colorMap[2] = "Gray";
	colorMap[3] = "Black";
	board[4][0] = 255;
	colorMap[4] = "Red";
	board[5][0] = 128;
	colorMap[5] = "Maroon";
	board[6][0] = 255;
	board[6][1] = 255;
	colorMap[6] = "Yellow";
	board[7][0] = 128;
	board[7][1] = 128;
	colorMap[7] = "Olive";
	board[8][1] = 255;
	colorMap[8] = "Lime";
	board[9][1] = 128;
	colorMap[9] = "Green";
	board[10][1] = 255;
	board[10][2] = 255;
	colorMap[10] = "Aqua";
	board[11][1] = 128;
	board[11][2] = 128;
	colorMap[11] = "Teal";
	board[12][2] = 255;
	colorMap[12] = "Blue";
	board[13][2] = 128;
	colorMap[13] = "Navy";
	board[14][0] = 255;
	board[14][2] = 255;
	colorMap[14] = "Fuchsia";
	board[15][0] = 128;
	board[15][2] = 128;
	colorMap[15] = "Purple";
	int r, g, b;
	while (1) {
		cin >> r >> g >> b;
		if (r == -1 && g == -1 && b == -1) break;

		int dis = 256 * 256 + 256 * 256 + 256 * 256;
		int select = 0;
		int temp,i;
		for (i = 0; i < 16; i++) {			
			temp = (r - board[i][0]) * (r - board[i][0]) + (g - board[i][1]) * (g - board[i][1]) + (b - board[i][2]) * (b - board[i][2]);
			if (temp < dis) {
				dis = temp;
				select = i;
			}
		}
		cout << colorMap[select] << "\n";
	}
	return 0;
}