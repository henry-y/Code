#include <bits/stdc++.h>

using namespace std ;
 
#define N 500010
#define lowbit( x ) ( x & ( -x ) )
 
int n , top , tim ;
int cnt , head[ N ] , c[ N * 2 ];
int st[ N ] ;
int in[ N ] , out[ N ] , fa[ N ] ;
struct node {
	int to , nxt ;
}e[ N ];

void ins( int u , int v ) {
	e[ ++ cnt ].to = v ;
	e[ cnt ].nxt = head[ u ] ;
	head[ u ] = cnt ;
}

void add( int x , int val ) {
	for( int i = x ; i <= n + n ; i += lowbit( i ) ) 
		c[ i ] += val ;
}

int query( int x ) {
	int ans = -1 ;
	for( int i = x ; i ; i -= lowbit( i ) ) 
		ans += c[ i ] ;
	return ans ;
} 

void dfs() {
	st[ ++ top ] = 1 ;
	while( top ) {
		int now = st[ top ] , f = fa[ top -- ] ;
		if( ! in[ now ] ) {
			in[ now ] = ++ tim ;
			st[ ++ top ] = now ;
			for( int i = head[ now ] ; i ; i = e[ i ].nxt ) {
				if( e[ i ].to == f ) continue ;
				st[ ++ top ] = e[ i ].to ;
				fa[ top ] = now ; 
			}
		}else out[ now ] = ++ tim ;
	}
}

int main() {
	scanf( "%d" , &n ) ;
	for( int i = 1 ; i < n ; i ++ ) {
		int a, b ;
		scanf( "%d%d" , &a , &b ) ;
		ins( a ,b ) ; ins( b , a ) ; 
	}
	dfs() ; 
	for( int i = 1 ; i <= n ; i ++ ) {
		add( in[ i ] , 1 ) ; add( out[ i ] , -1 ) ;
	}
	int m ;
	scanf( "%d" , &m ) ;
	m = m + n - 1 ;
	while( m -- ) {
		int a , b ;
		char ch[ 10 ] ;
		scanf( "%s" , ch ) ;
		if( ch[ 0 ] == 'A' ) {
			scanf( "%d%d" , &a ,&b ) ;
			add( in[ b ] , -1 ) ; add( out[ b ] , 1 ) ;
		}
		else scanf( "%d" , &a ) , printf( "%d\n" , query( in[ a ] ) ) ;
	}
	return 0 ;
}
