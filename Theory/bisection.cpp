#include<iostream>
#include<bits/stdc++.h>
using namespace std;

float f(float x){
    return (pow(x,2)-5*x+6);
}

float find_root(float a, float b, float tol){
    if(f(a) == 0) return a;
    else if(f(b)==0) return b;
    else if(f(a)*f(b)>0) return -1;

    float midp = -1;
    while(((b-a)/2.0)>tol){
        midp = (b+a)/2.0;
        float value = f(midp);
        if(value == 0 ) return midp;
        else if(value*f(b)<0) a=value;
        else b = value;
    }

    return midp;
}

int main(){
    float ans = find_root(2.5,4,0.00001);
    cout<<ans;
}