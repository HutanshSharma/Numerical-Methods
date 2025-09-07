#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const double g = 32.17;
const double k = 0.1;
const double m = 0.25;
const double so = 300;

double f(double x){
    return (so-(m*g*x)/k+(pow(m,2)*g*(1-exp(-k*x/m)))/pow(k,2));
}

float secant(double a, double b) {
    int number_of_iter=10000;
    while(number_of_iter){
        if(f(a)==f(b)){
            cout<<"Division by zero"<<endl;
            break;
        }
        float temp=a-(f(a)*(a-b))/(f(a)-f(b));
        b=a;
        a=temp;
        number_of_iter--;
        if(fabs(f(a)-f(b))<0.01) break;
    }
    return a;
}

int main(){
    cout<<secant(1e5,2e5);
}