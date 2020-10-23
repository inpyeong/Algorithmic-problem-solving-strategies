#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int MAX_N = 10000, MAX_M = 20000, INF = 987654321;
int n, m;

vector<pair<int, double> > adj[MAX_N];
vector<double> dist(MAX_N, INF);

void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int a, b;
        double c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }

    priority_queue<pair<double, int> > pq;
    int start = 0;
    dist[start] = 1;
    pq.push(make_pair(-1, 0));
    while(!pq.empty()) {
        double cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        for(int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].first;
            double thereCost = adj[here][i].second * cost;
            if(dist[there] > thereCost) {
                dist[there] = thereCost;
                pq.push(make_pair(-thereCost, there));
            }
        }
    }
    printf("%.10f", dist[n-1]);
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}