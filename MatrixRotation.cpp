#include <iostream>

using namespace std;

int main()
{
	long m, n, s;
	cin >> m >> n >> s;
	long l, r, u, t;
	long **a, **b;
	a = new long*[m+1];
	b = new long*[m+1];
	for (long i=1; i<=m; i++) {
		a[i] = new long[n+1];
		b[i] = new long[n+1];
		for (long j=1; j<=n; j++) {
			cin >> a[i][j];
		}
	}
	//cout << endl;
	long tmp;
	l = 1, r = n, t = 1, u = m;
	while (l<=r && t<=u) {
		int N0 = s % (2*(u+r-l-t));
		for (int i=1; i<=N0; i++) {
			tmp = a[t][l];
			for (int j=l; j<=r-1; j++) {
				b[t][j] = a[t][j+1];
				a[t][j] = b[t][j];
			}
			for (int j=t; j<=u-1; j++) {
				b[j][r] = a[j+1][r];
				a[j][r] = b[j][r];
			}
			for (int j=r; j>=l+1; j--) {
				b[u][j] = a[u][j-1];
				a[u][j] = b[u][j];
			}
			for (int j=u; j>=t+1; j--) {
				if (j!=t+1) {
					b[j][l] = a[j-1][l];
					a[j][l] = b[j][l];
				}
				else {
					b[j][l] = tmp;
					a[j][l] = tmp;
				}
			}
		}
		if (N0==0) {
			for (int j=l; j<=r-1; j++) {
				b[t][j] = a[t][j];
				a[t][j] = b[t][j];
			}
			for (int j=t; j<=u-1; j++) {
				b[j][r] = a[j][r];
				a[j][r] = b[j][r];
			}
			for (int j=r; j>=l+1; j--) {
				b[u][j] = a[u][j];
				a[u][j] = b[u][j];
			}
			for (int j=u; j>=t+1; j--) {
					b[j][l] = a[j][l];
					a[j][l] = b[j][l];
			}
		}
		l++; r--; u--; t++;
	}
	for (int i=1; i<=m; i++) {
		for (int j=1; j<=n; j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
}