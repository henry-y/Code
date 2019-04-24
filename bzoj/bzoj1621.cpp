#include <cstdio>
using namespace std;
int n,k,ans=1;
void find(int x){
	if(x<=k)return;
	if((x-k)/2==(x-k)/2.0)
		ans++,find((x-k)/2),find((x-k)/2+k);
}
int main(){
	scanf("%d%d",&n,&k);
	find(n);
	printf("%d\n",ans);
}
