#include <bits/stdc++.h>

using namespace std ;

inline int lowbit( int x ) {
	return x & -x ;
} 

#define N 700010

int n ;
int c[ N ] ;

void add( int x , int val ) {
	for( int i = x ; i <= n ; i += lowbit( i ) ) 
		c[ i ] += val ;
}

int query( int x ) {
	int ans = 0 ;
	for( int i = x ; i ; i -= lowbit( i ) ) ans += c[ i ] ;
	return ans ;
}

int find( int x ) {
	int l = 1 , len = n ;
	while( len ) {
		int mid = l +( len >> 1 ) ;
		if( query( mid ) < x ) {
			l = mid + 1 ;
			len = len - ( len >> 1 | 1 ) ;
		} else len = len >> 1 ;
	}
	return l ;
}

int main() {
	int now = 0 ;
	scanf( "%d" , &n ) ;
	for( int i = 1 ; i <= n ; i ++ ) add( i , 1 ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		int t ;
		scanf( "%d" , &t ) ;
		t = t % ( n - i + 1 ) ;
		now = ( now + t ) % ( n - i + 1 ) ;
		t = find( now + 1 ) ;
		printf( "%d\n" , t ) ;
		add( t , -1 ) ;
	}
	return 0 ;
}
