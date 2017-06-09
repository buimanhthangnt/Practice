#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int* quickSort(int *a, int first, int last) {
	if (first>=last) return a;
	int pivot = rand()%(last-first+1) + first;
	int i = first-1, j = last+1;
	while (i<j) {
		if (i<pivot) i++;
		if (j>pivot) j--;
		while (*(a+i) < *(a+pivot) && i<pivot) i++;
		while (*(a+j) > *(a+pivot) && j>pivot) j--;
		swap(*(a+i),*(a+j));
		if (i==pivot) pivot = j;
		else if (j==pivot) pivot = i;
	}
	quickSort(a,first,pivot-1);
	quickSort(a,pivot+1,last);
	return a;
}

int main()
{
	srand(time(NULL));
	int *a;
	int n;
	cin >> n;
	a = new int[n+1];
	for (int i=1; i<=n; i++)
		a[i] = rand()%100003;
	a = quickSort(a,1,n);
	// for (int i=1; i<=n; i++) {
 //        cout << *(a+i) << " ";
	// }
	cout << endl;
}
