#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<iomanip>
using namespace std;
double fx1(double x2){
    return (8-x2)/3.0;
}

double fx2(double x1){
    return (20-5.0*x1)/5.0;
}

void jacobi(vector<double>&initialguess,int iter,double tol){
    ofstream outputfile("Gauss-Jacobi.txt");
    for(int i=0;i<iter;i++){
        pair<double,double>p1 = {initialguess[0],initialguess[1]};
        double x1=fx1(initialguess[1]);
        double x2=fx2(initialguess[0]);
        initialguess[0]=x1;
        initialguess[1]=x2;
        outputfile<<fixed<<setprecision(10)<<initialguess[0]<<','<<fixed<<setprecision(10)<<initialguess[1];
        if(fabs(p1.first-initialguess[0])<tol && fabs(p1.second-initialguess[1])<tol) break;
        outputfile<<endl;
    }
    outputfile.close();
}

int main(){
    double tol=1e-6;
    vector<double>initialguess={0,0};
    jacobi(initialguess,100,tol);
}