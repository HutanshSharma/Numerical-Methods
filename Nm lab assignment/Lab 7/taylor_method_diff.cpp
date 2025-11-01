#include<bits/stdc++.h>
using namespace std;

const double h = 0.25;

double relative_error(double org, double cal){
    return fabs(org-cal)/org;
}

double f(double x){
    return (-0.1*pow(x,4)-0.15*pow(x,3)-0.5*pow(x,2)-0.25*x+1.2);
}

double forward_diff2(double x){
    return (f(x+2*h) - 2*f(x+h) + f(x))/pow(h,2);
}

double backward_diff2(double x){
    return (f(x) - 2*f(x-h) + f(x-2*h))/pow(h,2);
}

double central_diff2(double x){
    return (f(x+h) + f(x-h) - 2*f(x))/pow(h,2);
}

double backward_diff1(double x){
    return (f(x)-f(x-h))/h;
}

double forward_diff1(double x){
    return (f(x+h) - f(x))/h;
}

double central_diff1(double x){
    return (f(x+h)-f(x-h))/(2*h);
}

double org_derivative1(double x){
    return (-0.4*pow(x,3)-0.45*pow(x,2)-x-0.25);
}

double org_derivative2(double x){
    return (-1.2*pow(x,2)-0.9*x-1);
}




int main(){
    double x= 0.5;
    double org_val1 = org_derivative1(x);
    double forward_val1 = forward_diff1(x);
    double central_val1 = central_diff1(x);
    double backward_val1 = backward_diff1(x);

    cout<<org_val1<<" "<<forward_val1<<" "<<central_val1<<" "<<backward_val1<<endl;
    cout<<relative_error(org_val1,forward_val1)<<endl;
    cout<<relative_error(org_val1,central_val1)<<endl;
    cout<<relative_error(org_val1,backward_val1)<<endl;

    cout<<endl;

    double org_val2 = org_derivative2(x);
    double forward_val2 = forward_diff2(x);
    double central_val2 = central_diff2(x);
    double backward_val2 = backward_diff2(x);

    cout<<org_val2<<" "<<forward_val2<<" "<<central_val2<<" "<<backward_val2<<endl;
    cout<<relative_error(org_val2,forward_val2)<<endl;
    cout<<relative_error(org_val2,central_val2)<<endl;
    cout<<relative_error(org_val2,backward_val2)<<endl;
}