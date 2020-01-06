#include<cstdio>
#include<algorithm>
using namespace std;
int fx[4] = {0,0,1,-1};
int fy[4] = {1,-1,0,0};

int n,m;
int f[105][105];
int a[105][105];

void dfs(int x,int y){
    // printf("%d %d\n",x,y);
    f[x][y]  = 1;
    for(int i = 0;i<4;i++){
        int nx = x + fx[i];
        int ny = y + fy[i];
        if(nx <=0 || nx >n || ny <=0 || ny > m || a[nx][ny] >= a[x][y]) continue;
        if(f[nx][ny] == 0) dfs(nx,ny);
        f[x][y] = max(f[x][y],f[nx][ny] + 1);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    int mx = 0;
    int mxx = 0;
    int mxy = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j] > mx){
                mx = a[i][j];
                mxx = i;
                mxy = j;
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            dfs(i,j);
        }
    }
    // dfs(mxx,mxy);
    int ans = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            ans = max(ans,f[i][j]);
        }
    }
    printf("%d\n",ans);
}