#include <iostream>
#include <cmath>

using namespace std;

const double c = 300000000.0;
const double k = 0.05;
const double T = 780.0;
const double initial_guess = 1.0;

double f(double a) {
    return a/c+k*log2(a)-T;
}

double df(double a) {
    return 1.0/c+k/(a*log(2.0));
}

double newtonRaphson(double initial_guess, double tol=1e-6, int max_iter=100) {
    double point=initial_guess;
    for (int i=0;i<max_iter;++i) {
        double f_val=f(point);
        double df_val=df(point);
        
        if (df_val==0.0) {
            cout<<"Zero derivative";
            return -1;
        }

        double new_point=point-f_val/df_val;
        if (fabs(new_point -point) < tol) {
            return new_point;
        }
        point=new_point;

    }
    cout<<"Exceeded maximum iterations";
    return -1;
}

int main() {
    double root=newtonRaphson(initial_guess);
    if (root!=-1)
        cout<<root;
    return 0;
}