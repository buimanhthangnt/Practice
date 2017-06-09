#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[32][32];
bool mark[32];
int best = 9999, tmp = 0;;
int temp[32], path[32];
int count = 1;

void travel(int lb) {
	if (count==n+1) {
		if (map[lb][1]+tmp<best) {
			best = map[lb][1] + tmp;
			for (int i=1; i<=n; i++) path[i] = temp[i];
			path[count] = 1;
		}
		return;
	}
	for (int j=1; j<=n; j++) {
		if (!mark[j] && lb!=j && map[lb][j]!=9999) {
			if (tmp+map[lb][j]<best) {
				tmp += map[lb][j];
				temp[count] = j; count++;
				mark[j] = true;
				travel(j);
				mark[j] = false;
				count --;
				tmp -= map[lb][j];
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<32; i++) {
		for (int j=0; j<32; j++) {
			map[i][j] = 9999;
		}
	}
	for (int i=1; i<=m; i++) {
		int x, y, p;
		cin >> x >> y >> p;
		map[x][y] = p; map[y][x] = p;
	}
	temp[count] = 1;
	count++;
	mark[1] = true;
	travel(1);
	cout << best << endl;
	for (int i=1; i<=n+1; i++) {
		cout << path[i];
		if (i!=n+1) cout << "->";
	}
}