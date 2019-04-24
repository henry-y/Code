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
#define N 100010
int d,g,c[N],p[N],ans=inf,vis[N];
void find(){
	int sum=0,ans1=0;
	for(int i=1;i<=d;i++){
		if(vis[i]){
			ans1+=c[i];
			sum+=p[i]+c[i]*100*i;
		}
	}
	if(sum>=g){
		ans=min(ans1,ans);return;
	}
	for(int i=d;i;i--){
		if(vis[i])continue;
		int t=c[i];
		while(t>1){
			t--;
			ans1++;
			sum+=100*i;
			if(sum>=g){
				ans=min(ans1,ans);
				return;
			}
		}
	}
}
void dfs(int x){
	if(x==d+1){find();return;}
	vis[x]=1;dfs(x+1);
	vis[x]=0;dfs(x+1);
}
int main(){
	in2(d,g);
	for(int i=1;i<=d;i++)in2(c[i],p[i]);
	dfs(1);
	printf("%d\n",ans);
}
