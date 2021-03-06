#include <bits/stdc++.h>

#define ll long long
#define inf 0x3f3f3f3f 
#define il inline 
#define in1(a) read(a)
#define in2(a,b) in1(a),in1(b)
#define in3(a,b,c) in2(a,b),in1(c)
#define in4(a,b,c,d) in2(a,b),in2(c,d)

inline void read( int &x ){
    x = 0 ; int f = 1 ; char c = getchar() ;
    while( c < '0' || c > '9' ) {
        if( c == '-' ) f = -1 ;
        c = getchar() ;
    }
    while( c >= '0' && c <= '9' ) {
        x = (x << 1) + (x << 3) + c - 48 ;
        c = getchar() ;
    }
    x *= f ;
}

inline void readl( ll &x ){
    x = 0 ; ll f = 1 ; char c = getchar() ;
    while( c < '0' || c > '9' ) {
        if( c == '-' ) f = -1 ;
        c = getchar() ;
    }
    while( c >= '0' && c <= '9' ) {
        x = (x << 1) + (x << 3) + c - 48 ;
        c = getchar() ;
    }
    x *= f ;
}

using namespace std ;

#define N 100010

int n , a[ N ] , m ;
priority_queue<int,vector<int>,greater<int> > q ;
int main(){
	in2(n,m);
	int mx=0;
	for(int i=1;i<=n;i++)in1(a[i]),mx=max(a[i],mx),q.push(a[i]);
	int ans1=mx,m1=m;
	while(m--){
		int t=q.top();
		q.pop();
		q.push(t+1);
		ans1=max(ans1,t+1);
	}
	printf("%d %d\n",ans1,mx+m1);
	return 0 ;
}
