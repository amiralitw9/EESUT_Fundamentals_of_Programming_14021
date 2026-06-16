#include <iostream>
#include <cmath>
#define IoFast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std ;


int main() {
    IoFast;
    int n, m, q, counter_2 = 0, t, counter = 0;
    cin >> n >> m;
    int pos_list[n];
    int neg_list[n];
    int list_accused[n];
    int list_t[n];
    for (int i = 0; i < n; i++) {
        pos_list[i] = 0;
        neg_list[i] = 0;
        list_t[i]=0;
    }

    for (int i = 0; i < n; i++) {
        cin >> q;
        list_accused[i] = q;
        if (q > 0) {
            pos_list[q - 1] += 1;
        }
        if (q < 0) {
            neg_list[-q - 1] += 1;
            counter_2 += 1;
        }

    }
    for (int i = 0; i < n; i++) {
        t = abs(list_accused[i]) - 1;
        list_t[t]+=1;
        if (m == (pos_list[t] + counter_2 - neg_list[t]) && list_t[t]==1) {
            counter += 1;
        }
    }
    for(int i = 1 ; i<n+1 ; i++){
        if(m==counter_2 &&list_t[i]==0)
            counter+=1 ;
    }
    for (int i = 0; i < n; i++) {
        t = abs(list_accused[i]) - 1;
        if (counter >= 2) {
            if (m != (pos_list[t] + counter_2 - neg_list[t])) {
                if (list_accused[i] < 0) {
                    cout << "Truth";
                    cout << endl;
                }
                if (list_accused[i] > 0) {
                    cout << "Lie";
                    cout << endl;
                }
            } else {
                cout << "Not defined";
                cout << endl;
            }
        }
        if (counter==1) {
            if (m == (pos_list[t] + counter_2 - neg_list[t])) {
                if (list_accused[i] < 0) {
                    cout << "Lie";
                    cout << endl;
                }
                if (list_accused[i] > 0) {
                    cout << "Truth";
                    cout << endl;
                }
            } else {
                if (list_accused[i] < 0) {
                    cout << "Truth";
                    cout << endl;
                }
                if (list_accused[i] > 0) {
                    cout << "Lie";
                    cout << endl;
                }

            }
        }
    }
}
