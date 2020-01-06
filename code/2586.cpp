#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
int vis[6];
int month[15];
int main(){
    int s,d;
    // ?vector<int>
    while(scanf("%d%d",&s,&d)!=EOF){
        int ans = -1e9;
        // if(4*d<=s || 4*s<=d){
        //     printf("Deficitn\n");
        //     continue;
        // }
        for(int i = 1;i<=4;i++){
            if(i*d>(5-i)*s){
                if(i<=3){
                    ans = max(ans,s*(12-i*2)-d*(2*i));
                    // printf("%d\n",s*(12-i*2)-d*(2*i));
                }else{
                    ans = max(ans,s*3-d*9);
                    // printf("%d\n",s*3-d*9);
                }
            }
        }
        if(ans>0) printf("%d\n",ans);
        else printf("Deficit\n");
    }
}