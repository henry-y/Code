#include <cstdio>
using namespace std;
int stack[1000000],h[1000000],n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&h[i],&h[i]);
	}int top=0,ans=n;
	for(int i=1;i<=n;i++){
		while(stack[top]>h[i])top--;
		if(stack[top]==h[i])ans--;
		stack[++top]=h[i];
	} 
	printf("%d\n",ans);
	return 0;
} 
