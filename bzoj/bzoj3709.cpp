#include <bits/stdc++.h>

using namespace std;

#define N 100010

struct node {
	int d,a,id;
}a[N],b[N],c[N];

int n;
long long sum;
int cnt1,cnt2;

bool cmp1(node a,node b){
	return a.d<b.d;
}
bool cmp2(node a,node b){
	return a.a>b.a;
}

int main(){
	scanf("%d%lld",&n,&sum);
	for(int i=1;i<=n;i++){
		node a;
		scanf("%d%d",&a.d,&a.a);
		a.id=i;
		if(a.d<=a.a)b[++cnt1]=a;
		else c[++cnt2]=a;
	}
	sort(b+1,b+cnt1+1,cmp1);
	sort(c+1,c+cnt2+1,cmp2);
	for(int i=1;i<=cnt1;i++){
		sum-=b[i].d;
		if(sum<=0)return puts("NIE");
		sum+=b[i].a;
	}
	for(int i=1;i<=cnt2;i++){
		sum-=c[i].d;
		if(sum<=0)return puts("NIE");
		sum+=c[i].a;
	}
	puts("TAK");
	for(int i=1;i<=cnt1;i++){
		printf("%d ",b[i].id);
	}
	for(int i=1;i<=cnt2;i++){
		printf("%d ",c[i].id);
	}
	return 0;
}
