#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node {int val,x;}a[2000];
bool cmp(node a,node b){
	return a.x<b.x;
}
int f[2000][2000]; 
//f[i,j]最后从j点跳到i点 
int main(){
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].val);
	}
	sort(a+1,a+n+1,cmp);
	for(int j=1;j<=n;j++){
		int k=j-1,val=f[j][0]+a[j].val;
		for(int i=j+1;i<=n;i++){
			while(k&&a[i].x-a[j].x>=a[j].x-a[k].x)
				val=max(val,a[j].val+f[j][k]),k--;
			f[i][j]=max(f[i][j],val);
			ans=max(ans,val+a[i].val);
		}
	} 
	for(int j=n;j;j--){
		int k=j+1,val=f[j][n+1]+a[j].val;
		for(int i=j-1;i;i--){
			while(k<=n&&a[j].x-a[i].x>=a[k].x-a[j].x)
				val=max(val,f[j][k]+a[j].val),k++;
			f[i][j]=max(f[i][j],val);
			ans=max(ans,val+a[i].val);
		}
	}
	printf("%d\n",ans);
	return 0;
} 
