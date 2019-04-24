#include <bits/stdc++.h>

using namespace std ; 

int n ; 
int f[ 5010 ] , a[ 5010 ] ; 

int main() {
    scanf( "%d" , &n ) ;
    for( int i = 1 ; i <= n ; i ++ ) {
        scanf( "%d" , &a[i] ) ; 
    } 
    int ans = 0 ;
    for( int i = 1 ; i <= n ; i ++ ) {
        f[ i ] = 1 ; 
        for( int j = 1 ; j < i ; j ++ ) {
            if( a[ i ] > a[ j ] ) f[ i ] = max( f[ i ] , f[ j ] + 1 ) ; 
        }
        ans = max ( ans , f[ i ] ) ; 
    }
    printf( "%d" , ans ) ;
    return 0 ;
}
