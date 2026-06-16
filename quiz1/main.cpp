#include <iostream>
using namespace std ;

int main() {
    long long int n=0,x_1=0,x_2=0,counter=0 ;
    cin>>n>>x_1>>x_2 ;
    if (x_1>x_2){
        counter = x_1 ;
        x_1=x_2 ;
        x_2=counter ;
    }
    long long int tool_1=x_1 , tool_2 =n-x_2 , tool_3 =x_2-x_1;
    if (tool_1+tool_2<=tool_3 ||tool_2+tool_3<=tool_1 || tool_1+tool_3<=tool_2) {
        cout<<"NO" ;
    }
    else
        cout<<"YES" ;
}
