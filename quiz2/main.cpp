#include <iostream>
using namespace std ;
int main() {
    long long int m=0 , saver=0,count_save=0;
    int n ;
    cin>>n ;
    for(int i=1 ; i<=n ; i++) {
        cin>>m ;
        if (m==saver){
            cout<<"full";
            break ;
        }
        if (m>saver){
            saver = m;
            count_save=i ;
        }
        if (i==n)
            cout<<count_save ;
    }

}