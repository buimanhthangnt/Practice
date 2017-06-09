#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	long l;
	cin >> l;
	char s[500002];
	cin >> s;
	long C[26];
	for (int i=0; i<26; i++) C[i] = 0;
	for (long i=0; i<l; i++) {
		switch (s[i]) {
			case 65: C[0]++; break;
			case 71: C[6]++; break;
			case 67: C[2]++; break;
			case 84: C[19]++; break;
		}
	}
	long nC[26];
	for (int i=0; i<26; i++) {
		if (C[i]<=l/4) nC[i] = 0;
		else nC[i] = C[i]-l/4;
	}
	long min = l;
	for (long i=0; i<l; i++) {
		char c = s[i];
		bool b = false;
		if ((nC[s[i]-65]>0 && (s[i]!=s[i-1] && i>0)) || (nC[s[i]-65]>0 && i==0)) {
			long tmp[5];
			tmp[1] = nC[0]; tmp[2] = nC[2]; tmp[3] = nC[6]; tmp[4] = nC[19];
			long count = 0;
			long j = i;
			while ((tmp[1]!=0 || tmp[2]!=0 || tmp[3]!=0 || tmp[4]!=0) && j<l) {
				switch (s[j]) {
					case 65: if(tmp[1]!=0) tmp[1]--; break;
					case 71: if(tmp[3]!=0) tmp[3]--; break;
					case 67: if(tmp[2]!=0) tmp[2]--; break;
					case 84: if(tmp[4]!=0) tmp[4]--; break;
				}
				j++;
				count++;
			}
			if (count<min && (tmp[1]==0 && tmp[2]==0 && tmp[3]==0 && tmp[4]==0)) min = count;
		}
	}
	if(min!=l) cout << min;
	else cout << 0;
}