#include <iostream>
using namespace std ;
#define IoFast ios_base::sync_with_stdio(0);cin.tie(0);

int main() {
    IoFast;
    long long  int n , k,counter=0 ;
    long long  int  list_tekrari [100000];
    long long  int  list_addadd [100000];
    for(long long  int i = 0 ; i<100000 ; i++) {
        list_tekrari[i] = 0;
        list_addadd[i] = 0;
    }
    cin>>n>>k ;
    long long int ans[n];
    long long  int list [n];
    for(long long  num_kala = 0 ;num_kala<n ; num_kala++){
        long long  int g ;
        cin>>g ;
        list[num_kala]=g; // تعریف لیست اعداد
    }
    for(long long int  i = 0 ; i<n ; i++) {
        list_tekrari[list[i]] += 1;
        if(list_tekrari[list[i]]==1)
            counter+=1 ;
    }
    ans[0]=counter;
    for(long long int i=1 ;i<n ;i++ ) {
        list_tekrari[list[i-1]]-=1 ;
        if(list_tekrari[list[i-1]]==0)
            counter-=1;
        ans[i]=counter ;
    }
    for(long long int question = 0 ; question<k ; question++) {
        long long int p ;
        cin>>p ; // پرسش های داور
        p-=1 ; // تبدیل به عدد در لیست
        cout<<ans[p]<<endl ;
    }
/*    for(long long int i = 0 ; i<n ; i++) {
        cout<<ans[i] ;
    }*/
}