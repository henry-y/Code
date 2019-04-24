#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define inf 1<<30
#define il inline 
#define in1(a) read(a)
#define in2(a,b) in1(a),in1(b)
#define in3(a,b,c) in2(a,b),in1(c)
#define in4(a,b,c,d) in2(a,b),in2(c,d)
il int max(int x,int y){return x>y?x:y;}
il int min(int x,int y){return x<y?x:y;}
il int abs(int x){return x>0?x:-x;}
il void swap(int &x,int &y){int t=x;x=y;y=t;}
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
bool cmp(int a,int b){return a>b;}
int a[N],n,m,k;
int main(){
	in2(n,m);
	for(int i=1;i<=m;i++){
		int x;in1(x);
		a[x]++;
	}
	int ans=0;
	for(int i=1;i<=100;i++){
		if(a[i])k++;
	}
	sort(a,a+100+1,cmp);
	for(int i=100;i;i--){
		int num=0;
		for(int j=0;j<=k;j++){
			num+=a[j]/i;
		}
		if(num>=n){ans=i;break;}
	}
	printf("%d\n",ans);
	return 0;
}
