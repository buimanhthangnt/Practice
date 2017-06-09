#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int T;
	cin >> T;
	char s[100008];
	for (int i=1; i<=T; i++) {
		int left, right;
		cin >> s;
		bool b = true, diff = false;
		long l = strlen(s);
		int j = 0, k = l-1;
		while (j<k) {
			if (s[j]!=s[k]) {
				if (!diff) {
					left = j; right = k;
				}
				if (diff) b = false;
				diff = true;
				j++;
			}
			else {
				j++; k--;
			}
			if (b==false) break;
		}
		if (!diff) cout << -1 << endl;
		else {
			if (b==true) cout << left << endl;
			else cout << right << endl;
		}
	}
}