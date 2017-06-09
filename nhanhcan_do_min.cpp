#include <iostream>
#include <conio.h>

using namespace std;

int map[22][22];
int ver[8] = {-1,1,0,-1,1,-1,0,1};
int hor[8] = {-1,0,1,1,-1,0,-1,1};
int row, col, board[22][22];

void show() {
	for (int i=0; i<row; i++) {
		for (int j=0; j<col; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

bool possible(int j) {
	int count = 0;
	for (int i=1; i<row; i++) {
		count = 0;
		map[i][j] = 0;
		for (int k=0; k<8; k++) {
			if (i-1+ver[k]>=0 && i-1+ver[k]<row && j-1+hor[k]>=0 && j-1+hor[k]<col) {
				count += map[i-1+ver[k]][j-1+hor[k]];
			}
		}
		switch(board[i-1][j-1]-count) {
			case 0: map[i][j] = 0; break;
			case 1: map[i][j] = 1; break;
			default: return false;
		}
	}
}

void try_hor(int i) {
	//show();
	if (i==col) show();
	else {
		for (int j=0; j<=1; j++) {
			map[0][i] = j;
			if (possible(i)) try_hor(i+1);
		}
	}
}

void try_ver(int i) {
	if (i==row) try_hor(1);
	else {
		for (int j=0; j<=1; j++) {
			map[i][0] = j;
			try_ver(i+1);
		}		
	}
	
}

int main()
{
	cin >> row >> col;
	for (int i=0; i<row; i++) {
		for (int j=0; j<col; j++) {
			cin >> board[i][j];
		}
	}
	cout << endl << endl;
	try_ver(0);
}