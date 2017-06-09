#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int f[55][55], v[55], w[55];
	int n, m;
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> w[i] >> v[i];
	}
	for (int i=1; i<=n; i++) {
		for (int j=0; j<=m; j++) {
			f[i][j] = f[i-1][j];
			if (j>=w[i] && f[i][j]<f[i-1][j-w[i]]+v[i]) {
				f[i][j] = f[i-1][j-w[i]]+v[i];
			}
		}
	}
	cout << f[n][m] << endl;
	int i = n; int j = m;
	while (i>0) {
		if (f[i][j]!=f[i-1][j]) {
			cout << i << " ";
			j -= w[i];
		}
		i--;
	}
}