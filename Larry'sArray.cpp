#include <iostream>

using namespace std;

int T;
int *n, **a;

bool check(int i) {
	bool b = true;
	for (int j=1; j<n[i]; j++) {
		if (a[i][j]<a[i][j-1]) {
			b = false;
			goto a;
		}
	}
	a:;
	if (b==false) {
		b = true;
		for (int j=1; j<n[i]; j++) {
			if (a[i][j]>a[i][j-1]) {
				b = false;
				goto d;
			}
		}
	}
	d:;
	return b;
}

void swap3(int i, int j) {
	int tmp = a[i][j+2];
	a[i][j+2] = a[i][j+1];
	a[i][j+1] = a[i][j];
	a[i][j] = tmp;
}

void swap1(int i, int j) {
	int tmp = a[i][j];
	a[i][j] = a[i][j+1];
	a[i][j+1] = a[i][j+2];
	a[i][j+2] = tmp;
}

int main()
{
	cin >> T;
	n = new int[T+1];
	a = new int*[T+1];
	for (int i=1; i<=T; i++) {
		cin >> n[i];
		a[i] = new int[n[i]+1];
		for (int j=1; j<=n[i]; j++) {
			cin >> a[i][j];
		}
	}
	for (int i=1; i<=T; i++) {
		for (int j=1; j<=n[i]-2; j++) {
			int k=1;
			while (a[i][k]!=j) k++;
			while (k-j>=2) {
				swap3(i,k-2);
				k = k-2;
			}
			while (a[i][j]!=j) {
				swap1(i,j);
			}
		}
		if (a[i][n[i]-1]<a[i][n[i]]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}