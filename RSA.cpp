#include <iostream>
#include <cmath>

using namespace std;

long long findKey(long long On, long long e) {
    long long schia, sbichia, du, thuong, y1, y2, y3;
    schia = On;
    sbichia = e;
    y1 = 0, y2 = 1;
    while (sbichia>1) {
        thuong = schia/sbichia;
        du = schia%sbichia;
        schia = sbichia;
        sbichia = du;
        y3 = y1-thuong*y2;
        y1 = y2; y2 = y3;
    }
    if (y3<0) return y3+On;
    else return y3;
}

long long encodingName(string name) {
    long i = 0;
    long size;
    while (name[i]!='\0') i++;
    size = i - 1;
    i = 0;
    long long encodedNum = 0;
    while (name[i]!='\0') {
        encodedNum += (name[i]-97)*pow(26,size);
        size--;
        i++;
    }
    return encodedNum;
}

long long encoding(long long m, long long e, long long n) {
    long long r, power = m%n, x = 1;
    while (e>0) {
        r = e%2;
        e = e/2;
        if (r==1) x = (x*power) %n;
        power = (power*power)%n;
    }
    return x % n;
}

long long decoding(long long c, long long d, long long n) {
    long long r, power = c%n, x = 1;
    while (d>0) {
        r = d%2;
        d = d/2;
        if (r==1) x = (x*power) %n;
        power = (power*power)%n;
    }
    return x % n;
}

int main()
{
    string name;
    cout << "Nhap ten cua ban (nhap bang chu thuong): ";
    cin >> name;
    long long p, q, e, d, n, On, m;
    p = 12569;
    q = 10853;
    e = 1291793;
    m = encodingName(name);
    cout << endl;
    cout << "So duoc ma hoa tu ten la: " << m << endl;
    n = p*q;
    On = (p-1) * (q-1);
    d = findKey(On,e);
    cout << "Khoa bi mat la d = " << d << endl;
    long long c = encoding(m,e,n);
    cout <<"So da ma hoa la: " << c << endl;
    cout << "So da giai ma la: " << decoding(c,d,n) << endl;
}
