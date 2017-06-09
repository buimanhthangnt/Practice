#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;

int a[5][5];
int xspace = 4, yspace = 4;

void gotoxy(int x, int y) {
	COORD pos = {y, x};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void drawSquare(int x, int y, int number) {
	gotoxy(x,y+1);
	cout << "______";
	for (int i=1; i<=3; i++) {
		gotoxy(x+i,y); cout << "|";
		for (int j=1; j<=6; j++) {
			if (i==2 && j==3) cout << number;
			else cout << " ";
			if (number>9 && j==3  && i==2) j++;
		}
		cout << "|";
	}
	gotoxy(x+3,y+1); cout << "______";
}

void move(char c, int x, int y) {
	int i = x, j = y;
	switch (c) {
		case 'a': j++; break;
		case 's': j--; break;
		case 'w': i++; break;
		case 'z': i--; break;
	}
	if (i>0 && i<5 && j>0 && j<5) {
		int temp = a[x][y];
		a[x][y] = a[i][j];
		a[i][j] = temp;
		xspace = i; yspace = j;
	}
}

void show() {
	for (int i=1; i<=4; i++) {
		for (int j=1; j<=4; j++) {
			if (a[i][j]<0) continue;
			drawSquare(5+(i-1)*4,22+(j-1)*9,a[i][j]);
		}
	}
}

bool endCondition() {
	int count = 1;
	bool b = true;
	for (int i=1; i<=4; i++) {
		for (int j=1; j<=4; j++) {
			if (i!=4 || j!=4) 
				if (count!=a[i][j]) b = false;
			count++;
		}
	}
	return b;
}

void merge() {
	int step = 0, direction;
	char dir;
	for (int i=1; i<=222; i++) {
		step = rand() % 12 +1;
		if (step<3) step = 1;
		if (step>=3 && step<7) step = 2;
		if (step>=7 && step<=10) step = 3;
		if (step>10) step = 4;
		direction = rand()%4 + 1;
		switch(direction) {
			case 1: dir = 'a'; break;
			case 2: dir = 's'; break;
			case 3: dir = 'z'; break;
			case 4: dir = 'w'; break;
		}
		for (int j=1; j<=step; j++) {
			move(dir,xspace,yspace);
		}
	}
	while (xspace<4) move('w',xspace,yspace);
	while (yspace<4) move('a',xspace,yspace);
}
	
int main()
{
	srand(time(NULL));
	int count = 1;
	for (int i=1; i<=4; i++) {
		for (int j=1; j<=4; j++) {
			if (i*j!=16) a[i][j] = count;
			else a[i][j] = -1;
			count++;
		}
	}
	merge();
	show();
	while(!endCondition()) {
		char c;
		do c = getch();
		while (c!='a' && c!='s' && c!='w' && c!='z');
		system("cls");
		move(c,xspace,yspace);
		show();
	}
	gotoxy(3,35); cout << "YOU WIN!";
	getch();
	system("cls");
}