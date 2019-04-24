#include <cstdio>
#include <cstring>
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
#define N 100010
int n,m,a[N],b[N];
bool pd(double a,double b){
	if(abs(a-b)<=0.000001)return 1;
	return 0;
}
double check(int x,double f){
	if(x==1||pd(-1,f))return -1;
	return f+f*1.0/(x-1);
}
int main(){
	in2(n,m);
	for(int i=1;i<=n;i++)
		in1(a[i]);
	for(int i=1;i<=n;i++)
		in1(b[i]);
	double t=m;
	t=check(b[1],t);
	t=check(a[n],t);
	for(int i=n-1;i;i--){
		t=check(b[i+1],t);
		t=check(a[i],t);
	}
	if(pd(-1,t))printf("-1\n");
	else printf("%.10lf\n",t-m);
	return 0;
}
