#include<cstdio>
#include<algorithm>
using namespace std;
struct coin_strcut{
    int v;
    int b;
}coin[25];

bool cmp(coin_strcut a,coin_strcut b){
    return a.v<b.v;
}

int main(){
    int n,c;
    long long ans = 0;
    scanf("%d%d",&n,&c);
    for(int i = 1;i<=n;i++){
        scanf("%d%d",&coin[i].v,&coin[i].b);
    }
    sort(coin+1,coin+n+1,cmp);
    int tot = 0;
    for(int i = 1;i<=n;i++){
        if(coin[i].v>=c){
            ans+=coin[i].b;
            coin[i].b=0;
        }else tot = i;
    }

    while(1){
        int need = c;
        for(int i = tot;i>=1;i--){
            if(need > 0 && coin[i].b > 0){
                int t = min(coin[i].b,need/coin[i].v);
                coin[i].b-=t;
                need -= t*coin[i].v;
            }
       }
       for(int i = 1;i<=tot;i++){
            if(need > 0 && coin[i].b > 0){
                int t = min(coin[i].b,(need+coin[i].v-1)/coin[i].v);
                coin[i].b-=t;
                need -= t*coin[i].v;
            }
       }
       if(need > 0) break;
       ans++;
       need = c;
    }
    printf("%lld\n",ans);
}