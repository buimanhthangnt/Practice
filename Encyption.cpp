#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
	char a[2222];
	cin >> a;
	char b[22][22];
	//cout << strlen(a);
	int rc = int(sqrt(strlen(a)));
	int r = rc, c = rc;
	if (r*c<strlen(a)) c++;
	if (r*c<strlen(a)) r++;
	//cout << c << " " << r;
	int count = -1;
	for (int i=1; i<=r; i++) {
		for (int j=1; j<=c; j++) {
			count++;
			if(count<strlen(a)) b[i][j] = a[count];
			else b[i][j] = 32;
			//cout << b[i][j];
		}
		//cout << endl;
	}
	//cout << endl;
	for (int i=1; i<=c; i++) {
		for (int j=1; j<=r; j++) {
			if(b[j][i]!=32) cout << b[j][i];
		}
		if(i!=c) cout << " ";
	}
}