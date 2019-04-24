#include <cstdio>
#include <cstring>
#include <algorithm>

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

int a[ N ] , n , m ; 

int main(){
	in2(n,m);
	for(int i = 1;i<=n;i++){
		in1(a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(m-a[i]>=0)m-=a[i];
		else return printf("%d",i-1),0;
	} 
	printf("%d\n",n-(m>0));
}

