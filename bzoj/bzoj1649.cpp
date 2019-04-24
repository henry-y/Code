#include <bits/stdc++.h>

using namespace std;

#define N 10010

int f[1010][1010];
//长度为i时成本为j
int l,n,b;
struct node {
	int x,w,f,c;
	//x起点，w长度，f权值，c成本 
}a[N];

bool cmp(node a,node b){
	return a.x<b.x;
}

int main(){
	scanf("%d%d%d",&l,&n,&b);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&a[i].x,&a[i].w,&a[i].f,&a[i].c);
	}
	sort(a+1,a+n+1,cmp);
	memset(f,-1,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=b;j>=a[i].c;j--){
			if(f[a[i].x][j-a[i].c]!=-1){
				f[a[i].x+a[i].w][j]=max(f[a[i].x+a[i].w][j],f[a[i].x][j-a[i].c]+a[i].f);
			}
		}
	}
	int ans=-1;
	for(int i=0;i<=b;i++){
		ans=max(ans,f[l][i]);
	}
	printf("%d\n",ans);
}
