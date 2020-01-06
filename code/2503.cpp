#include<cstdio>
#include<map>
#include<string>
#include<iostream>
#include<cstring>
using std::string;
using std::map;
using std::cout;
map<string,string>mp;
int main(){
    // freopen("1.txt","r",stdin);
    char str[100];
    while(fgets(str,100,stdin)){
        if(str[0] == '\r' || str[0] == '\n') break;
        char str1[15],str2[15];
        sscanf(str,"%s %s",str1,str2);
        // printf("%s %s\n",str1,str2);
        // printf("%d %d\n",strlen(str1),strlen(str2));
        mp[str2]=str1;
    }
    char str3[12];
    while(~scanf("%s",str3)){
        // cout<<str3<<"\n";
        // printf("%d\n",str3.length());
        if(mp.find(str3) != mp.end()){
            cout<<mp[str3]<<"\n";
        }else{
            cout<<"eh"<<"\n";
        }
    }
}
