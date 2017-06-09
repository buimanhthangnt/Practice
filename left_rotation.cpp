#include <iostream>

using namespace std;

int main()
{
	int n, d;
	long *a;
	cin >> n >> d;
	a = new long[n+1];
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=d+1; i<=n; i++) cout << a[i] << " ";
	for (int i=1; i<=d; i++) cout << a[i] << " ";
}