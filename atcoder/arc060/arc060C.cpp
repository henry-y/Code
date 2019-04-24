#include <bits/stdc++.h>

using namespace std ; 

int n , ar , a[ 60 ] ;
long long f[ 60 ][ 60 ][ 2510 ] ;
//选到i，选了j个，sum为k 

int main() {
	scanf( "%d%d" , &n , &ar ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		scanf( "%d" , &a[ i ] ) ;
	}
	
	f[ 0 ][ 0 ][ 0 ] = 1 ;
	
	for( int i = 1 ; i <= n ; i ++ ) {
		for( int j = i ; j >= 0 ; j -- ) {
			for( int k = ar * n + 1 ; k >= 0 ; k -- ) {
				f[ i ][ j ][ k ] += f[ i - 1 ][ j ][ k ] ; 
				if( k >= a[ i ] && j ) f[ i ][ j ][ k ] += f[ i - 1 ][ j - 1 ][ k - a[ i ] ] ;
			}
		}
	}
	long long ans = 0 ;
	for( int i = 1 ; i <= n ; i ++ ) {
		ans += f[ n ][ i ][ ar * i ] ;
	}
	printf( "%lld\n" , ans );
} 
