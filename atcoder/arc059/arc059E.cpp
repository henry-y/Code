#include <bits/stdc++.h>

using namespace std ; 

#define N 500
#define ll long long
const ll mod = 1e9+7 ; 

ll n , m ;
ll a[ N ] , b[ N ] ;
ll sum[ N ][ N ] , l[ N ][ N ] ;
ll f[ N ][ N ] ;
//f[ i ][ j ]ǰi����һ������j���ǹ� 
//l[ i ][ j ]����i��j�η�
//sum[ i ][ j ]��lά��ǰ׺�� 

int main() {
	scanf( "%lld%lld" , &n ,&m ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		scanf( "%lld" , &a[ i ] ) ;
	}
	for( int i = 1 ; i <= n ; i ++ ) {
		scanf( "%lld" , &b[ i ] ) ;
	}
	for( int i = 1 ; i < N ; i ++ ) {
		l[ i ][ 0 ] = 1 ;
		for( int j = 1 ; j < N ; j ++ ) {
			l[ i ][ j ] = l[ i ][ j - 1 ] * i  ;
			l[ i ][ j ] %= mod ;
		}
	}
	for( int i = 1 ; i < N ; i ++ ){
		for( int j = 0 ; j < N ; j ++ ) {
			sum[ i ][ j ] += sum[ i - 1 ][ j ] + l[ i ][ j ] ;
			sum[ i ][ j ] %= mod ;
		}
	} 
	f[ 0 ][ 0 ] = 1 ;
	for( int i = 1 ; i <= n ; i ++ ) {
		for( int j = 0 ; j <= m ; j ++ ) {
			for( int k = 0 ; k <= j ; k ++ ) {
				f[ i ][ j ] = ( f[ i ][ j ] % mod + ( 1ll * f[ i - 1 ][ j - k ] *( ( sum[ b[ i ] ][ k ] - sum[ a[ i ] - 1 ][ k ] ) % mod )  + mod ) % mod + mod ) % mod  ;
			}
		} 
	} 
	printf( "%lld\n" , f[ n ][ m ] ) ;
	return 0 ;
} 
