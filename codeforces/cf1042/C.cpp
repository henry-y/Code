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

#define N 200010

int n , a[ N ] , m ;
int vis[ N ] ;
vector < int > ans[ 3 ] ;

int main(){
	in1( n ) ;
	int cnt = 0 , min_ = -inf , id = 0 , cnt2 = 0 ;
	for(int i =1;i<=n;i++)in1(a[i]);
	sort(a+1,a+n+1);
	for( int i = 1 ; i <= n ; i ++ ) {
		if( a[ i ] == 0 ) ans[ 0 ].push_back( i ) , cnt2 = 1 ; 
		if( a[ i ] < 0 ){
			ans[ 1 ].push_back( i ) ; 
			cnt ++ ;
		}
		else ans[ 2 ].push_back( i ) ;
	}
	int len=ans[0].size();
	for( int i=0;i<len-1;i++){
		printf("1 %d %d\n",ans[0][i],ans[0][i+1]);
	}
	len=ans[1].size();
	if( cnt % 2 ) {
		int len1=ans[0].size();
		if( cnt2 ) printf("1 %d %d\n",ans[0][len1-1],ans[1][len-1]);
		else printf("2 %d\n",ans[1][len-1]);
		for(int i = 0 ; i < len - 2 ; i ++ ){
			printf("1 %d %d\n" , ans[1][i],ans[1][i+1]);
		}
		ans[2].push_back(ans[1][len-1]);
	}else {
		int len1 = ans[0].size();
		for(int i = 0 ; i < len - 1 ; i ++ ) {
			printf("1 %d %d\n",ans[1][i],ans[1][i+1]);
		}
		if(cnt2)printf("2 %d\n",ans[0][len1-1]);
		ans[2].push_back(ans[1][len-1]);
	}
	len=ans[2].size();
	for(int i=0;i<len-1;i++){
		printf("1 %d %d\n",ans[1][i],ans[1][i+1]);
	}
	return 0 ;
}
