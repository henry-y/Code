#include <bits/stdc++.h>
using namespace std;
char ch[200];
int n;
int f[200][200];
int idx(int x){
	if(x<10)return 1;
	if(x<100)return 2;
	return 3;
}
bool check(int l,int r,int len){
	for(int i=1;i<=len;i++){
		for(int j=l+i-1;j+len<=r;j+=len){
			if(ch[j]!=ch[j+len])return 0;
		}
	}
	return 1;
}
int main(){
	scanf("%s",ch+1);
	n=strlen(ch+1);
	for(int l=n;l;l--){
		f[l][l]=1;
		for(int r=l+1;r<=n;r++){
			f[l][r]=r-l+1;
			for(int k=l;k<=r;k++){
				f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]);
			}
			for(int k=1;k<=r-l+1;k++){
				if((r-l+1)%k==0&&check(l,r,k)){
					f[l][r]=min(f[l][r],f[l][l+k-1]+idx((r-l+1)/k)+2);
				}
			}
		}
	}
	printf("%d\n",f[1][n]);
	return 0;
}
