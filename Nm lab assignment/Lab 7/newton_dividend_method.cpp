#include<bits/stdc++.h>
using namespace std;

vector<vector<double>> dividend_table(vector<double>x, vector<double>y){
    vector<vector<double>>dividend(y.size(),vector<double>(y.size(),0));
    int n= y.size();
    for(int i=0;i<n;i++){
        dividend[i][0] = y[i];
    }
    for(int j=1;j<n;j++){
        for(int i=0;i<n-j;i++){
            dividend[i][j] = (dividend[i+1][j-1] - dividend[i][j-1])/(x[i+j]-x[i]);
        }
    }

    return dividend;
}

double newton(vector<vector<double>>dividend, double x, vector<double>X){
    double turn = 1;
    double ans = 0;
    int n = X.size();

    for(int i=0;i<n;i++){
        ans += dividend[0][i]*turn;
        turn*= (x-X[i]);
    }

    return ans;
}

int main(){
    vector<double>X={1,4,5,6};
    vector<double>Y={0,1.386294,1.791759,1.609438};
    vector<vector<double>>dividend = dividend_table(X,Y);

    double x = 2;
    double val = newton(dividend,x,X);
    double org_val = 0.6931472;
    cout<<val<<endl;
    cout<<(org_val-val)/org_val;
}