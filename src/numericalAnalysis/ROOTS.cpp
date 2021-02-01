#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

const double L = 10;

int N;

vector<double> solveNative(const vector<double>& poly) {
    int n = poly.size() - 1;
    vector<double> ret;
    switch(n) {
        case 1:
            ret.push_back(-poly[1] / poly[0]);
            break;
        case 2:
            double a = poly[0], b = poly[1], c = poly[2];
            ret.push_back((-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a));
            ret.push_back((-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a));
            break;
    }
    sort(ret.begin(), ret.end());
    return ret;
}

vector<double> differentiate(const vector<double>& poly) {
    int n = poly.size() - 1;
    vector<double> ret;
    for(int i = 0; i < n; ++i)
        ret.push_back((n - i) * poly[i]);
    return ret;
}

double evaluate(const vector<double>& poly, double x) {
    int n = poly.size() - 1;
    double ret = 0;
    for(int i = 0; i <= n; ++i)
        ret += pow(x, n - i) * poly[i];
    return ret;
}

vector<double> solve(const vector<double>& poly) {
    int n = poly.size() - 1;
    if(n <= 2) return solveNative(poly);
    vector<double> derivative = differentiate(poly);
    vector<double> sols = solve(derivative);

    sols.insert(sols.begin(), -L-1);
    sols.insert(sols.end(), L+1);
    vector<double> ret;
    for(int i = 0; i+1 < sols.size(); ++i) {
        double x1 = sols[i], x2 = sols[i+1];
        double y1 = evaluate(poly, x1), y2 = evaluate(poly, x2);
        if(y1*y2 > 0) continue;
        // 불변 조건: f(x1) <= 0 < f(x2)
        if(y1 > y2) { swap(y1, y2); swap(x1, x2); }
        for(int iter = 0; iter < 100; ++iter) {
            double mx = (x1 + x2) / 2;
            double my = evaluate(poly, mx);
            if(y1*my > 0) {
                y1 = my;
                x1 = mx;
            }
            else {
                y2 = my;
                x2 = mx;
            }
        }
        ret.push_back((x1 + x2) / 2);
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<double> poly;
        for(int i = 0; i <= n; ++i) {
            double coef;
            cin >> coef;
            poly.push_back(coef);
        }
        vector<double> ret = solve(poly);
        cout << fixed << setprecision(12);
        for(int i = 0; i < ret.size(); ++i)
            cout << ret[i] << " ";
        cout << "\n";
    }
}