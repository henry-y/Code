#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define ll char
#define inf 1<<30
#define il inline 
#define in1(a) read(a)
#define in2(a,b) in1(a),in1(b)
#define in3(a,b,c) in2(a,b),in1(c)D
#define in4(a,b,c,d) in2(a,b),in2(c,d)
il void readl(ll &x){
    x=0;ll f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    x*=f;
}
il void read(int &x){
    x=0;int f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    x*=f;
}
using namespace std;
/*===================Header Template=====================*/
#define N 100010
#define mod 1000000007
ll dp[100010][4];
int main(){
	string s;
	cin>>s;
	int n=s.size();
	for(int i=n;i>=0;i--){
		for(int j=3;j>=0;j--){
			if(i==n){
				dp[i][j]=(j==3?1:0);
			}else {
				dp[i][j]=dp[i+1][j]*(s[i]=='?'?3:1);
				if(j<3&&(s[i]=='?'||"ABC"[j]==s[i])){
					dp[i][j]+=dp[i+1][j+1];
				}
				dp[i][j]%=mod;
			}
		}
	}
	printf("%lld\n",dp[0][0]);
	return 0;
}
