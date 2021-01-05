#include <iostream>
#include <vector>

using namespace std;

int n, m;

bool decision(const vector<double>& locations, double gap) {
    // 카메라를 설치할 수 있을 때마다 설치하는 탐욕적 알고리즘
    double limit = -1;
    int installed = 0;
    for(int i = 0; i < locations.size(); ++i) {
        if(limit <= locations[i]) {
            ++installed;
            // locations[i] + gap 이후는 되어야 카메라를 설치할 수 있다.
            limit = locations[i] + gap;
        }
    }
    // 결과적으로 카메라를 n 이상 설치할 수 있었으면 성공
    return installed >= n;
}

double optimize(const vector<double>& locations) {
    double lo = 0, hi = 241;
    for(int it = 0; it < 100; ++it) {
        double mid = (lo + hi) / 2;
        if(decision(locations, mid))
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}

void solve() {
    cin >> n >> m;
    vector<double> locations;
    for(int i = 0; i < m; ++i) {
        double location; cin >> location;
        locations.push_back(location);
    }
    cout << fixed;
    cout.precision(2);
    cout << optimize(locations) << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}