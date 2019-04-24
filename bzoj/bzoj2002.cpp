#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define ll long long
#define N 200010
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	x*=f;
}
using namespace std;
int n,a[N],m;
int block,num,to[N],d[N],l[N],r[N],belong[N];
void build(){
	block=sqrt(n),num=n/block;
	if(n%block)num++;
	for(int i=1;i<=num;i++){
		l[i]=(i-1)*(block)+1;
		r[i]=block*i;
	} 
	r[num]=n;
	for(int i=1;i<=n;i++){
		belong[i]=(i-1)/block+1;
	}
	for(int i=n;i;i--){
		if(belong[i+a[i]]!=belong[i]){
			d[i]=1;
			to[i]=i+a[i];
		}else {
			d[i]=d[i+a[i]]+1;
			to[i]=to[i+a[i]];
		}
	}
}
void upd(int x,int c){
	a[x]=c;
	for(int i=r[belong[x]];i>=l[belong[x]];i--){
		if(belong[i+a[i]]!=belong[i]){
			to[i]=i+a[i];
			d[i]=1;
		}else {
			d[i]=d[i+a[i]]+1;
			to[i]=to[i+a[i]];
		}
	}
}
int query(int x){
	int ans=0;
	while(x<=n){
		ans+=d[x];
		x=to[x];
	}
	return ans;
}
int main(){
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	build();
	read(m);
	while(m--){
		int x,y;
		read(x);read(y);
		if(x==1)printf("%d\n",query(y+1));
		else {
			int k;read(k);
			upd(y+1,k);
		}
	}
}
