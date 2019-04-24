#include <cstdio>
#include <cstring>
#include <algorithm>
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
#define N 200010
int n,c[N],a[N];
int st[N],flag=0,top=0,f1=0;
int vis[N];
int dfs(int x,int d){
	st[x]++;vis[x]=d;
	if(st[x]==2){
		return x;
	}
	if(!st[a[x]]||vis[a[x]]==d)return dfs(a[x],d);
	return 0;
}
int sum=0;
void dfs1(int x){
	if(st[x]==2)return;
	sum=min(sum,c[x]);
	dfs1(a[x]);
}
int main(){
	in1(n);
	for(int i=1;i<=n;i++)in1(c[i]);
	for(int i=1;i<=n;i++)in1(a[i]);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!st[i]){
			int t=dfs(i,i);
			if(a[i]==i)ans+=c[i];
			else if(t)sum=c[t],dfs1(a[t]),ans+=sum;
		}
	}
	printf("%d\n",ans);
	return 0;
}
