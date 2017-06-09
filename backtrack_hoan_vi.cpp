#include <iostream>

using namespace std;

int n, a[12];
bool track[12];

void show() {
	for (int i=1; i<=n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void hoanvi(int i) {
	if (i==n+1) {
		show();
		return;
	}
	for (int j=1; j<=n; j++) {
		if (track[j]==false) {
			a[i] = j;
			track[j] = true;
			hoanvi(i+1);
			track[j] = false;
		}
	}
}

int main()
{
	cin >> n;
	for (int i=1; i<=n; i++) {
		track[i] = false;
	}
	hoanvi(1);
}