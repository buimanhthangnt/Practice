#include <iostream>

using namespace std;

int N;

int prefer(int x, int y) {
	int i;
	for (i=1; i<=3; i++) {
		if (i!=x && i!=y) break;
	}
	return i;
}

void list(int n, int i, int j) {
	if (n==1) {
		cout << "Chuyen 1 dia tu coc " << i << " sang coc " << j << endl;
		return;
	}
	list(n-1,i,prefer(i,j));
	cout << "Chuyen 1 dia o coc " << i << " sang coc " << j << endl;
	list(n-1,prefer(i,j),j);
}

int main()
{
	cin >> N;
	cout << endl;
	list(N,1,3);
}