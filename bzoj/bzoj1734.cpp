#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define inf 1<<30
#define il inline 
#define in1(a) readl(a)
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
ll n,c,a[N]; 
bool check(ll x){
    ll k=1,last=a[1];
    for(ll i=2;i<=n;i++){
        if(a[i]-x>=last)last=a[i],k++;
    }
    if(k>=c)return 1;
    return 0;
}
int main(){
    in2(n,c);
    for(ll i=1;i<=n;i++)in1(a[i]);
    sort(a+1,a+n+1);
    ll l=1,r=a[n],ans;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid))ans=mid,l=mid+1;
        else r=mid-1; 
    }
    printf("%lld\n",ans);
    return 0;
}
