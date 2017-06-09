#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int a[10002];

int main()
{
	ll n ,i;
	cin >> n;
	ll prev = 1; i = 2;
	if (n>=81) {
		n = n%81;
		i = 1; prev = 8;
	}
	for (; i<=n; i++) {
		int j=0;
		while (prev!=0) {
			a[j] = prev%10;
			prev = prev/10;
			j++;
		}
		//cout << j << endl;
		for (int k=0; k<j; k++) {
			prev += a[k]*pow(10,j-k-1);
		}
		prev += 2;
	}
	cout << prev;
}