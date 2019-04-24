#include <bits/stdc++.h>

using namespace std;

#define N 100010
#define ll long long

int n;
long long h[N];
int top=0,st[N];
long long v[N],ans[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&h[i],&v[i]);
		while(top&&h[st[top]]<=h[i])top--;
		if(top)ans[st[top]]+=v[i];
		st[++top]=i;
	}
	int top=0;
	for(int i=n;i;i--){
		while(top&&h[st[top]]<=h[i])top--;
		if(top)ans[st[top]]+=v[i];
		st[++top]=i;
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		sum=max(sum,ans[i]);
	}
	printf("%lld\n",sum);
	return 0;
} 
