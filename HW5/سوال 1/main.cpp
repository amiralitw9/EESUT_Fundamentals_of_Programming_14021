#include <iostream>
using namespace std ;
int main() {
    int a,size,counter=0 ;
    cin>>a;
    for(int i = 0 ; i<a ;i++) {
        string b ;
        cin>>b ;
        size = b.length();
        char list [size];
        for(int j = 0 ; j<size ; j++) {
            if (b[j]!='b'){
                list[counter]=b[j];
                counter+=1;
            }
            if (b[j]=='b' && counter!=0)
                counter-=1;
//            cout<<counter ;
        }
        for(int z = 0 ; z<counter ; z++){
            cout<<list[z];
        }
        counter = 0 ;
        cout<<endl ;
    }
}