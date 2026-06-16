#include <iostream>
#include <cmath>
using namespace std ;

long long int f (long long int number){ //nozooli
    long long int max=number%10,a_1=1,num_1=number;
    while (num_1>0) {
        num_1/=10;
        if (num_1%10>max) {
            a_1 = 0;
            break;
        }
        max = num_1%10 ;
    }    
    return a_1 ;

    }

long long int g (long long int number){ //soodi
        long long int min=number%10,a_2=1,num_2=number ;
    while(num_2>9){
        num_2/=10;
        if (num_2%10<min){
            a_2=0;
            break ;
        }
        min= num_2 %10 ;
    }    
    return a_2 ;
    
    }

bool hasExtermum(long long int num){
    long long int max=0 , min=10,counter,number= num ;
    while (number>0) {
        counter = number%10 ;
        if (counter<min)
            min = counter;
        if (counter>max)
            max = counter ;
        number/=10 ;
    }

    long long int c_1=0,c_2=0,c_3=0,c_4=0,i=0 ;
    number=num;
    while ((number%10) !=max) { //تقسیم عدد به قبل از ماکس که اگر در شرط برقرار باشد باید صعودی باشد
        c_1+=(number%10)*pow(10,i) ;
        number/=10;
        i++;
    }
    i=0;
    while (number>0){//تقسیم عدد به بعد از ماکس که اگر در شرط برقرار باشد باید نزولی باشد
        c_2+=(number%10)*(pow(10,i));
        number/=10;
        i++;
    }
    number=num;
    i=0;
    while ((number%10) !=min) { //تقسیم عدد به قبل از مین که اگر در شرط برقرار باشد باید نزولی باشد
        c_3+=(number%10)*pow(10,i) ;
        number/=10;
        i++;
    }
    while (number>0){//تقسیم عدد به قبل از مین که اگر در شرط برقرار باشد باید نزولی باشد
        c_4+=(number%10)*(pow(10,i));
        number/=10;
        i++;
    }
    if (f(c_2)==1&&g(c_1)==1)
        return true ;
    else if (g(c_4)==1&&f(c_3)==1)
        return true ;
    else 
        return false ;
}

bool isPalindrome(long long int number){
    long long int c=0,num=number;
    while (number>0) {
        c *= 10;
        c += number % 10;
        number /= 10;
    }
    if (c==num)
        return true;
    else
        return false ;
}

int main(){
    long long int a,m,counter=0,save=0 ;
    int v_1=0,v_2=0;
    cin>>a ;
    for (int i =1 ;i<=a ; i++) {
        cin>>m ;
        if (isPalindrome(m)== 1 || hasExtermum(m)==1){
            counter+=1 ;
            if (isPalindrome(m)==1) {
                v_1 = 1;
            }
            if (hasExtermum(m)==1) {
                v_2 = 1;
            }
            if (v_1==1 && v_2==1){
                if (counter>save)
                    save=counter ;
            }

        }
        else
            counter=0,v_1=0,v_2=0;
    }
    cout<<save ;
}
