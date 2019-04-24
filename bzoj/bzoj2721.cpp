#include <cstdio>
using namespace std;
#define mod 1000000007
#define N 1000010
#define ll long long
int p[N],v[N];
ll ans=1,cnt[N];
int n,tot=0;
void eular(){
	v[1]=1;
	for(int i=2;i<=n;i++){
		if(!v[i])v[i]=i,p[++tot]=i;
		for(int j=1;j<=tot;j++){
			if(p[j]>v[i]||p[j]*i>n)break;
			v[i*p[j]]=p[j];
		}
	}
}
int main(){
	scanf("%d",&n);
	eular();
	for(int i=1;i<=tot;i++){
		cnt[i]=0;
		for(ll j=p[i];j<=n;j*=p[i])cnt[i]+=n/j;
		cnt[i]%=mod;
	}
	for(int i=1;i<=tot;i++)ans=(ans*(cnt[i]*2+1))%mod;
	printf("%lld\n",ans);
	return 0;
}
