#include<bits/stdc++.h>
using namespace std;

const double g = 32.17;
const double k = 0.1;
const double m = 0.25;
const double so = 300;

double f(double x){
    return (so-(m*g*x)/k+(pow(m,2)*g*(1-exp(-k*x/m)))/pow(k,2));
}

double secant(double a,double b,int iter,double tol){
    for(int i=0;i<iter;i++){
        double df = (f(a)-f(b))/(a-b);
        if(df==0){
            cout<<"Zero derivative";
            return -1;
        }
        double newpt = a-f(a)/df;
        if(fabs(newpt-a)<tol) return newpt;
        b=a;
        a=newpt;
    }
    return a;
}

int main(){
    cout<<secant(1e5,2e5,1000,1e-6);
}