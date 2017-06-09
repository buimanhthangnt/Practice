#include <iostream>

using namespace std;

int main()
{
	int n, k, *a;
	cin >> n >> k;
	a = new int[k];
	for (int i=0; i<k; i++) a[i] = i+1;
	while (1) {
		for (int i=0; i<k; i++) cout << a[i] << " ";
		cout << endl;
		int j = k-1;
		while (j>=0 && a[j]==n-k+j+1) j--;
		if (j<0) break;
		a[j]++;
		for (int i=j+1; i<k; i++) a[i] = a[j] + i - j;
	}
}