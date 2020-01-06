#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
using namespace std;

struct point{
    double left, right;
}p[2010], temp;

bool operator < (point a, point b){
    return a.left < b.left;
}

int main(){
    int n;
    double r;
    int kase = 0;
    while(1){
        scanf("%d%lf",&n,&r);
        if(n==0&&r==0)break;
        bool flag = false;
        for (int i = 0; i < n; i++){
            double a, b;
            scanf("%lf%lf",&a,&b);
            if (fabs(b) > r){
                flag = true;
            }
            else{
                p[i].left = a * 1.0 - sqrt(r * r - b * b);
                p[i].right = a * 1.0 + sqrt(r * r - b * b);
            }
        }
        cout << "Case " << ++kase << ": ";
        if (flag){
            cout << -1 << endl;
        }
        else{
            int count = 1;
            sort(p, p + n);
            temp = p[0];
            for (int i = 1; i < n; i++){
                if (p[i].left > temp.right){
                    count++;
                    temp = p[i];
                }
                else if (p[i].right < temp.right){
                    temp = p[i];
                }
            }
            cout << count << endl;
        }
    }
    return 0;
}