#include <iostream>
#include <cmath>
using namespace std ;
bool areEqual(double r_1, double r_2, double r_3) {
    if (r_1==r_2 || r_1==r_3 ||r_2==r_3){
        return false ;
    }
    return true ;
}
long long int calculateScore(double x,double y, double r_1, double r_2, double r_3,long long int s_1, long long int s_2, long long int s_3){
    if ((x*x+y*y)<(r_1*r_1))
        return s_1 ;
    if ((x*x+y*y)<(r_2*r_2))
        return s_2 ;
    if ((x*x+y*y)<(r_3*r_3))
        return s_3 ;
    return 0 ;

}



int main() {
    double r_1, r_2, r_3,sum = 0;
    long long int n ;
    long long int s_1, s_2, s_3, counter;
    cin >> r_1 >> r_2 >> r_3;
    cin >> s_1 >> s_2 >> s_3;
    for (int i = 0; i < 2; i++) {
        if (s_1 > s_2) {
            counter = s_1;
            s_1 = s_2;
            s_2 = counter;
        }
        if (s_2 > s_3) {
            counter = s_2;
            s_2 = s_3;
            s_3 = counter;

        }
    }
    double r,t;
    cin >> r;
    t = (r/r_1);
    r_1 = r;
    r_2 *= t;
    r_3 *= t;
    double  x, y ;
    cin >> n;
    for(long long int i =0 ; i<n ; i++) {
        cin >> x >> y;
        sum+= calculateScore(x,y,r_1,r_2,r_3,s_3,s_2,s_1);
    }
    if (areEqual(r_1, r_2, r_3) == false) {
        cout << "error";
    }
    else
        cout<<sum ;
}