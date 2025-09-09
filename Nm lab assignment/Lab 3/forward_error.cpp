#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// L2 norm 
double abs_forward_error(vector<double>calculated_ans, vector<double>real_ans, int size){
    double sum=0;
    for(int i=0;i<size;i++){
        double temp=real_ans[i]-calculated_ans[i];
        sum+=pow(temp,2);
    }
    return pow(sum,0.5);
}

double relative_forward_error(vector<double>calculated_ans, vector<double>real_ans, int size){
    double sum=0;
    for(int i=0;i<size;i++){
        double temp=real_ans[i]-calculated_ans[i];
        sum+=pow(temp,2);
    }
    double sum_norm=pow(sum,0.5);
    double val_sum=0;
    for(auto i:real_ans){
        val_sum+=pow(i,2);
    }
    double org_norm=pow(val_sum,0.5);
    return sum_norm/org_norm;
}

vector<double> gaussian(vector<vector<double>>&h,int size){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            double factor=h[j][i]/h[i][i];
            for(int k=i;k<size+1;k++){
                h[j][k]-=h[i][k]*factor;
            }
        }
    }
    vector<double>ans(size);
    for (int i=size-1;i>=0;i--) {
        double sum=0.0;
        for (int j=i+1;j<size;j++) {
            sum+=h[i][j]*ans[j];
        }
        ans[i]=(h[i][size]-sum)/h[i][i];
    }

    return ans;

}

int main(){
    vector<vector<double>>h;
    for(int i =0;i<3;i++){
        vector<double>temp;
        for(int j=0;j<3;j++){
            temp.push_back(1/(i+j+1.0));
        }
        h.push_back(temp);
    }

    vector<double>b={11/6.0,13/12.0,47/60.0};

    for(int i=0;i<3;i++){
        h[i].push_back(b[i]);
    }

    vector<double>ans=gaussian(h,3);
    vector<double>actual_ans={1,1,1};
    cout<<abs_forward_error(ans,actual_ans,3)<<endl;
    cout<<relative_forward_error(ans,actual_ans,3)<<endl;

    for(auto i:ans){
        cout<<i<<endl;
    }
}