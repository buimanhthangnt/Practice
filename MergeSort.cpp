#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int* mergeSort(int* a, int first, int last) {
	if (first==last) {
		int *e;
		e = new int[2];
		e[1] = a[first];
		return e;
	}
	int mid = (first + last) / 2;
	int *b, *c, *d;
	d = new int[last-first+2];
	b = mergeSort(a,first,mid);
	c = mergeSort(a,mid+1,last);
	int i = 1, j = 1, k = 1;
	while (k<=last-first+1) {
        if (i>mid-first+1) {
   			d[k] = c[j]; k++; j++;
        }
        else {
           	if (j>last-mid) {
            	d[k] = b[i]; k++; i++;
            }
            else {
            	d[k] = (b[i]<c[j])? b[i]:c[j];
              	if (b[i]<c[j]) i++;
              	else j++;
                k++;
            }
        }
	}
	return d;
}

int main()
{
	int *a, n;
	cin >> n;
	a = new int[n+1];
	for (int i=1; i<=n; i++)
		a[i] = rand()%10003;
	a = mergeSort(a,1,n);
	for (int i=1; i<=n; i++) {
		cout << a[i] << " ";
	}
}
