#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int m=sqrt(n),ans=0;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=m;j++){
			if(i*i+j*j>n)break;
			for(int k=0;k<=m;k++){
				if(i*i+j*j+k*k>n)break;
				int l=n-i*i-j*j-k*k;
				int c=sqrt(l);
				if(c*c==l)ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
