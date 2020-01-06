#include<cstdio>
#include<cstring>
#include<stack>
using std::stack;

bool check(char *str){
    int len = strlen(str);
    stack<int>st;
    int value[5];
    for(int i = 0; i < (1<<5);i++){
        for(int j  = 0;j < 5;j ++){
            value[j] = ((i&(1 << j))>>j);
        }
        int ans = 0;
        int op = 0;
        while(!st.empty()) st.pop();
        for(int j = len - 1; j >= 0;j --){
    
            switch(str[j]){
                case 'K':{
                    int x = st.top();
                    st.pop();
                    int y = st.top();
                    st.pop();
                    int now = x && y;
                    st.push(now);
                    break;
                }
                case 'A':{
                    int x = st.top();
                    st.pop();
                    int y = st.top();
                    st.pop();
                    int now = x || y;
                    st.push(now);
                    break;
                }
                case 'N':{
                    int x = st.top();
                    st.pop();
                    x = !x;
                    st.push(x);
                    break;
                }
                case 'C':{
                    int x = st.top();
                    x ^= 1;
                    st.pop();
                    int y = st.top();
                    st.pop();
                    int now = x|| y;
                    st.push(now);
                    break;
                }
                case 'E':{
                    int x = st.top();
                    st.pop();
                    int y = st.top();
                    st.pop();
                    int now = (x == y);
                    st.push(now);
                    break;
                }
                case 'p':{
                    st.push(value[0]);
                    break;
                }
                case 'q':{
                    st.push(value[1]);
                    break;
                }
                case 'r':{
                    st.push(value[2]);
                    break;
                }
                case 's':{
                    st.push(value[3]);
                    break;
                }
                case 't':{
                    st.push(value[4]);
                    break;
                }
            }
            
        }
        if(st.top() == 0 || st.size() != 1) return 0;
    }
    return 1;
}

int main(){
    while(1){
        char str[105];
        scanf("%s",str);
        if(str[0] == '0') break;
        if(check(str)){
            printf("tautology\n");
        }else{
            printf("not\n");
        }
    }
}
