#include <cstdio>
using namespace std;
int main(){
	int n,ans=0;
	scanf("%d",&n);
	ans+=n/100;
	n%=100;
	ans+=n/20;
	n%=20;
	ans+=n/10;
	n%=10;
	ans+=n/5;
	n%=5;
	ans+=n/1;
	printf("%d\n",ans);
	return 0;
}
