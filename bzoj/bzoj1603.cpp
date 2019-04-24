#include <cstdio>
#include <algorithm>
using namespace std;
struct node{int l,r,v;}a[2000];
int n;
bool cmp(node a,node b){return a.l<b.l;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].v);
	}
	sort(a+1,a+n,cmp);
	int f=1;
	for(int i=1;i<n;i++){
		if(!a[i].v)f=(f?0:1);
	}
	printf("%d\n",f);
	return 0;
} 
