#include <iostream>

using namespace std;

typedef long long ll;

int n, m, count = 0;
long a[102][102], b[102], index[102];
bool visited[102];
ll ma = 0;

void initation() {
	for (int i=0; i<102; i++) 
		visited[i] = false;
}

void assess() {
	if (count>n) return;
	ll tmp = 0, j = 0;
	for (int i=1; i<=count; i++) {
		if (b[i]!=b[i-1]) j = 1;
		else j++;
		while (visited[j]==true) j++;
		tmp += a[j][b[i]];
		visited[j] = true;
	}
	if (tmp>ma) ma = tmp;
}

void analysis(int r, int prev) {
	if (r<=0) {
		assess();
		initation();
		return;
	}
	for (int i=prev; i>=1; i--) {
		if (r-i>=0) {
			count++; b[count] = i;
			analysis(r-i,i);
			count--;
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		index[i] = i;
		for (int j=1; j<=m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i=1; i<=m; i++) {
		for (int j=1; j<=n-1; j++) {
			for (int k=j+1; k<=n; k++) {
				if (a[j][i]<a[k][i]) {
					swap(a[j][i],a[k][i]);
					swap(index[j],index[k]);
				}
			}
		}
	}
	analysis(m,m);
	cout << ma;
}