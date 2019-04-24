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
int n,k,a[N];
char s[N];
int idx(char c){return c-'a'+1;}
int main(){
	in2(n,k);
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;i++)a[i]=idx(s[i]);
	sort(a+1,a+n+1);
	int last=a[1],num=1,ans=a[1];
	for(int i=2;i<=len;i++){
		if(num==k)break;
		if(a[i]-last>=2)num++,last=a[i],ans+=a[i];
	}
	if(num==k)printf("%d\n",ans);
	else printf("-1\n");
	return 0;
}
