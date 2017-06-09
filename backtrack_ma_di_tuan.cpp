#include <iostream>
#include <queue>

using namespace std;

int map[32][32];
queue<int> path;
int a[8] = {-2,-1,1,2,2,1,-2,-1};
int b[8] = {-1,-2,-2,-1,1,2,1,2};
int size;

void show() {
	while (!path.empty()) {
		int temp1 = path.front(), temp2 = path.front();
		cout << "(" << temp1 << "," << temp2 << ")";
		cout << " ";
		path.pop(); path.pop();
	}
}

bool quanma(int x, int y, int count) {
	if (count==size*size+1) {
		show();
		return true;
	}
	//cout << "a";
	path.push(x); path.push(y);
	for (int i=0; i<8; i++) {
		if (x+a[i]>0 && x+a[i]<=size && y+b[i]>0 && y+b[i]<=size && map[x+a[i]][y+b[i]]==0) {
			map[x+a[i]][y+b[i]] = 1;
			bool end = quanma(x+a[i],y+b[i],count+1);
			if (end) return true;
			map[x+a[i]][y+b[i]] = 0;
			path.pop(); path.pop();
		}
	}
	return false;
}

int main()
{
	cin >> size;
	map[3][3] = 1;
	quanma(3,3,1);
}