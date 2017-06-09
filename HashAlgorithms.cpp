#include <iostream>

using namespace std;

typedef long long ll;

const ll base = 1291793;

ll m, n;
ll a[100002], b[100002];
ll hashSi[100002], power[100002];

ll hashS(long i, long j) {
	return (hashSi[j] - hashSi[i-1] * power[j-i+1] + base * base) % base;
}

int main()
{
	cin >> n >> m;
	string s;
	cin >> s;
	for (long i=1; i<=m; i++) cin >> a[i] >> b[i];

	s = " " + s;
	hashSi[0] = 0;  power[0] = 1;
	for (long i=1; i<=n; i++) {
		hashSi[i] = (hashSi[i-1]*26 + s[i] - 'a') % base;
		power[i] = (power[i-1]*26) % base;
	}

	ll hashIJ = 0;
	for (long i=1; i<=m; i++) {
		ll temp = 0;
		ll count = 0;
		hashIJ = hashS(a[i],b[i]);
		ll j = a[i];
		while (j<=n-b[i]+a[i]) {
            temp = hashS(j,j+b[i]-a[i]);
			if (hashIJ == temp) {
				count++;
				j = j + b[i] - a[i] + 1;
			}
			else {
				goto a;
			}
		}
		a:;
		cout << count << endl;
	}
}
