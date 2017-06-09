#include <iostream>

using namespace std;

int a[12] = {2,6,3,8,4,1,7,9,10,5,12,11};
bool b[12];
int m = 0;
int d[12];

void count() {
	int c = 0;
	for (int i=1; i<=11; i++) {
		if (b[i]==true) c++;
	}
	if (c>m) {
		m = c;
		int j = 1;
		for (int i=1; i<=11; i++) {
			if (b[i]==true) {
				d[j] = a[i];
				j++;
			}
		}
	}
}

bool check(int n) {
	bool b = true;
	for (int i=n+1; i<=11; i++) {
		if (a[i]>a[n]) b = false;
	}
	return b;
}

void recursion(int prev) {
	if (check(prev)) {
		count();
		return;
	}
	for (int j=prev+1; j<=11; j++) {
		if (a[j]>a[prev]) {
			b[j] = true;
			recursion(j);
			b[j] = false;
		}
	}
}

int main()
{
	a[0] = -1;
	b[0] = false;
	for (int i=1; i<12; i++) {
		b[i] = false;
	}
	recursion(0);
	cout << m << endl;
	for (int i=1; i<=m; i++) {
		cout << d[i] << " ";
	}
}