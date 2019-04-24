#include <bits/stdc++.h>

using namespace std ;

#define ll long long

map<pair<int,int>,int>mp;

int h , w , n , cnt[ 10 ] ;

int main(){
	scanf( "%d%d%d" , &h , &w , &n ) ;
	while( n -- ) {
		int x , y ;
		scanf( "%d%d" , &x , &y ) ;
		for( int i = max( 1 , x - 2 ) ; i <= min( h - 2 , x ) ; i ++ ) {
			for( int j = max( 1 , y - 2 ) ; j <= min( w - 2 , y ) ; j ++ ) {
				mp[ pair<int,int>(i,j) ] ++ ;
			}
		}
	}
	map< pair<int,int> , int > :: iterator iter ;
	iter = mp.begin() ;
	while( iter != mp.end() ) {
		cnt[ iter -> second ] ++ ;
		iter ++ ; 
		n ++ ;
	}
	ll ans = 1ll * ( h - 2 ) * ( w - 2 ) ;
	printf( "%lld\n" , ans - n - 1 ) ;
	for( int i = 1 ; i <= 9 ; i ++ ) {
		printf( "%d\n" , cnt[ i ] ) ;
	}
	return 0 ;
}
