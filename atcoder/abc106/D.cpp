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
#define lowbit(x) x&-x
int n,m,q,ans[N];
struct node {int l,r,id;}a[N],ask[N];
bool cmp(node a,node b){
	return a.r<b.r; 
}
int c[N];
void add(int x,int y){
	for(int i=x;i<=n;i+=lowbit(i)){
		c[i]+=y;
	}
}
int Q(int x){
	int ans=0;
	for(int i=x;i;i-=lowbit(i)){
		ans+=c[i];
	}
	return ans;
}
int main(){
	in3(n,m,q);
	for(int i=1;i<=m;i++){
		in2(a[i].l,a[i].r);
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=q;i++){
		in2(ask[i].l,ask[i].r);
		ask[i].id=i;
	}
	sort(ask+1,ask+q+1,cmp);
	int j=1; 
	for(int i=1;i<=q;i++){
		while(j<=m&&a[j].r<=ask[i].r){
			add(a[j].l,1);j++;
		}
		ans[ask[i].id]=Q(ask[i].r)-Q(ask[i].l-1);
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}

