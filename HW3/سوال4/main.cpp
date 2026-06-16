# include <iostream>
using namespace std ;

void horizontal (long long int num){ //line horizontal
    for (int i =1 ; i<=num ; i++)
        cout<<"# ";
    cout<<"\n";
}
int f(int h ,int n , long long int num ) { //خط اول بعد از خط افقی
    long long int i = 1,counter=0 ;
        for (i; i <= num; i += h) {
            if (i<(num-h)){
                for (int j = 1; j <= h; j++)
                cout << "# ";
                for (int k = 1; k <= (h - 2); k++)
                    cout << "  ";
                    i += (h - 2);
            }
            else
                break ;
        }
    for (i;i<=num;i++){
        cout<<"# " ;
        counter+=1;
    }
    cout<<"\n";
    return counter ;
    }
void g(int h ,int n , int num,int counter ) { //خط زیر خط دوم افقی
    long long int i = 1;
    if (n % 2 == 0) {
        for (int h = 1; h <= counter; h++)
            cout << "# ";
        for (i; i <= num; i += h) {
            if (i < (num - h)) {
                for (int k = 1; k <= (h - 2); k++)
                    cout << "  ";
                for (int j = 1; j <= h; j++)
                    cout << "# ";
                i += (h - 2);
            } else
                break;
        }
        cout << "\n";
    }
    else {
        cout << "# ";
        for (i; i <= num; i += h) {
            if (i < (num - h)) {
                for (int k = 1; k <= (h - 2); k++)
                    cout << "  ";
                for (int j = 1; j <= h; j++)
                    cout << "# ";
                i += (h - 2);
            } else
                break;
        }
        for (int s = 1; s <= (h - 2); s++)
            cout << "  ";
        cout << "# ";

        cout << "\n";


    }
}


int main() {
    long long int h, n, num, c,a;
    cin >> n >> h;
    num = (h - 1) * n + 1;
    horizontal(num);

    if (n%2==0) {
        for (int i = 1; i <= n; i+=2) {
            for (int j=1 ; j<=(h-2);j++)
                a = f(h,n,num);
            horizontal(num);
            for (int k=1 ; k<=(h-2);k++)
                g(h,n,num,a);
            horizontal(num);

        }
    }
    else {
        for (int i = 1; i <= n-1; i+=2) {
            for (int j=1 ; j<=(h-2);j++)
                a = f(h,n,num);
            horizontal(num);
            for (int k=1 ; k<=(h-2);k++)
                g(h,n,num,a);
            horizontal(num);

        }
        for (int s=1;s<=(h-2);s++)
            f(h,n,num);
        horizontal(num);
    }
}