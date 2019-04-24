#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
ll n,m,s1=0,s2=0;
struct node{ll x,y,c;}a[100100];
inline bool cmp(node a,node b){
	return a.c>b.c;
}
int main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].x,&a[i].y);
		s1+=a[i].x;
		s2+=a[i].y;
		a[i].c=a[i].x-a[i].y;
	}
	if(s1<=m)return puts("0"),0;
	if(s2>m)return puts("-1"),0;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		s1=s1-a[i].c;
		if(s1<=m)return printf("%d\n",i),0;
	}
}
