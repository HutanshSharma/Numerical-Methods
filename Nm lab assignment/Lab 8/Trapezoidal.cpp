#include<bits/stdc++.h>
using namespace std;

double f(double x){
    return sinf(x);
}

double area(double x, double node_size){
    return ((f(x-node_size)+f(x))/2.0)*node_size;
}

int main(){
    int nodes = 5;
    double upper_limit = 3.14/2.0;
    double lower_limit = 0;
    vector<double>areas;

    double node_size = (upper_limit-lower_limit)/nodes;

    for(double i =node_size;i<=upper_limit;i+=node_size){
        areas.push_back(area(i,node_size));
    }

    double ans = 0;
    for(auto i:areas){
        ans+=i;
    }
    cout<<ans;
}