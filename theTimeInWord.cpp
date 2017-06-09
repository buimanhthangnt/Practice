#include <iostream>

using namespace std;

void read(int num) {
	switch (num) {
		case 0: cout << "o' clock"; break;
		case 1: cout << "one"; break;
		case 2: cout << "two"; break;
		case 3: cout << "three"; break;
		case 4: cout << "four"; break;
		case 5: cout << "five"; break;
		case 6: cout << "six"; break;
		case 7: cout << "seven"; break;
		case 8: cout << "eight"; break;
		case 9: cout << "nine"; break;
		case 10: cout << "ten"; break;
		case 11: cout << "eleven"; break;
		case 12: cout << "twelve"; break;
		case 13: cout << "thirteen"; break;
		case 14: cout << "fourteen"; break;
		case 15: cout << "quarter"; break;
		case 16: cout << "sixteen"; break;
		case 17: cout << "seventeen"; break;
		case 18: cout << "eightteen"; break;
		case 19: cout << "nineteen"; break;
		case 20: cout << "twenty"; break;
	}
}

void readNum(int num) {
	if (num<=20) {
		read(num);
	}
	else {
		if (num==30) cout << "half";
		else {
			cout << "twenty ";
			read(num%10);
		}
	}
}

int main()
{
	int h, m;
	cin >> h >> m;
	if (m<=30) {
		if (m==0) {
			readNum(h);
			cout << " ";
			readNum(m);
		}
		else {
			readNum(m);
			if (m!=15 && m!=30) {
				if (m>1) cout << " minutes";
				else cout << "minute";
			}
			
			cout << " past ";
			readNum(h);
		}
	}
	else {
		readNum(60-m);
		if (m!=45 && m!=30) {
				if (m>1) cout << " minutes";
				else cout << "minute";
			}
		cout << " to ";
		readNum(h+1);
	}
}