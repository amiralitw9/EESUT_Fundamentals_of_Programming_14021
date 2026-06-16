#include <iostream>
using namespace std ;
int main() {
    long int a,k ;
    long int n,Sn ;
    cin>>k>>n>>a ;
    Sn=(k*(a)*(a+1)/2) ;
    if (Sn>n) {
        cout<<Sn-n ;
    }
    else {
        cout<<0 ;
    }
    return 0;
}
