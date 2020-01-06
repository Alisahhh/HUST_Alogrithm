#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
using std::queue;
const int fx[4] = {1,0,-1,0};
const int fy[4] = {0,-1,0,1};
queue<int>q;

int getIdFromMat(int mat[6][6]){
    int ans = 0;
    for(int i = 1;i <= 4;i ++){
        for(int j = 1;j <= 4; j ++){
            ans <<= 1;
            ans |= mat[i][j];
        }
    }
    return ans;
}

void getMatFromId(int ID,int (*mat)[6]){
    for(int i = 4;i>=1;i--){
        for(int j = 4;j>=1;j--){
            mat[i][j] = ID&1;
            ID >>= 1;
        }
    }
}

int main(){
    int mp[6][6];
    int vis[65536];
    memset(mp,-1,sizeof(mp));
    memset(vis,0x3f3f3f,sizeof(vis));
    for(int i = 1;i <= 4; i++ ){
        char str[10];
        scanf("%s",str+1);
        for(int j = 1;j <=4;j++){
            if(str[j] == 'w') mp[i][j] = 0;
            else mp[i][j] = 1;
        }
    }  
    int begin = getIdFromMat(mp);
    q.push(begin);
    vis[begin] = 1;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now == 0 || now == 65535) break;
        int mat[6][6];
        getMatFromId(now,mat);
        for(int i = 1;i <= 4;i++){
            for(int j = 1;j<=4;j++){
                getMatFromId(now,mat);
                mat[i][j] ^=1;
                for(int k = 0; k < 4; k++){
                    int nx = i + fx[k];
                    int ny = j + fy[k];
                    if(mp[nx][ny] == -1) continue;
                    mat[nx][ny] ^= 1;
                }
                int nid = getIdFromMat(mat);
                if(vis[nid] > vis[now] + 1){
                    vis[nid] = vis[now] + 1;
                    q.push(nid);
                    // for(int i = 1;i<=4;i++){
                    //     for(int j = 1;j<=4;j++){
                    //         printf("%d ",mat[i][j]);
                    //     }
                    //     printf("\n");
                    // }
                }
            }
        }
    }
    int ans = std::min(vis[0],vis[65535])-1;
    if(ans > 100000){
        printf("Impossible\n");
    }else printf("%d\n",ans);
}
