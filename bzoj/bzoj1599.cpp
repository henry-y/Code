#include <cstdio>
#include <algorithm>
using namespace std;
int s1,s2,s3,vis[10010];
int main(){ 
	scanf("%d%d%d",&s1,&s2,&s3);
	for(int i=1;i<=s1;i++){
		for(int j=1;j<=s2;j++){
			for(int k=1;k<=s3;k++){
				vis[i+j+k]++;
			}
		}
	}
	int ans=0,t1=0;
	for(int i=10000;i>=0;i--){
		if(vis[i]>=t1){
			t1=vis[i];
			ans=i;
		}
	}
	printf("%d\n",ans);
	return 0; 
}
