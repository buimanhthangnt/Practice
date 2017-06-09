#include <iostream>
#include <conio.h>

using namespace std;

int a[32][32];
bool ng[32], d[32], cx[32], cn[32];
int n;

void mark(int x, int y, bool type) {
	ng[x] = type; d[y] = type;
	cx[x+y] = type; cn[x-y] = type;
}

void show() {
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (a[i][j]==0) cout << ". ";
			else cout << "H ";
		}
		cout << endl;
	}
	cout << endl;
}

void xephau(int i) {
	if (i==n+1) {
		show();
		//getch();
		return;
	}
	for (int j=1; j<=n; j++) {
		if (!ng[i] && !d[j] && !cx[i+j] && !cn[i-j]) {
			a[i][j] = 1;
			mark(i,j,true);
			xephau(i+1);
			a[i][j] = 0;
			mark(i,j,false);
		}
	}
}

int main()
{
	cin >> n;
	xephau(1);
}