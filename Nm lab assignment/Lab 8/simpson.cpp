#include<bits/stdc++.h>
using namespace std;

double f(double x){
    return sin(x);
}

double area_strip(double node_size, double x){
    return (f(x-node_size)/3 + (4*f(x))/3 + f(x+node_size)/3)*node_size;
}

int main(){
    int nodes = 4;
    double upper_limit = 3.14/2.0;
    double lower_limit = 0;
    vector<double>areas;

    double node_size = (upper_limit-lower_limit)/nodes;

    for(double i =node_size;i<upper_limit;i+=2*node_size){
        areas.push_back(area_strip(node_size,i));
    }

    double ans = 0;
    for(auto i:areas){
        ans+=i;
    }
    cout<<ans;
}