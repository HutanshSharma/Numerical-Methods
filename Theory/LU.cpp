#include<bits/stdc++.h>
using namespace std;

vector<vector<double>>augmented(vector<vector<double>>a,vector<double>b,int size){
    for(int i=0;i<size;i++){
        a[i].push_back(b[i]);
    }
    return a;
}

vector<double> lu(vector<vector<double>>u,vector<double>b,int n){
    vector<vector<double>>l(n,vector<double>(n,0));
    for(int i=0;i<n;i++){
        l[i][i]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            double factor = u[j][i]/u[i][i];
            l[j][i]=factor;
            for(int k=i;k<n;k++){
                u[j][k] -= u[i][k]*factor; 
            }
        }
    }
    vector<vector<double>>augmented_l = augmented(l,b,n);

    vector<double>temp(n);
    for(int i=0;i<n;i++){
        double sum = 0;
        for(int j=0;j<i;j++){
            sum+=augmented_l[i][j]*temp[j];
        }
        temp[i] = (augmented_l[i][n] - sum)/augmented_l[i][i];
    }

    vector<vector<double>>augmented_u = augmented(u,temp,n);

    vector<double>ans(n);
    for(int i=n-1;i>=0;i--){
        double sum=0;
        for(int j=i+1;j<n;j++){
            sum+=augmented_u[i][j]*ans[j];
        }
        ans[i] = (augmented_u[i][n]-sum)/augmented_u[i][i];
    }
    return ans; 
}

int main(){
    vector<vector<double>>a = {{1,1,-1},{1,-2,3},{2,3,1}};
    vector<double>b = {4,-6,7};
    vector<double>ans = lu(a,b,3);
    for(auto i:ans){
        cout<<i<<" ";
    }

}