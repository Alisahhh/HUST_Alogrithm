#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdlib>

using namespace std;
int a[1005];
int sum1(int a,int b,int c,int d){
  return c+a+d+a;
}

int sum2(int a,int b,int c,int d){
  return b+a+d+b;
}

int solve(int l,int r){
  if(r-l+1==3){
    int tmp=0;
    for(int i=l;i<=r;i++) tmp+=a[i];
    return tmp;
  }
  if(r-l+1<=2) return a[r];
  int mid=min(sum1(a[l],a[l+1],a[r-1],a[r]),sum2(a[l],a[l+1],a[r-1],a[r]));
  return solve(l,r-2)+mid;
}

int main(){
  int T,n;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int ans=solve(1,n);
    printf("%d\n",ans);
  }
  return 0;
}