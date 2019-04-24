#include <bits/stdc++.h>

using namespace std;

#define N 80010

int n , h[ N ] , st[ N ] , top ;
long long ans = 0 ;

int main(){
    scanf( "%d" , &n ) ;
    for( int i = 1 ; i <= n ;i ++ ){
        scanf( "%d" , &h[ i ] ) ;
    }
    for( int i = n ; i ; i -- ){
        while( top && h[ st[ top ] ] < h[ i ] ) top -- ;
        if ( top ) ans += st[ top ] - i - 1 ;
        else ans += n - i ;
        st[ ++ top ] = i ;
    }
    printf( "%lld\n" , ans ) ;
    return 0;
}
