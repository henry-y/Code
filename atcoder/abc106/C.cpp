#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
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
#define N 105
char s[N];
int a[N];
long long k;
int main(){
	int i,len;
	scanf("%s",s+1);
	len=strlen(s+1);
	for(i=1;i<=len;i++) a[i]=s[i]-'0';
	readl(k);
	i=0;
	while(k>0){
		i++;
		if(a[i]==1) k--;
		else k-=pow(a[i],5*1e15-1);
	}
	printf("%d",a[i]);
	return 0;
}
