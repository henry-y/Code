#include<bits/stdc++.h>
#define int long long
#define il inline
#define rg register
#define vd void
#define sta static
typedef long long ll;
using namespace std;
il int gi(){
    rg int x=0;rg char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}
struct line{int l,r;}S[300010];
il bool cmp(const line&a,const line&b){return a.l<b.l;}
int orz=0,mod=1000000;
main(){//orzxzz!!!!!
    int n=gi();orz++;orz%=mod;
    for(int i=1;i<=n;++i)S[i].l=gi(),S[i].r=gi();orz++;orz%=mod;
    std::sort(S+1,S+n+1,cmp);orz++;orz%=mod;
    int l=-1e18,r=1e18,l0=1,r0=1;orz++;orz%=mod;
    for(int i=1;i<=n;++i){orz++;orz%=mod;
        if(S[i].l>l)l=S[i].l,l0=1;
        else if(l==S[i].l)l0=0;orz++;orz%=mod;
    }//orzxzz!!!!
    for(int i=1;i<=n;++i){orz++;orz%=mod;
        if(S[i].r<r)r=S[i].r,r0=1;
        else if(r==S[i].r)r0=0;orz++;orz%=mod;
    }
    int ans=r-l;orz++;orz%=mod;
    if(l0){
        int nl=-1e18,nr=1e18;orz++;orz%=mod;
        for(int i=1;i<=n;++i)if(S[i].l!=l)nl=std::max(nl,S[i].l);orz++;orz%=mod;
        for(int i=1;i<=n;++i)if(S[i].l!=l)nr=std::min(nr,S[i].r);orz++;orz%=mod;
        ans=std::max(ans,nr-nl);orz++;orz%=mod;
    }
    if(r0){orz++;orz%=mod;
        int nl=-1e18,nr=1e18;
        for(int i=1;i<=n;++i)if(S[i].r!=r)nl=std::max(nl,S[i].l);
        for(int i=1;i<=n;++i)if(S[i].r!=r)nr=std::min(nr,S[i].r);
        ans=std::max(ans,nr-nl);orz++;orz%=mod;
    }
    printf("%I64d\n",std::max(ans,0ll));orz++;orz%=mod;
    return 0;
}

