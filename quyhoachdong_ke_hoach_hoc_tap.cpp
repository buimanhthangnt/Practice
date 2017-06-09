#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int a[100][100];
	int f[100][100];
	int n, m;
	int track[100];
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			f[i][j] = f[i-1][j];
			for (int k=1; k<=j; k++) {
				if (f[i-1][j-k] + a[i][k] > f[i][j]) {
					f[i][j] = f[i-1][j-k] + a[i][k];
				}
			}
		}
	}
	cout << f[n][m] << endl;

	int i = n, j = m;
	while (i>0) {
		if (f[i][j]!=f[i-1][j]) {
			for (int k=1; k<=j; k++) {
				if (f[i][j]==f[i-1][j-k] + a[i][k]) {
					track[i] = k;
				}
			}
			j -= track[i];
		}
		i--;
	}
	for (int i=1; i<=n; i++) {
		cout << track[i] << endl;
	}
}