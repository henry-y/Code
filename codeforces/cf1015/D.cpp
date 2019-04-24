#include <cstdio>
#include <cmath>
using namespace std;
#define ll long long
int n,k;
ll m;
int main(){
	scanf("%d%d%lld",&n,&k,&m);
	ll t=ceil((double)(m/(double)k));
	if(t>n-1||m<k)return puts("NO"),0;
	ll now=1;
	puts("YES");
	for(int i=1;i<=k;i++){
		t=ceil((double)(m/(double)(k-i+1)));
		m-=t;
		if(now-t>=1){
			now-=t;
			printf("%lld ",now);
		}else {
			if(now+t<=n){
				now+=t;
				printf("%lld ",now);
			}
		}
	}
}
