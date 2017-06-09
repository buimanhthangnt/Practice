#include <iostream>

using namespace std;

int n, k, *a;

void show() {
	for (int i=1; i<=k; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void tapcon(int i) {
	if (i==k+1) {
		show();
		return;
	}
	for (int j=a[i-1]+1; j<=n-k+i; j++) {
		a[i] = j;
		tapcon(i+1);
	}
}

int main()
{
	cin >> n >> k;
	a = new int[k+1];
	a[0] = 0;
	tapcon(1);
}