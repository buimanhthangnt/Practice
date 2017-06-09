#include <iostream>

using namespace std;

int *a;
int n;

void show() {
	for (int i=0; i<n; i++) {
		cout << a[i];
	}
	cout << endl;
}

void nhiphan(int n) {
	if (n<0) {
		show();
		return;
	}
	a[n] = 0;
	nhiphan(n-1);
	a[n] = 1;
	nhiphan(n-1);
}

int main()
{
	
	cin >> n;
	a = new int[n];
	nhiphan(n-1);
}