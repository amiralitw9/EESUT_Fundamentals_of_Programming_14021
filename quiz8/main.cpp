#include<iostream>
using namespace std ;
using namespace std ;
int fib(int a ) {
    if(a==0)
        return 1 ;
    if(a==1)
        return 1 ;
    return fib(a-1)+fib(a-2);

}
int main() {
    long long int b = 1;
    int num ;
    cin>>num ;
    for(int i = 0 ; i<num ; i++) {
        b*=fib(i);
    }
    cout<<b ;
}