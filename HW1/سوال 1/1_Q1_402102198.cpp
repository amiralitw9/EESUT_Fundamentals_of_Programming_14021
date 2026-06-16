#include <iostream>
using namespace std ;

int main() {
    long int a, b, c,f,g;
    cin >> a >> b >> c;
    if ((a/c)*c<a) {
         f = (a/c)+1 ;
    }
    else {
         f = (a/c);
    }
    if ((b/c)*c<b) {
         g = (b/c)+1 ;
    }
    else {
         g = (b/c);
    }
    cout<<(f*g);
}
