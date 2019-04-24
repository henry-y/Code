#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,ans=0,f[100005];
char s1[100],s2[100];
int main(){
	scanf("%d",&n);
	scanf("%s",s1);
	scanf("%s",s2);
	for(int i=0;i<n;i++){
		if(s2[i]!=s1[i]){
			int j;
			for(j=i+1;j<n;j++)
				if(s1[j]==s2[i])break;
			for(int k=j-i;k;k--){
				swap(s1[i+k-1],s1[i+k]);
				f[++ans]=i+k;
			}
		}
	}
	if(strcmp(s1,s2)!=0)return puts("-1"),0;
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++)
		printf("%d ",f[i]);
	return 0;
}

