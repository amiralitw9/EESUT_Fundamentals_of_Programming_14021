#include <iostream>
using namespace std ;

int main() {
    long long int n,m,max=0,counter=0 ;
    cin>>n ;
    for (int i=1 ; i<=n ;i++) {
        cin>>m ;
        if (m>max)
            max =m ;
        if (i==m){
            if (max<=m)
                counter++;
            else
                continue;
        }
    }
    cout<<counter ;
}