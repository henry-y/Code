#include <bits/stdc++.h>

using namespace std ;

#define N 500010

int n , m , ans[ N ] ;
char ch[ N ][ 10 ] ;
int a[ N ] , b[ N ] ;
int now[ N ] ;

int main() {
	scanf( "%d%d" , &n , &m ) ;
	for( int i = 1 ; i <= m ; i ++ ) {
		scanf( "%s%d" , ch[ i ] , &a[ i ] ) ;
		if( ch[ i ][ 0 ] != '!' ) scanf( "%d" , &b[ i ] ) ;
	}
	for( int i = m ; i ; i -- ) {
		if( ch[ i ][ 0 ] == '!' ) {
			now[ a[ i ] ] ++ ;
		}else {
			int t1 = now[ a[ i ] ] , t2 = now[ b[ i ] ] ;
			if( ch[ i ][ 0 ] == '-' ) {
				ans[ a[ i ] ] -= t2 ;
				ans[ b[ i ] ] -= t1 ;
			}else {
				ans[ a[ i ] ] += t2 ;
				ans[ b[ i ] ] += t1 ;
			}
		}
	}
	for( int i = 1 ; i <= n ; i ++ ) printf( "%d " , ans[ i ] ) ;
	return 0 ;
} 
