#include <iostream>
using namespace std ;

int  b_m_m (int a , int b) {
    int c = 1 ;
    if (b>a)
        swap(a,b);
    while (c!=0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a ;
}

int main() {
    int a, f, max = 0, counter = 0;
    cin >> a;
    string b;
    int list[26];
    for (int i = 0; i < 26; i++)
        list[i] = 0;
    cin >> b;
    int size = b.length();
    for (int i = 0; i < size; i++) {
        list[b[i] - 'a'] += 1;

    }
    for (int i = 0; i < 26; i++) {
        if (list[i] > max)
            max = list[i];
    }
    f = max;

    for (int i = 0; i < 26; i++) {
        if (list[i] != 0) {
            int d = list[i];
            f = b_m_m(d, f);
        }
    }
    if (f % a != 0)
        cout << -1;
    else {
        f /= a;
        char list_1[size];
        for (int i = 0; i < 26; i++) {
            if (list[i] != 0) {
                for (int j = 0; j < (list[i] / a); j++) {
                    list_1[counter] = i + 'a';
                    counter += 1;

                }
            }
        }
        for (int j = 0; j < a; j++) {
            for (int z = 0; z < counter ; z++)
                cout << list_1[z];
        }
    }
}