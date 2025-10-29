#include<bits/stdc++.h>
using namespace std;

vector<vector<double>>augmented(vector<vector<double>>a,vector<double>b,int size){
    for(int i=0;i<size;i++){
        a[i].push_back(b[i]);
    }
    return a;
}

vector<vector<double>> lu(vector<vector<double>>u,int n){
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

    for(auto i:l){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    for(auto i:u){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    vector<vector<double>>inverse(n,vector<double>(n));
    for(int i=0;i<n;i++){
        vector<double>b(n,0);
        for(int j=0;j<n;j++){
            if(j==i) b[j]=1;
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
        for(int j=0;j<n;j++){
            inverse[j][i] = ans[j];
        }
        }

        return inverse;
}

int main(){
    vector<vector<double>>a = {{3,-0.1,-0.2},{0.1,7,-0.3},{0.3,-0.2,10}};
    vector<vector<double>> ans = lu(a,3);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}