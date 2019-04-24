#include <cstdio>
#include <algorithm>
using namespace std;
long long m;
int ans=0;
int main(){
	scanf("%lld",&m);
	while(m){
		m/=2;
		ans++;
	}
	printf("%d\n",ans);
} 
