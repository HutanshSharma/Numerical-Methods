#include<bits/stdc++.h>
using namespace std;

double f(double x){
    return (sinf(3.14*(x+1)/4));
}

int main(){
    vector<vector<pair<double,double>>> v1 = {
        {{0,2}},
        {{0.57735,1},{-0.57735,1}},
        {{0,8/9},{0.774597,5/9},{-0.774597,5/9}},
        {{0.339981,0.652145},{-0.339981,0.652145},{0.861136,0.347855},{-0.861136,0.347855}},
        {{0,0.568889},{0.538469,0.478629},{-0.538469,0.478629},{0.90618,0.236927},{-0.90618,0.236927}}
    };

    vector<double>ans;

    for(auto i:v1){
        double sum=0;
        for(auto j:i){
            sum+=f(j.first)*j.second;
        }
        ans.push_back(sum);
    }

    for(auto i:ans){
        cout<<i<<endl;
    }
}