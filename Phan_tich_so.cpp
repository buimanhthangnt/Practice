#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int *a;
	a = new int[n+1];
	for (int i=1; i<=n; i++) {
		a[i] = 1;
	}
	while (1) {
		for (int i=1; i<=n; i++) {
			if (a[i]!=0) cout << a[i] << " ";
		}
		if (a[1]==n) break;
		cout << endl;
		int j = n;
		while (a[j]==0) j--;
		int count = 0;
		while (a[j-1]<a[j]+1 && j>1 || count==0) {
			j--;
			count++;
		}
		a[j]++;
		int n1 = n;
		count = 1;
		while (n1>0) {
			if (count<=j) n1 -= a[count];
			else {
				a[count] = 1;
				n1--;
			}
			count++;
		}
		for (int i=count; i<=n; i++) {
			a[i] = 0;
		}
	}
}