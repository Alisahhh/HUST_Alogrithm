#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a[105][105],b[105][105],c[105];
int n;

int main(){
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            b[i][j] = b[i-1][j] + a[i][j]; 
        }
    }
    int ans = -1e9+7;
    for(int i = 1;i<=n;i++){
        for(int j = i;j<=n;j++){
            for(int k = 1;k<=n;k++){
                c[k] = b[j][k] - b[i-1][k];
            }
            int tmp = 0;
            for(int k = 1;k<=n;k++){
                if(tmp<0) tmp = c[k];
                else tmp=tmp+c[k];
                ans = max(ans,tmp);
            }
        }
    }
    printf("%d\n",ans);
}