#include <iostream>
#include <stack>
#include <conio.h>

using namespace std;

int n, k, mo = 0, degree = 0;
char a[222];
long count = 0;

void show(int x) {
	for (int i=1; i<=x; i++) cout << a[i];
	cout << endl;
}

int getDegree(int x) {
	int count = 0, d = 0;
	for (int i=1; i<=x; i++) {
		if (a[i]=='(') count++;
		else count--;
		if (count>d) d = count;
	}
	return d;
}

void dayngoac(int x) {
	if (x==n+1) {
		if (mo==0 && getDegree(n)==k) {
			//show(n);
		}
		return;
	}
	for (char i='('; i<=')'; i++) {
		a[x] = i;
		if (i=='(' && getDegree(x)>k) continue;
		if (i==')') {
			if (mo==0) return;
			else mo--;
		} else {
			mo++;
			if (mo>(n-x)) {
				mo--;
				continue;
			}
		}
		dayngoac(x+1);
		if (i==')') mo++;
		else mo--;
	}
}

int main()
{
	cin >> n >> k;
	dayngoac(1);
}