#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
double ans_min;
struct dott{
    double x,y;
    int v;
}dot[200005];
int n;

double sqr(double x){
    return x*x;
}


bool cmp1(dott a,dott b){
    if(a.x == b.x) return a.y<b.y;
    return a.x<b.x;
}

bool cmp2(dott a,dott b){
    if(a.y == b.y) return a.x<b.x;
    return a.y<b.y;
}

double dis(int x,int y){
    return sqrt(sqr(dot[x].x-dot[y].x) + sqr(dot[x].y-dot[y].y));
}

void solve(int l,int r){
    if(r-l<=3){
        sort(dot+l,dot+r,cmp2);
        for(int i = l;i <= r;i ++){
            for(int j = i+1;j <= r;j++){
            	if(dot[i].v == dot[j].v)continue; 
                double tmp = dis(i,j);
                ans_min = min(ans_min,tmp);
            }
        }
        return;
    }
    int mid = (l+r)>>1;
    solve(l,mid);
    solve(mid+1,r);
    for(int i = l;i<=mid;i++){
        if(abs(dot[i].x - dot[mid].x) > ans_min) break;
        for(int j = mid+1;j<=2*n;j++){
            if(abs(dot[j].x - dot[mid].x) > ans_min) break;
            if(abs(dot[i].x - dot[i].y) > ans_min) break;
            if(dot[i].v == dot[j].v) continue;
            double tmp = dis(i,j);
            ans_min = min(ans_min,tmp);
        }
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i = 1;i<=n;i++){
            scanf("%lf%lf",&dot[i].x,&dot[i].y);
            dot[i].v = 1;
        }
        for(int i = 1;i<=n;i++){
            scanf("%lf%lf",&dot[i+n].x,&dot[i+n].y);
            dot[i+n].v = 2;
        }
        sort(dot+1,dot+2*n+1,cmp1);
        ans_min = 1e20+7;
        solve(1,2*n);
        printf("%.3f\n",ans_min);
    }
}
