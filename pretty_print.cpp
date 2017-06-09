#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
		char s[1111];
		int i = 0;
		long long inta = (long long) A;

		while (inta>0) {
			if (inta % 16 < 10) s[i] = inta % 16 + 48;
			else s[i] = inta % 16 + 87;
			inta = inta / 16;
			i++;
		}
		cout << i << endl;
		cout << setw(2) << internal;
			cout << "0x"; cout << setw(0) << internal; i--;
			while(i>=0) {
				cout << s[i]; i--;
			}
			cout << endl;
			
			long long intb = (long long) B;
			if (intb < 0) intb *= -1;
			i = 0;
			while (intb>0) {
				intb /= 10;
				i++;
			}
			for (int j=1; j<=15-i-4; j++) cout << "_";
			if (B>0) cout << "+";
			cout << fixed;
			cout << setprecision(2) << B << endl;
			cout << setprecision(9) << scientific << C << endl;
		}
	return 0;
}