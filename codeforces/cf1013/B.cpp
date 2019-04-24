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
#define N 100010
int n,x,a[N],vis[N],vis2[N];
bool q[10];
int main(){
	in2(n,x);
	for(int i=1;i<=n;i++){
		in1(a[i]);
		if(vis[a[i]]){printf("0\n");return 0;}
		vis[a[i]]=1;
	}
	for(int i=1;i<=n;i++){
		if((a[i]&x)!=a[i]&&vis[a[i]&x]){q[1]=1;}
		if((a[i]&x)!=a[i]&&vis2[a[i]&x]){q[2]=1;}
		vis2[a[i]&x]=1;
	}
	if(q[1])printf("1\n");
	else if(q[2])printf("2\n");
	else printf("-1\n");
	return 0;
}
