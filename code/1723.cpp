#include<cstdio>
#include<algorithm>
using namespace std;
int a[10005],b[10005],tmp[10005];
int n;
int main(){
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d%d",&a[i],&b[i]);

    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for(int i = 1;i<=n;i++){
        a[i] -= i;
    }
    sort(a+1,a+n+1);
    int tmp1 = a[(n+1)/2];
    int tmp2 = b[(n+1)/2];
    // printf("%d %d\n",tmp1,tmp2);
    long long ans = 0;
    for(int i = 1;i<=n;i++){
        // ans = ans + a[i] - tmp1;
        ans = ans + abs(b[i] - tmp2);
    }
    for(int i = 1;i<=n;i++){
        // printf("%d ",tmp[i]);
        ans = ans + abs(a[i] - tmp1);
    }
    printf("%lld\n",ans);
}