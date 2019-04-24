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
const char nc[20]={'0','1','2','3','4','5','6','7', '8','9','A','B','C','D','E','F','G','H','I','J'};
string ans;
int main()
{
    int m,n,k,t;
    cin>>m;
    n=-2;
    ans="";
    if(m==0){
    	cout<<0;
    	return 0;
	}
    while(m!=0){
        k=m%n;
        t=m/n;
        if(k<0)
        {
            k-=n;
            t++;
        }
        m=t;
        ans.push_back(nc[k]);
    }
    for(int i=ans.length()-1;i>=0;i--)
        cout<<ans[i];
    return 0;
}
