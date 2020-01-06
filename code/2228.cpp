#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 3835;
int a[N];
int dp[2][N][2];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    memset(dp,0xfffff,sizeof(dp));
    int p = 0,q = 1;
    dp[p][0][0] = 0;
    dp[p][1][1] = 0;
    
    for(int i = 2;i<=n;i++){
        for(int j = 0;j<=m;j++){
            dp[q][j][0] = max(dp[p][j][0],dp[p][j][1]);
            if(j>1)dp[q][j][1] = max(dp[p][j-1][0],dp[p][j-1][1]+a[i]);
        }
        for(int j = 0;j<=m;j++) dp[p][j][0] = dp[p][j][1] = 0;
        p^=1;
        q^=1;
    }
    int ans = max(dp[p][m][0],dp[p][m][1]);
    memset(dp,0xfffff,sizeof(dp));
    p = 0;q = 1;
    dp[p][1][1] = a[1];
    for(int i = 2;i<=n;i++){
        for(int j = 0;j<=m;j++){
            dp[q][j][0] = max(dp[p][j][0],dp[p][j][1]);
            if(j>1)dp[q][j][1] = max(dp[p][j-1][0],dp[p][j-1][1]+a[i]);
        }
        for(int j = 0;j<=m;j++) dp[p][j][0] = dp[p][j][1] = 0;
        p^=1;
        q^=1;
    }
     ans = max(dp[p][m][1],ans);
     printf("%d\n",ans);
}