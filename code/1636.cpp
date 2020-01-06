#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int N = 1e5+7;
struct ee{
    int v,nxt;
}e[N];
int cnt;
int head[N];
int vis[N];
int dp[2][105][105];
int n,m;
int p,q;
struct goods{
    int x,y;
};
vector<goods>good;
void ins(int u,int v){
    e[++cnt].v = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}

void dfs(int x){
    vis[x] = 1;
    if(x <= n) p ++;
    else q++;
    for(int i= head[x];i;i=e[i].nxt){
        int v = e[i].v;
        if(!vis[v]) dfs(v);
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        good.clear();
        memset(vis,0,sizeof(vis));
        cnt = 0;
        memset(head,0,sizeof(head));
        memset(dp,0,sizeof(dp));
        scanf("%d%d",&n,&m);
        for(int i = 1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            ins(u,v+n);
            ins(v+n,u);
        }
        
        for(int i = 1;i<=2*n;i++){
            if(!vis[i]){
                p = 0,q = 0;
                dfs(i);
                // printf("%d %d %d\n",i,p,q);
                good.push_back({p,q});
            }
        }
        int mn1,mn2,mn;
        mn1=mn2=mn=0;
        int p = 0,q = 1;    
        dp[p][0][0] = 1;
        for(int i = 1;i<=good.size();i++){
            for(int j = 0;j<=n/2;j++){
                for(int k = 0;k<=n/2;k++){
                    dp[q][j][k] |= dp[p][j][k];
                    if(j>=good[i-1].x&&k>=good[i-1].y)
                    	dp[q][j][k] |= dp[p][j-good[i-1].x][k-good[i-1].y];
                }
            }
            for(int j = 0;j<=n/2;j++){
                for(int k = 0;k<=n/2;k++){
                    dp[p][j][k] = 0;
                }
            }
            q^=1;
            p^=1;

        }
    	
        int mx = 0;
        for(int i = 0;i<=n/2;i++){
            if(dp[p][i][i]) mx = i;
        }
        printf("%d\n",mx);
    }
}

