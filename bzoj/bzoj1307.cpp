#include <bits/stdc++.h>
 
using namespace std ;
 
const int N = 1e6 + 10 ;
 
int q[ N ], a[ N ] , vis[ N ] ;
int n ;
 
int main() {
    scanf( "%d" , &n ) ;
    int l = 0 , r = 1 , ql = 1 , ans = 0 ;
    for( int i = 1 ; i <= n ; i ++ ) {
        scanf( "%d" , &a[ i ] ) ;
        while( l < r && a[ q[ r ] ] <= a[ i ] ) r -- ;
        q[ r ++ ] = i ;
        if( !vis[ a[ i ] ] ) {
            vis[ a[ i ] ] ++ ;
        }else {
            while( a[ i ] != a[ ql ] && ql < i ) vis[ a[ ql ] ] -- , ql ++ ;
            ql ++ ;
            while( l < r && q[ l ] < ql ) l ++ ;
        }
        if( i - ql + 1 == a[ q[ l ] ] ) ans = max( ans , a[ q[ l ] ] ) ;
    }
    printf( "%d\n" , ans ) ;
    return 0 ;
} 
