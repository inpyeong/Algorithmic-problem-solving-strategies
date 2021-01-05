#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int l[5000], m[5000], g[5000];

// 결정문제: dist 지점까지 가면서 k개 이상의 표지판을 만날 수 있는가?
bool decision(int dist) {
    int ret = 0;
    for(int i = 0; i < n; ++i)
        if(dist >= l[i] - m[i])
            ret += (min(dist, l[i]) - (l[i] - m[i])) / g[i] + 1;
    return ret >= k;
}

int optimize() {
    int lo = -1, hi = 8030001;
    while(lo+1 < hi) {
        int mid = (lo + hi) / 2;
        if(decision(mid))
            hi = mid;
        else
            lo = mid;
    }
    return hi;
}

void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        cin >> l[i] >> m[i] >> g[i];
    cout << optimize() << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}