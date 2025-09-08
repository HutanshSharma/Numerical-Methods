#include<bits/stdc++.h>
using namespace std;

vector<vector<double>> l(vector<vector<double>>v1,int n){
    vector<vector<double>>l(n,vector<double>(n,0));
    for(int col=0;col<n;col++){
        for(int row=0;row<n;row++){
            if(col==row){
                double value = 0;
                for(int k=0;k<col;k++){
                    value += pow(l[col][k],2);
                }
                l[col][col] = sqrt(v1[col][col]-value);
            }
            else if(col<row){
                double value = 0;
                for(int k=0;k<col;k++){
                    value+=l[row][k]*l[col][k];
                }
                l[row][col] = (v1[row][col] - value)/l[col][col];
            }
        }
    }
    return l;
}

vector<vector<double>>augmented(vector<vector<double>>a,vector<double>b,int size){
    for(int i=0;i<size;i++){
        a[i].push_back(b[i]);
    }
    return a;
}

vector<vector<double>> transpose(vector<vector<double>>l,int n){
    vector<vector<double>>ans(n,vector<double>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i][j] = l[j][i];
        }
    }
    return ans;
}

vector<double> cholesky(vector<vector<double>>u,vector<vector<double>>l,vector<double>b,int n){
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
    vector<vector<double>>v1 = {{4,12,-16},{12,37,-43},{-16,-43,98}};
    vector<double>b = {1,2,3};

    vector<vector<double>>L = l(v1,3);
    vector<vector<double>>U = transpose(L,3);

    vector<double>ans = cholesky(U,L,b,3);
    for(auto i:ans){
        cout<<i<<" ";
    }
}