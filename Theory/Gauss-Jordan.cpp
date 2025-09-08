#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<double> gauss_jordan(vector<vector<double>>a,int n){
    for(int i=0;i<n;i++){
        int maxrowidx = i;
        double maxvalue = fabs(a[i][i]);
        for(int l=i;l<n;l++){
            if(fabs(a[l][i])>maxvalue){
                maxvalue = fabs(a[l][i]);
                maxrowidx = l;
            }
        }
        swap(a[maxrowidx],a[i]);

        double pivot = a[i][i];
        for (int k = i; k <= n; k++) {
            a[i][k] /= pivot;
        }

        for(int j=i+1;j<n;j++){
            double factor = a[j][i];
            for(int k=i;k<n+1;k++){
                a[j][k] -= a[i][k]*factor; 
            }
        }
    }

    for(int i=n-1;i>0;i--){
        for(int j=i-1;j>=0;j--){
            double factor = a[j][i];
            for(int k=n+1;k>=i;k--){
                a[j][k]-=a[i][k]*factor; 
            }
        }
    }

    vector<double>ans(n);

    for(int i=0;i<n;i++){
        ans[i] = a[i][n];
    }

    return ans;
}

int main(){
    vector<vector<double>>a = {{2,4,-2},{4,9,-3},{-2,-3,7}};
    vector<double>b = {1,2,3};
    for(int i=0;i<3;i++){
        a[i].push_back(b[i]);
    }
    vector<double>ans = gauss_jordan(a,3);
    for(auto i:ans){
        cout<<i<<" ";
    }
}