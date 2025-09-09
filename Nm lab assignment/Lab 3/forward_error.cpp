#include<bits/stdc++.h>
using namespace std;

// L2 norm
double norm(vector<double>v1){
    double sum = 0;
    for(auto i:v1){
        sum+=pow(i,2);
    }

    return sqrt(sum);
}

double forward_error(vector<double>calans, vector<double>organs){
    for(int i=0;i<calans.size();i++){
        calans[i]-=organs[i];
    }
    return norm(calans)/norm(organs);
}

vector<double> gaussian(vector<vector<double>>a,int size){
    for(int i=0;i<size;i++){
        int maxrowidx = i;
        double maxvalue = fabs(a[i][i]);

        for(int k=i+1;k<size;k++){
            if(fabs(a[k][i])>maxvalue){
                maxrowidx = k;
                maxvalue = fabs(a[k][i]);
            }
        }

        swap(a[maxrowidx],a[i]);

        for(int j=i+1;j<size;j++){
            double factor = a[j][i]/a[i][i];
            for(int k=i;k<=size;k++){
                a[j][k] -= a[i][k]*factor;
            }
        }
    }
    vector<double>ans(size);
    for(int i=size-1;i>=0;i--){
        double sum=0;
        for(int j=i+1;j<size;j++){
            sum+=a[i][j]*ans[j];
        }
        ans[i] = (a[i][size]-sum)/a[i][i];
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
    vector<double>organs = {1,1,1};

    for(int i=0;i<3;i++){
        h[i].push_back(b[i]);
    }

    cout<<forward_error(gaussian(h,3),organs);
}