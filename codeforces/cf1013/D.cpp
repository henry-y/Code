#include <cstdio>
#include <cstring>
#define ll long long
#define inf 1<<30
#define il inline 
#define in1(a) read(a)
#define in2(a,b) in1(a),in1(b)
#define in3(a,b,c) in2(a,b),in1(c)
#define in4(a,b,c,d) in2(a,b),in2(c,d)
il int max(int x,int y){return x>y?x:y;}
il int min(int x,int y){return x<y?x:y;}
il int abs(int x){return x>0?x:-x;}
il void swap(int &x,int &y){int t=x;x=y;y=t;}
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
#define N 500010
int n,f[N],m,q,vis[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void add(int x,int y){x=find(x),y=find(y);f[y]=x;}
int main(){
	in3(n,m,q);
	for(int i=1;i<=n+m;i++)f[i]=i;
	for(int i=1;i<=q;i++){
		int r,c;
		in2(r,c);
		c+=n;
		add(r,c);
	}
	int ans=0;
	for(int i=1;i<=n+m;i++)ans+=(f[i]==i);
	printf("%d\n",ans-1);
	return 0;
}
