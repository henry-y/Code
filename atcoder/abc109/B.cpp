#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f 
#define il inline 
#define in1(a) read(a)
#define in2(a,b) in1(a),in1(b)
#define in3(a,b,c) in2(a,b),in1(c)
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
string s;
int n;
string c;
map<string,int> mp;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(mp[s]==1)return puts("No"),0;
		int len=s.size();
		if(i==1)c=s[len-1];
		else if(s[0]!=c[0])return puts("No"),0;
		mp[s]=1;c[0]=s[len-1];
	}
	return puts("Yes"),0;
}
