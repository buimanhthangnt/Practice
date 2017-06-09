#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;

int main()
{
	int n;
	cout << "Nhap 1 so trong khoang tu 8 den 12 roi nhan Enter: ";
	cin >> n;
	while (n<8 || n>12) {
		cout << "Vui long nhap lai n (8 <= n <= 12): ";
		cin >> n;
	}
	for (int i=-3*n/2; i<=n; i++) {
		for (int j=-3*n/2; j<=3*n/2; j++) {
			if (abs(i)+abs(j)<n 
				|| (n/2+i)*(n/2+i)+(-n/2+j)*(-n/2+j)<n*n/2
				|| (n/2+i)*(n/2+i)+(n/2+j)*(n/2+j)<n*n/2) {
				cout << "* ";
			}
			else cout << "  ";
		}
		cout << endl;
	}
	getch();
	return 0;
}