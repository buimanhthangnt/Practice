#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char s[100002];
	cin >> s;
	int count[26];
	for (int i=0; i<26; i++) {
		count[i] = 0;
	}
	for (int i=0; i<strlen(s); i++) {
		count[s[i]-97]++;
	}
	int c = 0;
	for (int i=0; i<26; i++) {
		if (count[i]%2==1) c++;
	}
	if (c>1) cout << "NO";
	else cout << "YES";
}