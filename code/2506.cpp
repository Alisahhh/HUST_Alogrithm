#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
int n;

struct BigInteger
{
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    vector<int> s;
 
    BigInteger (long long num = 0)
    {
        *this = num;    // 构造函数
    }
    BigInteger operator = (long long num)   // 赋值运算符
    {
        s.clear();
        do
        {
            s.push_back (num % BASE);
            num /= BASE;
        }
        while (num > 0);
        return *this;
    }
    BigInteger operator = (const string& str)   // 赋值运算符
    {
        s.clear();
        int x, len = (str.length() - 1) / WIDTH + 1;
        for (int i = 0; i < len; i++)
        {
            int end = str.length() - i * WIDTH;
            int start = max (0, end - WIDTH);
            sscanf (str.substr (start, end - start).c_str(), "%d", &x);
            s.push_back (x);
        }
        return *this;
    }
    BigInteger operator + (const BigInteger& b) const
    {
        BigInteger c;
        c.s.clear();
        for (int i = 0, g = 0; ; i++)
        {
            if (g == 0 && i >= s.size() && i >= b.s.size() ) break;
            int x = g;
            if (i < s.size() ) x += s[i];
            if (i < b.s.size() ) x += b.s[i];
            c.s.push_back (x % BASE);
            g = x / BASE;
        }
        return c;
    }
};

ostream& operator << (ostream &out, const BigInteger& x)
{
    out << x.s.back();
    for (int i = x.s.size() - 2; i >= 0; i--)
    {
        char buf[20];
        sprintf (buf, "%08d", x.s[i]);
        for (int j = 0; j < strlen (buf); j++) out << buf[j];
    }
    return out;
}
istream& operator >> (istream &in, BigInteger& x)
{
    string s;
    if (! (in >> s) ) return in;
    x = s;
    return in;
}


BigInteger dp[255][4];
int main(){
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = 1;
    for(int i = 1;i<=250;i++){
        dp[i][0] = dp[i-1][3];
        dp[i][0] = dp[i][0]+dp[i-2][0]; // 2*n
        // dp[i][0] = dp[i][0]+dp[i-2][0]; // 两块横着的
        dp[i][0] = dp[i][0]+dp[i-1][0];
        // dp[i][0] = dp[i][0]+dp[i-1][1];
        dp[i][1] = dp[i-1][2];
        dp[i][2] = dp[i-1][1];
        dp[i][3] = dp[i-1][0]; 
    }
    while(~scanf("%d",&n)){
        cout<< dp[n][0]<<endl;
    }
}