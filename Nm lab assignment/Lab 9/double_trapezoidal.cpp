#include<bits/stdc++.h>
using namespace std;

double f(double x, double y){
    return pow(x,2)+pow(y,2);
}

int weights(double i,double j, int a, int b,int c, int d){
    if((i==a || i==b) && (j==c || j==d)) return 1;
    if(i==a || i==b || j==c || j==d) return 2;
    return 4;  
}

double trapezoidal(double m, double n, double a, double b, double c, double d){
    vector<vector<pair<double,double>>>v1(n+1,vector<pair<double,double>>(m+1));
    double hx = (b-a)/m;
    double hy = (d-c)/n; 
    double val_x =a;
    double val_y =c;

    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            v1[i][j] = {val_x,val_y};
            val_x+=hx;
        }
        val_x=0;
        val_y+=hy;
    }


    double sum =0;
    for(auto i:v1){
        for(auto j:i){
            int weight =weights(j.first,j.second,a,b,c,d) ;
            sum+= weight*f(j.first,j.second);
        }
    }

    double ans = sum*hx*hy/4;
    cout<<ans<<endl;

    double actual_ans = 10.67;
    double relative_err = fabs(ans-actual_ans)/actual_ans;
    return relative_err;
}

int main(){
    double m = 4.0;
    double n = 4.0;
    
    int a=0,b=2,c=0,d=2;
    while(1){
        double err = trapezoidal(m,m,a,b,c,d);
        if(err<1e-5){
            cout<<m<<" "<<n<<endl;
            break;
        }
        m*=2;
    }
    
}