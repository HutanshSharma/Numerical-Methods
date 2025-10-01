#include<bits/stdc++.h>
using namespace std;

double lagrange_cal(vector<double>nodes ,int pos, double x){
    double denom = 1;
    double num =1;
    for(int i=0;i<nodes.size();i++){
        if(i!=pos){
            denom*=(nodes[pos]-nodes[i]);
            num*=(x-nodes[i]);
        }
    }

    return num/denom;
}

double ans_cal(vector<double>input,vector<double>lagrange){
    double ans = 0;
    for(int i=0;i<input.size();i++){
        ans+=input[i]*lagrange[i];
    }
    return ans;
}

int main(){
    vector<double>nodes = {0,1,2};
    vector<double>value_of_y = {1,3,2};
    double x = 1.5;
    vector<double>lagrange(nodes.size());

    for(int i=0;i<nodes.size();i++){
        lagrange[i] = lagrange_cal(nodes,i,x);
    }

    for(auto i:lagrange){
        cout<<i<<" ";
    }
    cout<<endl;

    double ans = ans_cal(value_of_y,lagrange);
    cout<<ans;

}