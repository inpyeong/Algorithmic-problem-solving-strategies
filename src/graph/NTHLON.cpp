#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, V;
vector<pair<int, int> > adj[410];
const int START = 401, INF = 987654321;

int vertex(int delta) {
  return delta + 200;
}

vector<int> dijkstra(int start) {
  priority_queue<pair<int, int> > pq;
  vector<int> dist(V, INF);

  pq.push(make_pair(0, start));
  dist[start] = 0;
  while(!pq.empty()) {
    int here = pq.top().second;
    int cost = -pq.top().first;
    pq.pop();
    if(dist[here] < cost) continue;
    for(int i = 0; i < adj[here].size(); ++i) {
      int there = adj[here][i].first;
      int nextDist = cost + adj[here][i].second;
      if(dist[there] > nextDist) {
        dist[there] = nextDist;
        pq.push(make_pair(-nextDist, there));
      }
    }
  }
  return dist;
}

void solve() {
  cin >>  M;
  vector<int> a(M, 0), b(M, 0);

  for(int i = 0; i < M; ++i)
    cin >> a[i] >> b[i];

  V = 402;
  for(int i = 0; i < V; ++i) adj[i].clear();
  for(int i = 0; i < a.size(); ++i) {
    int delta = a[i] - b[i];
    adj[START].push_back(make_pair(vertex(delta), a[i]));
  }

  for(int delta = -200; delta <= 200; ++delta) {
    for(int i = 0; i < a.size(); ++i) {
      int next = delta + a[i] - b[i];
      if(abs(next) > 200) continue;
      adj[vertex(delta)].push_back(make_pair(vertex(next), a[i]));
    }
  }

  vector<int> shortest = dijkstra(START);
  int ret = shortest[vertex(0)];
  if(ret == INF) 
    cout << "IMPOSSIBLE" << '\n';
  else
    cout << ret << '\n';
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
