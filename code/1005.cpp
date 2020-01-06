#include<cstdio>
#include<cmath>
const double pi = 3.14159265357;
double dist(double x,double y){
    return sqrt(x*x+y*y);
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        double x,y;
        scanf("%lf%lf",&x,&y);
        double r = dist(x,y);
        double area = r*r*pi;
        int ans = ceil(area / 100.0);
        printf("Property %d: This property will begin eroding in year %d.\n",i,ans);
    }
    printf("END OF OUTPUT.\n");
}