#include <iostream>
using namespace std ;

int main() {
    long long int n,a,b=0,counter=0;
    cin>>n ;
    for (int i=1 ; i<=n;i++) {
        cin>>a ;
        if (a==-1 && b==0)
            counter +=1 ;
        else if (a!=-1)
            b+=a;
        else
            b-=1 ;

    }
    cout<<counter ;
}