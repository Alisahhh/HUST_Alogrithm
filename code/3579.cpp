#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
int a[100005];
int n;


int check(int x){
    ll num = 0;
    int head = 1, tail = 1;
    while(head<=n){
        while(a[tail]-a[head]<x && tail<n){
            tail++;
        }
        while(a[tail]-a[head]>=x) tail --;
        num += (tail - head);
        head++;
    }
 
    if(num < (((ll)(n)*(ll)(n-1)/2)+1)/2){
        return 1;
    }
    return 0;
}

int main(){
    while(~scanf("%d",&n)){
        for(int i = 1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int ans;
        sort(a+1,a+n+1);
        int L = 0,R = a[n] - a[1];
        while(L<=R){
            int mid = (L+R)>>1;
            if(check(mid)){
                ans = mid;
                L = mid + 1;
            }else{
                R = mid - 1;
            }
        }
        printf("%d\n",ans);
    }
}
