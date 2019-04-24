#include <cstdio>
using namespace std;
int n,m,a[100000],sum[500000],b[100000];
int val[500000],ch[500000][2],siz=0;
void insert(int len){
	int u=0,t=0;
	for(int i=1;i<=len;i++){
		int c=a[i];
		if(!ch[u][c])ch[u][c]=++siz;
		u=ch[u][c];
		b[++t]=u; 
	}
	val[u]++;
	for(int i=1;i<t;i++)sum[b[i]]++;
}
int find(int len){
	int u=0,ans=0;
	for(int i=1;i<=len;i++){
		int c=a[i];
		if(!ch[u][c])return ans;
		u=ch[u][c]; 
		ans+=val[u];
	}
	return ans+sum[u];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		for(int i=1;i<=x;i++){
			scanf("%d",&a[i]);
		}
		insert(x);
	}
	for(int i=1;i<=m;i++){
		int x;
		scanf("%d",&x);
		for(int i=1;i<=x;i++){
			scanf("%d",&a[i]);
		}
		printf("%d\n",find(x));
	}
	return 0;
} 
