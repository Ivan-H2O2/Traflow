#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define M_PI 3.141592653589793

int main(){
    double h0 = 20;
    double u1 = 20;
    double u0 = 15;
    double Alpha = 8;
    double dt = 0.01;
    double T = 60;
    int tn = T / dt;

    double Tao = 0.19 / dt;

    vector<vector<double>> x(tn + 1, vector<double>(2));
    x[0] = {h0, 0};
    vector<vector<double>> v(tn + 1, vector<double>(2));
    v[0] = {u1, u0};
    vector<vector<double>> a(tn + 1, vector<double>(2));

    for (int i = 1; i <= tn; i++) {
        for (int n = 0; n < 2; n++) {
            x[i][n] = x[i - 1][n] + dt * v[i - 1][n];
            v[i][n] = v[i - 1][n] + dt * a[i - 1][n];
        }

        double Vn_1, Vn;
        if (i <= Tao + 1) {
            Vn_1 = v[0][0];
            Vn = v[0][1];
        }
        else {
            Vn_1 = v[i - Tao][0];
            Vn = v[i - Tao][1];
        }

        a[i][1] = Alpha * (Vn_1 - Vn);
    }

    for (int i = 0; i <= tn; i++) {
        cout << (i * dt) << " " << v[i][0] << " " << v[i][1] << endl;
    }

    cout << "1/Alpha*e=" << (1 / Alpha / 2.71828) << "  pi/2*Alpha=" << (M_PI / Alpha / 2) << endl;

    return 0;
}
