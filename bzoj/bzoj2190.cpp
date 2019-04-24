#include <cstdio>
#include <cstring>
using namespace std;
#define N 40040
int phi[N];
int main(){
	int n;
	scanf("%d",&n);
	if(n==1)return puts("0"),0;
	phi[1]=1;
	for(int i=2;i<=n;i++){
		if(!phi[i]){
			for(int j=i;j<=n;j+=i){
				if(!phi[j])phi[j]=j;
				phi[j]=phi[j]/i*(i-1);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n-1;i++){
		ans+=phi[i];
	}
	printf("%d\n",ans*2+1);
	return 0;
}
