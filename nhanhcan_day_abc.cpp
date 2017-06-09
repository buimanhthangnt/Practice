//chua hoan thanh
#include <iostream>
#include <conio.h>

using namespace std;

int n;
char *a, *ofic;
int numc = 0, best = 999;

bool checkSame(int x) {
	bool same;
	for (int i=1; i<=x/2; i++) {
		same = true;
		for (int j=0; j<i; j++) {
			if (a[x-j]!=a[x-i-j]) {
				same = false;
				break;
			}
		}
		if (same) break;
	}
	return same;
}

void show() {
	for (int i=1; i<=n; i++) {
		cout << a[i];
	} cout << "  " << numc;
	cout << endl;
}

void ctry(int i) {
	if (i==n+1) {
			        best = numc;
			        for (int i=1; i<=n; i++) ofic[i] = a[i];
		        	return;
				}
	for (char j='A'; j<='C'; j++) {
		a[i] = j;
		if (!checkSame(i)) {
			if (j=='C') numc++;
			if (numc-1+(n-i)/4<best) {
				
				//else {
					ctry(i+1);
					if (j=='C') numc--;
				//}
			}
		}
	}
}

void dayabc(int k) {
	if (k==n+1) {
		if (numc<best) {
			best = numc;
			for (int i=1; i<=n; i++) ofic[i] = a[i];
		}
		return;
	}
	for (char i='A'; i<='C'; i++) {
		a[k] = i;
		if (!checkSame(k)) {
			if (i=='C') numc++;
			if (numc-1+(n-k)/4>=best) return;
			dayabc(k+1);
			if (i=='C') numc--;
		} 
	}
}

int main()
{
	cin >> n;
	a = new char[n+4];
	ofic = new char[n+4];
	dayabc(1);
	//ctry(1);
	for (int i=1; i<=n; i++) {
		cout << ofic[i];
	}
	cout << "  " << best;
}