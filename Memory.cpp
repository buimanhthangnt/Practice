#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;

char a[8];
bool mark[27];

void gotoxy(int x, int y) {
	COORD pos = {y, x};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void showGame(int stage) {
	gotoxy(1,33); cout << "M E M O R Y";
	gotoxy(4,20); cout << "Stage " << stage; 
	gotoxy(8,22);
	for (int i=1; i<=6; i++) {
		cout << a[i];
		if (i==6) cout << " ";
		else cout << "     "; 
	}
}

void move(int x, int y, int stage) {
	int dist = y - x;
	int posx = 6*(x-1) + 22, posy = 6*(y-1) + 22;
	char valuex = a[x], valuey = a[y];
	a[x] = ' '; a[y] = ' ';
	system("cls");
	if (dist==1) {
		int count = dist + 3;
		int i = (posy-posx-2)/count;
		while(count>0) {
			posx += i; posy -= i;
			gotoxy(7,posx); cout << valuex;
			gotoxy(9,posy); cout << valuey;
			showGame(stage); Sleep(200);system("cls"); count--;
		}
		a[x] = valuey; a[y] = valuex;
		showGame(stage); Sleep(200);
		return;
	}

	if (dist==4 || dist==5 || dist==3 || dist==2) {
		int count = dist+1;
		for (int i=1; i<=2; i++) {
			posx += 2; posy -= 2;
			gotoxy(8-i,posx); cout << valuex;
			gotoxy(8+i,posy); cout << valuey;
			showGame(stage); Sleep(180); system("cls");
		}
		int i = (posy-posx-4)/count;
		if (dist<=4) i++;
		while (count>0) {
			posx += i; posy -= i;
			gotoxy(6,posx); cout << valuex;
			gotoxy(10,posy); cout << valuey;
			showGame(stage); ;Sleep(180);system("cls"); count--;
		}
		gotoxy(7,posx+i+2); cout << valuex;
		gotoxy(9,posy-i-2); cout << valuey;
		showGame(stage); Sleep(180);system("cls");
		a[x] = valuey; a[y] = valuex;
		showGame(stage); Sleep(180);
		return;
	}
}

int main()
{
	int point = 0;
	for (int i=1; i<=5; i++) {
		for (int j=1; j<=26; j++) 
			mark[j] = false;
		srand(time(NULL));
		for (int j=1; j<=6; j++) {
			int random;
			do random = rand()%26 + 1;
			while (mark[random]==true);
			a[j] = random + 64;
			mark[random] = true;
		}
		gotoxy(4,20); cout << "Stage " << i;
		showGame(i);
		getch();

		for (int j=1; j<=12; j++) {
			int pos1 = 1, pos2 = 0;
			pos1 = rand()%6 + 1;
			pos2 = pos1;
			while (pos2==pos1) pos2 = rand()%6 + 1;
			if (pos1>pos2) {
				int temp = pos1;
				pos1 = pos2;
				pos2 = temp;               
			}
			move(pos1,pos2,i);
			Sleep(120);
		}
		system("cls");
		gotoxy(8,22);
		for (int j=1; j<=6; j++) {
			cout << j;
			if (j==6) cout << " ";
			else cout << "     ";
		}
		int random = rand() % 6 + 1;
		gotoxy(1,33); cout << "M E M O R Y";
		gotoxy(4,20); cout << "Stage " << i;
		gotoxy(10,28); cout << "Where is letter '" << a[random] << "': ";
		int answer;
		cin >> answer;
		gotoxy(6,35);
		if (answer==random) {
			cout << "CORRECT!";
			point++;
		}
		else cout << "WRONG!";
		char b[7];
		for (int k=1; k<=6; k++) {
			if (k==random) b[k] = ' ';
			else b[k] = a[k];
		}
		for (int k=1; k<=6; k++) {
			showGame(i);
			Sleep(300);
			gotoxy(8,22);
			for (int j=1; j<=6; j++) {
				cout << b[j];
				if (j==6) cout <<" ";
				else cout << "     ";
			}
			Sleep(400);
		}
		system("cls");
	}
	gotoxy(1,33); cout << "M E M O R Y";
	gotoxy(4,25); cout << "You have " << point << " correct answers";
}
