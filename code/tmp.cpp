//行数 R 和列数 C(1 <= R,C <= 100)
//高度 h，0<=h<=10000
//1088
//思想：c[i,j]=max(1,(c[i,j]>c[i-1,j]?c[i-1,j]+1:0),(c[i,j]>c[i+1,j]?c[i+1,j]+1:0),
//                   (c[i,j]>c[i,j-1]?c[i,j-1]+1:0),(c[i,j]>c[i,j+1]?c[i,j+1]+1:0))
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int R;
int C;
int M[102][102];
int N[102][102];
int len = 0;
struct node{
	int X;
	int Y;
}a[11000];

void path(int N[102][102],int M[102][102],int i,int j){
	N[i][j] = max(
				max((M[i][j]>M[i][j+1]?N[i][j+1]+1:1),(M[i][j]>M[i-1][j]?N[i-1][j]+1:1)),
	              max((M[i][j]>M[i+1][j]?N[i+1][j]+1:1),(M[i][j]>M[i][j-1]?N[i][j-1]+1:1)));
	if(N[i][j]>len) len = N[i][j];
}

bool line(struct node &a,struct node &b){
	return M[a.X][a.Y]<M[b.X][b.Y];
}

int main(void){
	int i,j;
	scanf("%d %d",&R,&C);
	for(j=1;j<=C;j++) M[0][j] = 10001,M[R+1][j] = 10001;
	for(i=1;i<=R;i++) M[i][0] = 10001,M[i][C+1] = 10001;
	for(i=1;i<=R;i++) for(j=1;j<=C;j++) scanf("%d",&M[i][j]);
	for(int  i = 1;i<=R;i++){
        for(int j = 1;j<=C;j++){
            printf("%d ",M[i][j]);
        }
        printf("\n");
    }
	for(i=0;i<R;i++) for(j=0;j<C;j++){
	
		a[i*C+j].X = i+1,a[i*C+j].Y = j+1;
		printf("%d\n",i*R+j);
	}
	sort(a,a+R*C,line);
	for(i=0;i<R;i++) for(j=0;j<C;j++) 
	path(N,M,a[i*R+j].X,a[i*R+j].Y);
	printf("%d\n",len);
    for(int  i = 1;i<=R;i++){
        for(int j = 1;j<=C;j++){
            printf("%d ",N[i][j]);
        }
        printf("\n");
    }
	return 0;
}
