#include<cstdio>
#include<algorithm>
using namespace std;
int x[10005],y[10005];
int fx[4] = {0,0,1,-1};
int fy[4] = {1,-1,0,0};

struct {
    int x,y;
}cow[10005];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d%d",&x[i],&y[i]);
        cow[i].x = x[i];
        cow[i].y = y[i];
    }
    sort(x+1,x+n+1);
    sort(y+1,y+n+1);
    int tmp1 = x[(n+1)/2];
    int tmp2 = y[(n+1)/2];
    int ans1 = 1e9+7;
    if(n%2){
        int ans2 = 0;
        int ansx,ansy,nx,ny;
        int flag = 0;
        for(int i = 1;i<=n;i++){
            if(cow[i].x == tmp1 && cow[i].y == tmp2){
                flag = 1;
                break;
            }
        }
        if(!flag){
            ans1 = 0;
            for(int i  = 1;i<=n;i++){
                ans1 += abs(cow[i].x - tmp1);
                ans1 += abs(cow[i].y - tmp2);
            }
            printf("%d 1\n",ans1);
            return 0;
        }
        for(int i = 0;i<4;i++){
            nx = tmp1 + fx[i];
            ny = tmp2 + fy[i];
            int flag = 1;
            for(int j = 1;j<=n;j++){
                if(nx == cow[j].x && ny == cow[j].y) {
                    flag = 0;
                    break;
                }
            }
            if(flag){
                ansx = nx;
                ansy = ny;
                int  tmpans= 0;
                for(int j = 1;j<=n;j++){
                    tmpans += abs(cow[j].x-ansx);
                    tmpans += abs(cow[j].y-ansy);
                }
                if(tmpans<ans1){
                    ans1 = tmpans;
                    ans2 = 1;
                }else if(tmpans == ans1){
                    ans2++;
                }
            }
        }
        printf("%d %d\n",ans1,ans2);
        return 0;
    }
    int ans2 = ((x[n/2+1]-x[n/2])+1)*((y[n/2+1]-y[n/2]+1));
    for(int i = 1;i<=n;i++){
        if(cow[i].x<=x[n/2+1] && cow[i].x>=x[n/2] && cow[i].y<=y[n/2+1]&& cow[i].y>=y[n/2]) ans2--;
    }
    ans1 = 0;
    for(int i = 1;i<=n;i++){
        ans1 += abs(tmp1 - cow[i].x);
        ans1 += abs(tmp2 - cow[i].y);
    }
    printf("%d %d\n",ans1,ans2);

}