#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[500][500],n,m,q,ans[500][500];
struct node{int val,id;}c[500];
bool cmp(node a,node b){
	return a.val<b.val;
}
int C[500];
int main(){
	scanf("%d%d%d",&n,&m,&q);
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i].val);
		c[i].id=i;
		f[i][i]=0;
	}
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++){
		C[c[i].id]=i;
	}
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		f[C[x]][C[y]]=f[C[y]][C[x]]=min(f[C[x]][C[y]],z);
	}
	memset(ans,0x3f,sizeof(ans));
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){ 
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				ans[i][j]=min(ans[i][j],f[i][j]+max(c[k].val,max(c[i].val,c[j].val)));
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",ans[C[x]][C[y]]);
	}
	return 0;
}
