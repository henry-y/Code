#include <bits/stdc++.h>
using namespace std;
char s[100];
int f[100][100];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	memset(f,127,sizeof(f));
	for(int i=1;i<=n;i++)f[i][i]=1;
	for(int len=2;len<=n;len++){
		for(int l=1;l<=n;l++){
			int r=l+len-1;
			if(r>n)break;
			if(s[l]==s[r])f[l][r]=min(f[l+1][r],f[l][r-1]);
			else 
				for(int k=l;k<=r;k++){
					f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]);
				}
		}
	}
	printf("%d\n",f[1][n]);
} 
