#include <iostream>
using namespace std ;
void vorodi_2_matrix( int & n , long long int a [50][50] ){
    for(int i = 0 ; i<n ; i++){
        for(int j =0 ; j<n ; j++){
            long long int g ;
            cin>>g ;
            a[i][j]=(g%1000000007) ;

        }
    }
}
void zarb_2_matrix(long long int a [50][50],long long int b [50][50],long long int c[50][50], int &n);

int main() {
    int n, k;
    cin >> n >> k;
    long long int a[50][50], b[50][50],c[50][50],d[50][50];
    vorodi_2_matrix(n, a);
    vorodi_2_matrix(n, b);
    zarb_2_matrix(a,b,c,n);
    zarb_2_matrix(c,c,d,n);
    if (k==1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << c[i][j]<<" ";
            }
            cout<<endl;
        }

    }
    else {
        for (int z = 0; z < k - 2; z++) {


            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    b[i][j] = d[i][j];
                }
            }
            zarb_2_matrix(b, c, d, n);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << d[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}



void zarb_2_matrix(long long int a [50][50],long long int b [50][50],long long int  c[50][50], int &n){
    long long int sum = 0;
    for(int i = 0 ; i<n ; i++) {
        for (int k = 0 ; k<n ; k++) {
            for (int j = 0 ; j<n ; j++) {
                sum+=((a[i][j]*b[j][k])%1000000007);
                sum%=1000000007;

            }
            c[i][k]=sum ;
            sum=0;
        }
    }
}