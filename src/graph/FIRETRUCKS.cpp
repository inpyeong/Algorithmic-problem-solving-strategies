#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>

using namespace std;

const int MAX_V = 1000;
const int INF = 987654321;
int v, e, n, m;
vector<pair<int, int> > adj[MAX_V+1];
vector<int> dist(MAX_V+1, INF);

void solve() {
    cin >> v >> e >> n >> m;
    for(int i = 0; i < e; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        adj[a].push_back(make_pair(b, t));
        adj[b].push_back(make_pair(a, t));
    }
    vector<int> firePlaces;
    vector<int> fireStations;
    for(int i = 0; i < n; ++i) {
        int firePlace;
        cin >> firePlace;
        firePlaces.push_back(firePlace);
    }     
    for(int i = 0; i < m; ++i) {
        int fireStation;
        cin >> fireStation;
        fireStations.push_back(fireStation);
        adj[0].push_back(make_pair(fireStation, 0));
        adj[fireStation].push_back(make_pair(0, 0));
    }
    priority_queue<pair<int, int> > pq;

    // 임의의 시작점
    int start = 0;
    pq.push(make_pair(0, start));
    dist[0] = 0;
    while(!pq.empty()) {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        for(int j = 0; j < adj[here].size(); ++j) {
            int there = adj[here][j].first;
            int newCost = cost + adj[here][j].second;
            if(dist[there] > newCost) {
                dist[there] = newCost;
                pq.push(make_pair(-newCost, there));
            }
        }
    }

    int answer = 0;
    for(int i = 0; i < n; ++i) 
        answer += dist[firePlaces[i]];
    cout << answer << endl; 
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}