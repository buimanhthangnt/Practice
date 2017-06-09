#include <iostream>

using namespace std;

int x0, y0, map[102][102], m, n, count = 0;
int a[] = {1,0,-1, 0};
int b[] = {0,1, 0,-1};


int inspect(int x, int y) {
	for (int i=0; i<4; i++) {
		int xx = x + a[i], yy = y + b[i];
		if (xx<=0 || xx>m || yy<1 || yy>n || (xx==x0 && yy==y0)) continue;
		if (map[xx][yy]==0) {
			map[xx][yy] = 2; count++;
			inspect(xx,yy);
		}
	}
	return count;
}

int main()
{
	cin >> m >> n >> x0 >> y0;
	for (int i=1; i<=m; i++) {
		for (int j=1; j<=n; j++) {
			cin >> map[i][j];
		}
	}
	if (map[x0][y0]==0) count = 1;
	cout << inspect(x0,y0);
}