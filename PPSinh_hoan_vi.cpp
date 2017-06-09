#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int *a;
	a = new int[n];
	for (int i=1; i<=n; i++) {
		a[i] = i;
	}
	while (1) {
		for (int i=1; i<=n; i++) cout << a[i] << " ";
		cout << endl;
		int j = n-1;
		while (j>=1 && a[j]>a[j+1]) j--;
		if (j<1) break;
		int k = n;
		while (a[k]<a[j]) k--;
		swap(a[k],a[j]);
		for (int i=j+1; i<=(n+j+1)/2; i++) {
			swap(a[i],a[n-i+j+1]);
		}
	}
}