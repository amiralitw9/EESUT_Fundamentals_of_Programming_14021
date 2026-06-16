#include <iostream>
using namespace std ;


int main() {
    unsigned int t, n, a_i, counter = 0;
    cin >> t;
    for (unsigned int i = 0; i < t; i++) {
        cin >> n;
        bool arr[n];
        for (unsigned int j = 0; j < n; j++) {
            cin >> a_i;
            if (a_i == 1) {
                arr[counter] = true;
                counter += 1;
            }
        }
        if ((n - counter) < (counter + 1)) {
            if (((counter % 2) == 0) && counter != 0) {
                cout << counter << endl;
                for (unsigned int k = 0; k < counter; k++) {
                    cout << "1" << " ";
                }
                cout << endl;
            } else if (counter >= 2) {
                cout << (counter - 1) << endl;
                for (unsigned int k = 1; k < counter; k++) {
                    cout << "1" << " ";
                }
                cout << endl;
            } else {
                cout << "1" << endl;
                cout << "0" << endl;
            }
            for (int z = 0; z < counter; z++) {
                arr[z] = false;
            }
        }
        else{
            cout<<(n - counter)<<endl;
            for(unsigned int c=0 ; c<(n - counter) ; c++){
                cout<<"0"<<" ";
            }
            cout<<endl ;
            for (int z = 0; z < counter; z++) {
                arr[z] = false;
            }
        }
        counter = 0;

    }
}