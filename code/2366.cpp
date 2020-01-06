#include<cstdio>
#include<map>
using std::map;
int vis[100000];
int main(){
    int n,m;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        vis[x+32768] = 1;
    }
    scanf("%d",&m);
    int flag = 0;
    for(int i = 1;i<=m;i++){
        int x;
        scanf("%d",&x);
        if(10000-x+32768<0 || 10000-x+32768 > 100000) continue;
        if(vis[10000-x+32768]){
            flag = 1;
            
        }
    }
    if(flag){
        printf("YES\n");
    }else printf("NO\n");
}