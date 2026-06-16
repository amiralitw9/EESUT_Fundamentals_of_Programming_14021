#include <iostream>
using namespace std ;
#define IoFast ios_base::sync_with_stdio(0);cin.tie(0);

int main() {
    IoFast;
    int n, m ;
    cin >> n >> m;
    int list[m], list_1[n];
    for (int i = 0; i < n; i++)
        list_1[i] = 0;
    for (int k = 0; k < m; k++) {
        int j;
        cin >> j;
        list[k] = j;
    }


   for (int i = 0; i < m; i++) {
        for (int j = (n - 1); j >= (list[i] - 1); j--) {
            if (list_1[j] == 0) {
                list_1[j] = list[i];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << list_1[i]<<" ";

    }
}