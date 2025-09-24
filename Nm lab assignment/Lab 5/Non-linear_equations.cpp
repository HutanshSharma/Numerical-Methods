#include<bits/stdc++.h>
using namespace std;

vector<double> gaussian(vector<vector<double>>h,int size){
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

double f1(double x1,double x2, double x3){
    return (3*x1 - cosf(x2*x3) - 0.5);
}

double f2(double x1,double x2, double x3){
    return (pow(x1,2) - 81*pow((x2+0.1),2) + sinf(x3) +1.06);
}

double f3(double x1,double x2, double x3){
    return (exp(-1*x1*x2) + 20*x3 + (10*3.14 - 3)/3.0);
}

double df1x1(){
    return 3;
}

double df1x2(double x2,double x3){
    return (sinf(x2*x3)*x3);
}

double df1x3(double x2,double x3){
    return (sinf(x2*x3)*x2);
}

double df2x1(double x1){
    return (2*x1);
}

double df2x2(double x2){
    return (-162*(x2+0.1));
}

double df2x3(double x3){
    return cosf(x3);
}

double df3x1(double x1,double x2){
    return (exp(-1*x1*x2)*(-1*x2));
}

double df3x2(double x1,double x2){
    return (exp(-1*x1*x2)*(-1*x1));
}

double df3x3(){
    return 20;
}

vector<double> newton_raphson(vector<double>initialguess,int size){
    vector<vector<double>>jacobian(size,vector<double>(size));
    jacobian[0][0]=df1x1();
    jacobian[0][1]=df1x2(initialguess[1],initialguess[2]);
    jacobian[0][2]=df1x3(initialguess[1],initialguess[2]);
    jacobian[1][0]=df2x1(initialguess[0]);
    jacobian[1][1]=df2x2(initialguess[1]);
    jacobian[1][2]=df2x3(initialguess[2]);
    jacobian[2][0]=df3x1(initialguess[0],initialguess[1]);
    jacobian[2][1]=df3x2(initialguess[0],initialguess[1]);
    jacobian[2][2]=df3x3();

    vector<double>F(size);
    F[0]=f1(initialguess[0],initialguess[1],initialguess[2]);
    F[1]=f2(initialguess[0],initialguess[1],initialguess[2]);
    F[2]=f3(initialguess[0],initialguess[1],initialguess[2]);

    for(int i=0;i<size;i++){
        jacobian[i].push_back(F[i]);
    }

    vector<double>X = gaussian(jacobian,size);
    
    vector<double>newpoint(size,0);
    for(int i=0;i<size;i++){
        newpoint[i]=initialguess[i]-X[i];
    }
    return newpoint; 
}

int main(){
    vector<double>initialguess = {0.1,0.1,-0.1};
    double tol = 1e-6;

    for(int i=0;i<10000;i++){
        vector<double>prev = initialguess;
        initialguess = newton_raphson(initialguess,3);
        vector<double>l_infinity(3);
        
        for(int i=0;i<3;i++){
            l_infinity[i] = fabs(prev[i]-initialguess[i]);
        }
        double max_value = INT_MIN;
        for(auto i:l_infinity){
            max_value = max(i,max_value);
        }
        
        if(max_value<tol) break;
    }

    for(auto i:initialguess){
        cout<<i<<" ";
    }
    cout<<endl;
}