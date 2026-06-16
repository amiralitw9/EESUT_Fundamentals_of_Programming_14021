#include <iostream>

using namespace std ;

int main() {
    long long int m, min_counter = 0, max_counter = 0, c_1 = 0, c_2 = 0, c_3 = 0, tek = 1, i=0 ;
    while (true) {
        i++;
        cin >> m;
        if (c_3 == m) {
            tek++;
            continue;
        } else
            c_3 = m;
        if (m == -1)
            break;
        else {
            if (i>2) {
                if (c_2 > c_1 && c_2 > c_3 && c_1 !=0) {
                    max_counter += tek;
                    tek = 1;

                }
                else if (c_2 < c_1 && c_2 < c_3 && c_1 !=0) {
                    min_counter += tek;
                    tek = 1;
                } else
                    tek = 1;
            }


            c_1 = c_2;
            c_2 = c_3;
        }


    }
    cout << min_counter << " " << max_counter;
}