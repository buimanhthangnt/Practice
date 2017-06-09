#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	int *n, **a;
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
		bool c = true;
		for (int j=1; j<=n[i]; j++) {
			bool b = false;
			for (int k=-2; k<=2; k++) {
				if (j+k>0 && j+k<=n[i]) {
					if (a[i][j+k]==j) b = true;
				}
				if (b==true) break;
			}
			if (b==false) c = false;
			if (c==false) break;
		}
		if (c==true) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}