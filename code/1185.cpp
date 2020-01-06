#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
char str[16];
int mp[105][15];
int cnt;
int dp[105][100][100];
int status[105];
struct sta{
    int x;
    int cnt;
}sta[105];

void pre(){
    for(int i = 0;i<(1<<m);i++){
         if( (i&(i<<1))==0 && (i&(i<<2))==0 ){
             sta[++cnt].x =i;
             for(int tmp=i;tmp;tmp=(tmp>>1)) if(tmp&1) sta[cnt].cnt ++;
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++){
        scanf("%s",str+1);
        for(int j = 1;j<=m;j++){
            if(str[j] == 'H') mp[i][j] = 1;
            status[i] <<=1;
            status[i] |=mp[i][j];
        }
    }
    pre();
    for(int i = 1;i<=cnt;i++){
        if(sta[i].x&status[1]) continue;
        dp[1][i][1] = sta[i].cnt;
    }

    for(int i = 1;i<=cnt;i++){
        if(sta[i].x&status[2]) continue;
        for(int j = 1;j<=cnt;j++){
            if(sta[j].x&status[1]) continue;
            if(sta[j].x & sta[i].x) continue;
            dp[2][i][j] = max(dp[2][i][j],dp[1][j][1]+sta[i].cnt);
        }
    }

    for(int i = 3;i<=n;i++){
        for(int j = 1;j<=cnt;j++){// i-2
            if(sta[j].x&status[i-2]) continue;
            for(int k = 1;k<=cnt;k++){
                if(sta[k].x&status[i-1]) continue;
                for(int l = 1;l<=cnt;l++){
                    if(sta[l].x&status[i]) continue;
                    if(sta[l].x&sta[k].x||sta[l].x&sta[j].x) continue;
                    dp[i][l][k] = max(dp[i][l][k],dp[i-1][k][j]+sta[l].cnt);
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1;i<=cnt;i++){
        for(int j = 1;j<=cnt;j++){
            ans = max(ans,dp[n][i][j]);
        }
    }
    printf("%d\n",ans);
}