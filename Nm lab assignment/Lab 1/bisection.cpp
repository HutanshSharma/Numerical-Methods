#include<bits/stdc++.h>
using namespace std;

double f(double x){
    return (pow(x,2)-5*x+6);
}

double bisection(double a,double b,int iter,double tol){
    double midp=0;
    if(f(a)==0) return a;
    else if(f(b)==0) return b;
    else if(f(a)*f(b)>0){
        cout<<"No root in this interval";
        return -1;
    }
    for(int i=0;i<iter;i++){
        double avalue = f(a);
        double bvalue = f(b);
        midp = (a+b)/2;
        if(fabs(a-b)<tol || f(midp)==0){
            return midp;
        }
        double newvalue = f(midp);
        if(avalue*newvalue<0){
            b=midp;
        }
        else{
            a=midp;
        }
    }
    return midp;
}

int main(){
    double ans = bisection(2.5,4,1000,1e-6);
    cout<<ans;
}