#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

double dist[101][101];
int N;

bool decision(double d) {
    vector<bool> visited(N, false);
    visited[0] = true;
    queue<int> q;
    q.push(0);
    int seen = 0;
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        ++seen;
        for(int there = 0; there < N; ++there) {
            if(!visited[there] && dist[here][there] <= d) {
                visited[there] = true;
                q.push(there);
            }
        }
    }
    return seen == N;
}

double optimize(const vector<pair<double, double> >& locations) {
    double lo = 0, hi = 1416.00;
    for(int it = 0; it < 100; ++it) {
        double mid = (lo + hi) / 2;
        // 만약 현재 무전기 출력 길이가 가능한 경우
        if(decision(mid))
            hi = mid;
        // 그렇지 않으면 무전기 출력 길이를 늘린다.
        else
            lo = mid;
    }
    return hi;
}

void solve() {
    cin >> N;
    vector<pair<double, double> > locations(N, make_pair(0, 0));
    for(int i = 0; i < N; ++i)
        cin >> locations[i].first >> locations[i].second;

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            dist[i][j] = sqrt(pow(locations[i].first - locations[j].first, 2) + pow(locations[i].second - locations[j].second, 2));

    cout << fixed;
    cout.precision(2);
    cout << optimize(locations) << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}