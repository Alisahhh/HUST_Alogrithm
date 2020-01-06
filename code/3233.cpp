#include<cstdio>
int n,m,K;

struct mat{
    int a[35][35];
}ans,tot,a;

mat add(mat a,mat b){
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            a.a[i][j] =(a.a[i][j]+ b.a[i][j])%m;
        }
    }
    return a;   
}



mat mult(mat a,mat b){
    mat ans;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            ans.a[i][j] = 0;
        }
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            for(int k = 1;k <= n;k ++){
                ans.a[i][j] = (ans.a[i][j]+a.a[i][k] * b.a[k][j])%m;
            }
            ans.a[i][j] %= m;
        }
    }
    return ans;
}

mat quick( mat a,int p){
    mat ans;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            ans.a[i][j] = 0;
        }
    }
    for(int i = 1;i<=n;i++)ans.a[i][i] =1;
    while(p){
        if(p&1){
            ans=mult(ans,a);
        }
        p>>=1;
        a = mult(a,a);
    }
    return ans;
}

mat solve(int x,mat& a){
    if(x == 1) return a;
    mat ans;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            ans.a[i][j] = 0;
        }
    }
    for(int i = 1;i<=n;i++) ans.a[i][i] = 1;
    ans = add(ans,quick(a,x>>1));
    ans = mult(ans, solve(x>>1,a));
    if(x&1){
        ans = add(ans,quick(a,x));
    }
    return ans;
}

int main(){
    scanf("%d%d%d",&n,&K,&m);
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n; j ++){
            scanf("%d",&a.a[i][j]);
        }
    }
    
    mat ans = solve(K,a);
    for(int  i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            printf("%d ",ans.a[i][j]);
        }
        printf("\n");
    }
    
}
