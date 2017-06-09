#include <iostream>
#include <cstring>

using namespace std;

long th(long n, long k) {
    long res = 1;
    for (long i = n; i>=n-k+1; i--) {
        res *= i;
    }
    for (int i=1; i<=k; i++) {
        res /= i;
    }
    return res;
}

int main()
{
    char s[10002];
    cin >> s;
    long si = 0, sum = 0, dou = 0, count = 0;
    char first, second, third;
    first = s[0]; second = s[1];
    if (first==second) {
        si = 1;
    }
    third = s[2];
    if (third==second) si++;
    else {
        sum = si; if (si!=0) count++; si = 0;
        if (third==first) dou++;
    }
    for (long i=3; s[i]!='\0'; i++) {
        first = second; second = third; third = s[i];
        if (third==second) {
            si++;
        }
        else {
            sum += si; if (si!=0) count++; si = 0; 
            if (third==first) dou++;
        }
    }
    if (si!=0) {
        count++;
        sum += si;
    }
    //cout << count << " " << sum << " " << dou << th(16,2);
    cout << th(strlen(s)-sum,2) + count - dou;
}