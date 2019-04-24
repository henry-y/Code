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
#define N 100010
int t,n;
char s[N]; 
int main(){
	in1(t);
	while(t--){
		in1(n);
		scanf("%s",s+1);
		int i=n/2,j=n/2+1,pd=0;
		while(i&&j<=n){
			if(!abs(s[i]-s[j])||abs(s[i]-s[j])==2){i--;j++;continue;}
			pd=1;break;
		}
		if(pd)puts("NO");
		else puts("YES");
	}
	return 0;
}

