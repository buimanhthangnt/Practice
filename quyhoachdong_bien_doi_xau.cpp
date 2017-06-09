#include <iostream>
#include <cstring>
#include <stack> 

using namespace std;

int main()
{
	char x[22], y[22];
	cin >> x >> y;
	int n = strlen(x), m = strlen(y);
	int f[22][22];
	memset(f,0,sizeof(f));
	for (int i=0; i<=max(n,m); i++) {
		if (i<=m) f[0][i] = i;
		if (i<=n) f[i][0] = i;
	}
	for (int i=1; i<=n; i++) {
		for (int j= 1; j<=m; j++) {
			if (x[i-1]==y[j-1]) f[i][j] = f[i-1][j-1];
			else {
				int min = f[i-1][j];
				if (f[i][j-1]<min) min = f[i][j-1];
				if (f[i-1][j-1]<min) min = f[i-1][j-1];
				f[i][j] = min + 1;
			}
		}
	}
	cout << f[n][m] << endl;	
	int i = n, j = m;
	while (i>0 || j>0) {
		if (x[i-1]==y[j-1]) {
			cout << "nothing  ";
			i--; j--;			
		} else {
			if (f[i][j]-1==f[i-1][j])  {
				cout << "delete  "; i--; 
			}
			if (f[i][j]-1==f[i-1][j-1])  {
				cout << "replace  "; i--; j--;
			}
			if (f[i][j]-1==f[i][j-1])  {
				cout << "insert  "; j--;
			}
		}
	}
}