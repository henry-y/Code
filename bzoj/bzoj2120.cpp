#include <bits/stdc++.h>

using namespace std;

inline void read( int &x ){
	x = 0 ; int f = 1 ; char c = getchar() ;
	while( c < '0' || c > '9' ) {
		if( c == '-' ) f = -1 ;
		c = getchar() ;
	}
	while( c >= '0' && c <= '9' ) {
		x = (x << 1) + (x << 3) + c - 48 ;
		c = getchar() ;
	}
	x *= f ;
}

#define N 1000100

int belong[N],block,num,pre[N],last[N];
int n,a[N],m,b[N];

void reset(int x){
	int l=(x-1)*block+1,r=min(n,block*x);
	for(int i=l;i<=r;i++)pre[i]=b[i];
	sort(pre+l,pre+r+1);
}

void build(){
	block=int(sqrt(n)+log(2*n)/log(2));
	num=n/block;
	if(n%block)num++;
	for(int i=1;i<=n;i++){
		b[i]=last[a[i]];
		belong[i]=(i-1)/block+1;
		last[a[i]]=i;
	}
	for(int i=1;i<=num;i++)reset(i);
}

int find(int i,int x){
	int lt=(i-1)*block+1,l=lt,r=min(i*block,n);
	while(l<=r){
		int mid=(l+r)>>1;
		if(pre[mid]<x)l=mid+1;
		else r=mid-1;
	}
	return l-lt;
}

int query(int l,int r){
	int ans=0;
	if(belong[l]==belong[r]){
		for(int i=l;i<=r;i++){
			if(b[i]<l)ans++;
		}
		return ans;
	}
	for(int i=l;i<=belong[l]*block;i++){
		if(b[i]<l)ans++;
	}
	for(int i=(belong[r]-1)*block+1;i<=r;i++){
		if(b[i]<l)ans++;
	}
	for(int i=belong[l]+1;i<belong[r];i++){
		ans+=find(i,l);
	}
	return ans;
}

void upd(int l,int x){
	for(int i=1;i<=n;i++)last[a[i]]=0;
	a[l]=x;
	for(int i=1;i<=n;i++){
		int lt=b[i];
		b[i]=last[a[i]];
		if(lt!=b[i])reset(belong[i]);
		last[a[i]]=i;
	}
}

int main(){
	read( n ) ; read( m ) ;
	for(int i=1;i<=n;i++)read( a[i] ) ;
	build();
	for(int i=1;i<=m;i++){
		int l,r;
		char ch[10];
		scanf("%s",ch);
		read( l ) ; read( r ) ;
		if(ch[0]=='Q')printf("%d\n",query(l,r));
		else upd(l,r);
	}
	return 0;
}
