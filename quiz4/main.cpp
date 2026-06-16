#include <iostream>
using namespace std ;

int main() {
    int n, k,counter_i,counter_j,sum=0;
    cin >> n >> k;
    bool list_0[n][n];
    bool list_1[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool m;
            cin >> m;
            list_0[i][j] = m;
        }
    }//لیست اولیه
    for(int q=0 ; q<k ; q++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                counter_i = i;
                counter_j = j;
                for (counter_i - 1; counter_i + 1 <= i + 1; counter_i++) {
                    if ((counter_i - 1) < 0 || counter_i + 1 >= n)
                        continue;
                    for (counter_j - 1; counter_j + 1<=j+1; counter_j++) {
                        if ((counter_j - 1) < 0 || counter_j + 1 >= n)
                            continue;
                        if (counter_i == i && counter_j == j)
                            continue;
                        if (list_0[i][j] == 1)
                            sum += 1;
                        else if (list_0[i][j] == 0)
                            sum -= 1;
                    }
                }
                if (sum > 0)
                    list_1[i][j] = 1;
                else if (sum == 0)
                    list_1[i][j] = list_0[i][j];
                else if (sum < 0)
                    list_1[i][j] = 0;
            }
            sum = 0;
        }
        for (int i = 0; i < n; i++) {  //دستور تغییر دادن
            for (int j = 0; j < n; j++) {
                list_0[i][j] = list_1[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << list_1[i][j] << " ";
        }
        cout << endl;
    }


}
