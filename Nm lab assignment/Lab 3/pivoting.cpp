#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<double> gaussian(vector<vector<double>>&h,int size){
    for(int i=0;i<size-1;i++){
        int maxrowidx=i;
        double maxvalue=fabs(h[i][i]);
        for(int l=i;l<size;l++){
            if(fabs(h[l][i])>maxvalue){
                maxvalue=fabs(h[l][i]);
                maxrowidx=l;
            }
        }
        swap(h[i],h[maxrowidx]);
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
    vector<vector<double>>h = {{1e-15,1,1},{1,1,1},{1,1,2}};

    vector<double>b={2.0,3.0,4.0};

    for(int i=0;i<3;i++){
        h[i].push_back(b[i]);
    }

    vector<double>ans = gaussian(h,3);
    for(auto i:ans){
        cout<<i<<endl;
    }
}

// i am getting the same answer for the above question with 
// and without pivoting because 1e-6 is not so small to produce some potential change in the answer if we take some more smaller number
// for e.g. 1e-15 then the answer is different 
// with pivoting ans is = {1,1,1}
// without pivoting ans is = {0.888178,1,1}

// it happens because at 
// 1e-6, the factor is 1e6
// That’s large, but still within the range where double precision (about 15–16 significant digits)
// can handle it without much visible error in such a small system.
// At 1e-15 the factore is 1e15
// here we are pushing close to the limits of double precision
// this introduces huge round-off errors,
// because floating-point double precision can’t represent differences between large and nearly equal numbers accurately.
// while in pivoting since the rows get swapped so the first row becomes 1,1,1 so here there is no factor of 1e15 hence we get 
// the correct answer (1,1,1)