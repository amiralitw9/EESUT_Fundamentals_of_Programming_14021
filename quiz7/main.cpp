#include <iostream>
using namespace std ;

int main() {
    long long  m, n, counter_1 = 0,t = 0;
    cin >> m >> n;
    bool list[m][n];
    int zirlist_amoodi[n];
    int zirlist_ofoghi[m];
    bool zir_list[n];
    for ( int i = 0; i < m; i++) {
        for ( int j = 0; j < n; j++) {
             int b;
            cin >> b;
            list[i][j] = b;
        }
    }
    for ( int i = 0; i < m; i++) {
         int counter = 0;
        for ( int j = 0; j < n; j++) {
            if (list[i][j] == 1)
                counter++;
        }
        zirlist_ofoghi[i] = counter;


    }
    for ( int i = 0; i < n; i++) {
         int counter = 0;
        for ( int j = 0; j < m; j++) {
            if (list[j][i] == 1)
                counter++;

        }
        zirlist_amoodi[i] = counter;
    }
    for ( int i = 0; i < m; i++) {
        for ( int j = 0; j < n; j++) {
            if (list[i][j] == 1)
                zir_list[j] = 1;
            else
                zir_list[j]=0 ;
        }
        for ( int k = 0; k < n; k++) {
            if (zir_list[k] == 1) {
                for ( int z = k+1 ; z < n; z++) {
                    if (zir_list[z] == 1) {

                        counter_1 += (zirlist_amoodi[k]-1);
                        counter_1 += (zirlist_amoodi[z]-1);
                    }

                }
            }
        }
    }
//    counter_1/=2 ;
    cout<<counter_1;
//    for(int i = 0 ;i<n ;  i++)
//        cout<<zirlist_amoodi[i]<<" ";
}
