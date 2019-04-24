#include <cstdio>
#include <algorithm>
using namespace std;
int n;
struct node {int w,s;}a[50010];
bool cmp(node a,node b){
	return a.w+a.s<b.w+b.s;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].w,&a[i].s);
	}
	sort(a+1,a+n+1,cmp);
	int sum=0,ans=-a[1].s;
	for(int i=2;i<=n;i++){
		sum+=a[i-1].w;
		ans=max(ans,sum-a[i].s);
	}
	printf("%d\n",ans);
} 
