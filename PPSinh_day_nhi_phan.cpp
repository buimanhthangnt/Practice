#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int *a;
	a = new int[n];
	for (int i=0; i<n; i++) a[i] = 0;
	while (1) {
		for (int i=0; i<n; i++) cout << a[i] << " ";
		cout << endl;
		int j = n-1;
		while (j>=0 && a[j]==1) j--;
		if (j<0) break;
		a[j] = 1;
		for (int i=n-1; i>j; i--) a[i] = 0;
	}
	return 0;
}