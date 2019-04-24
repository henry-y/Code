#include <bits/stdc++.h>

using namespace std;

#define N 1000100

int n,m,a[N];
int block,num,l[N],r[N],belong[N],sum[N],add[N];

void build(){
	block=sqrt(n);
	num=n/block;
	if(n%block)num++;
	for(int i=1;i<=num;i++){
		l[i]=block*(i-1)+1;
		r[i]=block*i;
	}
	r[num]=n;
	for(int i=1;i<=n;i++){
		belong[i]=(i-1)/block+1;
		sum[i]=a[i];
	}
	for(int i=1;i<=num;i++){
		sort(sum+l[i],sum+r[i]+1);
	}
}

void copy(int x){
	for(int i=l[x];i<=r[x];i++){
		sum[i]=a[i];
	}
	sort(sum+l[x],sum+r[x]+1);
}

void upd(int L,int R,int c){
	if(belong[L]==belong[R]){
		for(int i=L;i<=R;i++){
			a[i]+=c;
		}
		copy(belong[L]);
		return;
	}
	for(int i=L;i<=r[belong[L]];i++)a[i]+=c;
	copy(belong[L]);
	for(int i=l[belong[R]];i<=R;i++)a[i]+=c;
	copy(belong[R]);
	for(int i=belong[L]+1;i<=belong[R]-1;i++)add[i]+=c;
}

int find(int L,int R,int c){
	int r1=R;
	while(L<=R){
		int mid=(L+R)>>1;
		if(sum[mid]<c)L=mid+1;
		else R=mid-1;
	}
	return r1-L+1;
}

int query(int L,int R,int c){
	int ans=0;
	if(belong[L]==belong[R]){
		for(int i=L;i<=R;i++){
			if(a[i]+add[belong[i]]>=c)ans++;
		}
		return ans;
	}
	for(int i=L;i<=r[belong[L]];i++){
		if(a[i]+add[belong[i]]>=c)ans++;
	}
	for(int i=l[belong[R]];i<=R;i++){
		if(a[i]+add[belong[i]]>=c)ans++;
	}
	for(int i=belong[L]+1;i<=belong[R]-1;i++){
		ans+=find(l[i],r[i],c-add[i]);
	}
	return ans;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build();
	for(int i=1;i<=m;i++){
		char ch[10];
		int L,R,c;
		scanf("%s%d%d%d",ch,&L,&R,&c);
		if(ch[0]=='M')upd(L,R,c);
		else printf("%d\n",query(L,R,c));
	}
	return 0;
}
