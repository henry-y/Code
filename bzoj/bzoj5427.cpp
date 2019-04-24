#include <bits/stdc++.h>

using namespace std; 

inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	x*=f;
}

#define N 100010

int n,tot;
int f[N];

int main(){
	read(n);
	int m=0;
	for(int i=1;i<=n;i++){
		char ch[10];
		scanf("%s",ch);
		if(ch[0]=='N')tot++;
		else {
			int l=1,r=m,x;
			read(x);
			if(f[m]+tot<x)f[++m]=x;
			else {
				while(l<=r){
					int mid=(l+r)>>1;
					if(x>f[mid]+tot)l=mid+1;
					else r=mid-1;
				}
				f[l]=x-tot;
			}
		}
	}
	printf("%d\n",m+tot);
}
