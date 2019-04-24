#include <bits/stdc++.h>

using namespace std ;

#define ll long long
const ll mod = 1e9 + 7 ;
const int N = 1e6 + 10 ;

int n ;
ll f[ N ] ;

int main() {
	scanf( "%d" , &n ) ;
	f[ 1 ] = 1 ;
	for( int i = 2 ; i <= n ; i ++ ) 
		f[ i ] = ( f[ i - 1 ] * 2 + f[ i - 2 ] ) % mod ;
	printf( "%lld\n" , f[ n ] ) ;
}
