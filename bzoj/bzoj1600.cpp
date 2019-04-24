#include <cstdio>
#include <algorithm>
using namespace std;
int n,f[100][2500];
//f[i,j]表示前i块木板长度和为j的方案数 
int main(){
	scanf("%d",&n);
	int s=(n+1)/2-1;
	f[0][0]=1;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=min(s,j);k++){
				f[i][j]+=f[i-1][j-k];
			}
		}
	}
	printf("%d\n",f[4][n]);
	return 0; 
} 
