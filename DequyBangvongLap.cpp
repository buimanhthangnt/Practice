#include<iostream>
#include<fstream>
using namespace std;

int n,m,x1,y1,x2,y2;
int qx[1000010],qy[1000010],visited[1010][1010];
int dx[] = {-1,-2,-2,-1, 1, 2,2,1};
int dy[] = { 2, 1,-1,-2,-2,-1,1,2};

int main(){
    ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    //freopen("input.txt","r",stdin);

	for(int i=0;i<1010;i++)
		for(int j=0;j<=1010;j++)
			visited[i][j] =0;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    int l=0,r=0,x,y,xx,yy;
    qx[0] = x1,qy[0] = y1;
    visited[y1][x1] = 1;
    while(l<=r){
        x = qx[l],y = qy[l],l+=1;
        if(x==x2 && y==y2) break;
        for(int i=0;i<8;i++){
            xx = x + dx[i];
            yy = y + dy[i];

            if(xx<=0 || xx>n || yy<=0 || yy>m) continue;

            if(visited[yy][xx]==0){
                visited[yy][xx] = visited[y][x]+1;
                r+=1, qx[r] = xx, qy[r] = yy;
            }
            for (int p=1; p<=n; p++) {
    			for (int q=1; q<=m; q++) {
    				cout << visited[p][q] << " ";
    			}
    			cout << endl;
    		}
    		cout << endl;
        }
    }
    cout << visited[y2][x2]-1 << endl;

    

    return 0;
}