#include <bits/stdc++.h>
#define ll long long
#define inf 1<<30
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
int nxt[100];
int main(){
	string s;
	int n,t;
	in2(n,t);
	cin>>s;
	int k=0;
	int len=s.size();
	for(int i=1;i<len;i++){
        while(k&&s[i]!=s[k])k=nxt[k];
        if(s[i]==s[k])nxt[i+1]=++k;
    }
    cout<<s;
    for(int i=2;i<=t;i++){
    	for(int j=nxt[len];j<len;j++)
    		putchar(s[j]);
	}
	return 0;
}

