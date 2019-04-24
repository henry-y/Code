#include <bits/stdc++.h>
using namespace std;
int n,m,t;
struct node {
	int l,r,val;
}a[10000];
int f[1000000];
bool cmp(node a,node b){
	return a.r<b.r;
}
int main(){
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].val);
	}
	int ans=0;
	sort(a+1,a+m+1,cmp);
	a[0].r=-1000000;
	for(int i=1;i<=m;i++){
		for(int j=0;j<i;j++){
			if(a[i].l-a[j].r>=t)f[i]=max(f[i],f[j]+a[i].val);
		}
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
} 
