#include <iostream>
using namespace std ;
int main() {
    long long int n, a, counter = 0, last_p = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (last_p < a)
            last_p = a;
        if (a == i && last_p <= a) {
            counter += 1;
        }
    }
    cout<<counter ;
}