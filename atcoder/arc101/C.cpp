#include <bits/stdc++.h>
#define ll long long
#define inf 1<<30
#define il inline 
#define in1(a) read(a)
#define in2(a,b) in1(a),in1(b)
#define in3(a,b,c) in2(a,b),in1(c)
#define in4(a,b,c,d) in2(a,b),in2(c,d)
il void readl(ll &x){
    x=0;ll f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    x*=f;
}
il void read(int &x){
    x=0;int f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    x*=f;
}
using namespace std;
/*===================Header Template=====================*/
#define N 500010
int n,a[N]; 
int main(){
	int k;
	in2(n,k);
	for(int i=1;i<=n;i++)in1(a[i]);
	int l=1,r=k,ans=inf;
	while(r<=n){
		int sum=0;
		if(a[r]<=0){
			sum=abs(0-a[l]);
		}else {
			if(a[l]>=0){
				sum=a[r];
			}else {
				sum=min(a[r],0-a[l]);
				sum+=a[r]-a[l];
			}
		}
		ans=min(ans,sum);
		l++;r++;
	}
	printf("%d\n",ans);
}
