#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<double>> find_inverse(vector<vector<double>>org,int n){
    vector<vector<double>>inverse(n,vector<double>(n));
    for(int turn = 0;turn <n;turn++){
        vector<vector<double>>v1(n,vector<double>(n+1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                v1[i][j] = org[i][j];
            }
            if(i==turn)
                v1[i][n] = 1;
            else
                v1[i][n] = 0;
        }

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                double factor = v1[j][i]/v1[i][i];
                for(int k=i;k<n+1;k++){
                    v1[j][k]-=v1[i][k]*factor;
                }
            }
        }

        vector<double>ans(n);
        for(int i=n-1;i>=0;i--){
            double sum = 0;
            for(int j=i+1;j<n;j++){
                sum += v1[i][j]*ans[j];
            }
            ans[i] = (v1[i][n]-sum)/v1[i][i];
        }

        for(int i=0;i<n;i++){
            inverse[i][turn] = ans[i];
        }
    }

    return inverse;
}

int main(){
    vector<vector<double>>v1={{2,4,-2},{4,9,-3},{-2,-3,7}};
    vector<vector<double>>ans = find_inverse(v1,3);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}