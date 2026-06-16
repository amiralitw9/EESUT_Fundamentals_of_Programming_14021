#include <iostream>
using namespace std ;

int main() {
    long long int c_1=0 , c_2=1 ,c_3, a;
    cin>>a ;
    if (a==0)
        cout<<0 ;
    else {
        for (int i = 0; i <= a - 2; i++) {
            c_3 = c_1 + c_2;
            c_1 = c_2;
            c_2 = c_3;
        }

        cout << c_2;
    }
}