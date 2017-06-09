#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stack>

using namespace std;

long *a;

void quickSort(long l, long r) {
	if (l>=r) return;
	long pivot = a[rand()%(r-l+1)+l];
	long i = l, j = r;
	while (i<=j) {
		while (a[i]<pivot) i++;
		while (a[j]>pivot) j--;
		if (i<=j) {
			swap(a[i],a[j]);
			i++; j--;
		}
	}
	quickSort(l,j); quickSort(i,r);
}

void quickSort2(long *a, long l, long r) {
	stack<long> s;
	s.push(l); s.push(r);
	do {
		r = s.top(); s.pop();
		l = s.top(); s.pop();
		while (l<r) {
			long i = l, j = r;
			long pivot = a[rand()%(r-l+1)+l];
			while (i<=j) {
				while (a[i]<pivot) i++;
				while (a[j]>pivot) j--;
				if (i<=j) {
					swap(a[i],a[j]);
					i++; j--;
				}
			}
			if (i<r) {
				s.push(i); s.push(r); 
			}
			r = j;
		} 
	} while (!s.empty());
}

int main() 
{
	srand(time(NULL));
	long n;
	cin >> n;
	a = new long[n+1];
	for (long i=0; i<n; i++) {
		a[i] = rand()%100000;
	}
	quickSort2(a,0,n-1);
	//quickSort(0,n-1);
	for (int i=0; i<n; i++) {
		cout << a[i] << " ";
	}
}