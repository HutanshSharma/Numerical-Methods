#include<bits/stdc++.h>
using namespace std;

double f(double x){
    if(x == 1) return 0;
    else if (x == 4) return 1.386294;
    else if (x == 6) return 1.791759;
    else if (x == 5) return 1.609438;
    return -1;
}

double first_div_diff(double x, double y){
    return (f(y)-f(x))/(y-x);
}

double second_div_diff(double x, double y, double z){
    return (first_div_diff(y,z) - first_div_diff(x,y))/(z-x);
}

double third_div_diff(double w, double x, double y, double z){
    return (second_div_diff(x,y,z) - second_div_diff(w,x,y))/(z-w);
}

int main(){
    double x0=1;
    double x1=4;
    double x2=5;
    double x3=6;

    double x = 2;
    double val = f(x0) + (x-x0)*first_div_diff(x0,x1) + (x-x0)*(x-x1)*second_div_diff(x0,x1,x2) + (x-x0)*(x-x1)*(x-x2)*third_div_diff(x0,x1,x2,x3);
    
    double org_val = 0.6931472;
    cout<<val<<endl;
    cout<<(org_val-val)/org_val;
}