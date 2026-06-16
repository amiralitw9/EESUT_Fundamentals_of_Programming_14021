#include <iostream>
using namespace std ;
#define IoFast ios_base::sync_with_stdio(0);cin.tie(0);

int main() {
    IoFast;
    long long int k ;
    unsigned int n, m, a, b, c;
    cin >> n >> m >> k;
    int list[n][m];
    for(int i=0 ; i<n ;i++){
        for(int j=0 ;j<m ; j++){
            list[i][j]=0;
        }
    }
    for (int i = 1; i <= k; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            for (int j = 0; j < m; j++) {
                list[b-1][j] = c;
            }
        }
        if (a == 2) {
            for (int k = 0; k < n; k++) {
                list[k][b-1] = c;
            }
        }
    }
    for(int i = 0 ;i<n ; i++) {
        for(int j=0 ; j<m ; j++){
            cout<<list[i][j]<<" ";
        }
        cout<<endl ;
    }
}
