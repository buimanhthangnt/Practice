#include <iostream>

using namespace std;

int main()
{
	int T, *R, *C, *r, *c;
	cin >> T;
	R = new int[T];
	C = new int[T];
	r = new int[T];
	c = new int[T];
	char ***A, ***a;
	A = new char**[T];
	a = new char**[T];
	for (int i=0; i<T; i++) {
		cin >> R[i] >> C[i];
		A[i] = new char*[R[i]+1];
		for (int j=0; j<R[i]; j++) {
			A[i][j] = new char[C[i]+1];
		}
		for (int j=0; j<R[i]; j++) {
			cin >> A[i][j];
		}

		cin >> r[i] >> c[i];
		a[i] = new char*[r[i]+1];
		for (int j=0; j<r[i]; j++) {
			a[i][j] = new char[c[i]+1];
		}
		for (int j=0; j<r[i]; j++) {
			cin >> a[i][j];
		}
	}

	for (int i=0; i<T; i++) {
		bool b;
		for (int j=0; j<R[i]-r[i]+1; j++) {
			for (int k=0; k<C[i]-c[i]+1; k++) {
				b = true;
				for (int m=0; m<r[i]; m++) {
					for (int n=0; n<c[i]; n++) {
						if (A[i][j+m][k+n]!=a[i][m][n]) {
							b = false;
							goto a;
						}
					}
				}
				a:;
				if (b==true) {
					cout << "YES" << endl;
					goto b;
				}
			}
		}
		b:;
		if (b==false) cout << "NO" << endl;
	}




	// for (int i=0; i<T; i++) {
	// 		for (int j=0; j<R[i]; j++) {
	// 			for (int k=0; k<C[i]; k++) {
	// 				cout << A[i][j][k];
	// 			}
	// 			cout << endl;
	// 		}
	// 		cout << endl;
	// 		for (int j=0; j<r[i]; j++) {
	// 			for (int k=0; k<c[i]; k++) {
	// 				cout << a[i][j][k];
	// 			}
	// 			cout << endl;
	// 		}
	// 		cout << endl << endl;
	// 	}
}