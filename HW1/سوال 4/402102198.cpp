#include <iostream>
using namespace std ;
int main() {
//Answer_1
/*    int a ;
    cin>>a ;
    while (a>=0){
        if (a%3==0){
            cout<<"YES" ;
            break ;
        }
        a-=7 ;
    }
    if (a<7 & a!=6 & a!=3 & a!=0) {
        cout<<"NO" ;
    }*/
//Answer_2
/*    int a ;
    cin>>a ;
    if (a==1 || a==2 || a==4 || a==5 || a==8 || a==11 ){
        cout<<"NO" ;
    }
    else {
        cout<<"YES" ;
    } */
//Answer_3
    int a ;
    cin>>a ;
    if (a>=14) {
        cout<<"YES" ;
    }
    else if (a>=7) {
        if (a%3==0 || a%3==1){
            cout<<"YES" ;
        }
        else {
            cout<<"NO" ;
        }
    }
    else if (a>0) {
        if (a%3==0) {
            cout<<"YES" ;
        }
        else if (a%3==1 || a%3==2){
            cout<<"NO";
        }
    }
}
