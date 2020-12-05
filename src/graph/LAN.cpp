#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;

struct DisJointSet {
  vector<int> parent, rank;
  DisJointSet(int N) : parent(N), rank(N, 1) {
    for(int i = 0; i < N; ++i)
      parent[i] = i;
  }

  int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
  }

  void merge(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return;
    if(rank[u] > rank[v]) swap(u, v);
    parent[u] = v;
    if(rank[u] == rank[v]) rank[v]++;
  }
};

void makeGraph(vector<vector<double> >& adj) {
  // pair<x, y>
  vector<pair<int, int> > coords(N, make_pair(0, 0));
  for(int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    coords[i].first = x;
  }
  for(int i = 0; i < N; ++i) {
    int y;
    cin >> y;
    coords[i].second = y;
  }

  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      adj[i][j] = sqrt(pow(coords[i].first - coords[j].first, 2) + pow(coords[i].second - coords[j].second, 2));

  for(int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u][v] = adj[v][u] = 0;
  }
}

double kruskal(const vector<vector<double> >& adj, vector<pair<int, int> >& selected) {
  double ret = 0;
  selected.clear();

  vector<pair<double, pair<int, int> > > edges;
  for(int u = 0; u < N; ++u)
    for(int v = 0; v < N; ++v) {
      double cost = adj[u][v];
      edges.push_back(make_pair(cost, make_pair(u, v)));
    }

  sort(edges.begin(), edges.end());
  DisJointSet sets(N);
  for(int i = 0; i < edges.size(); ++i) {
    double cost = edges[i].first;
    int u = edges[i].second.first, v = edges[i].second.second;

    if(sets.find(u) == sets.find(v)) continue;
    sets.merge(u, v);
    selected.push_back(make_pair(u, v));
    ret += cost;
  }
  return ret;
}

void solve() {
  cin >> N >> M;
  vector<vector<double> > adj(N, vector<double>(N, 0));
  makeGraph(adj);

  vector<pair<int, int> > selected;
  double answer = kruskal(adj, selected);

  cout << fixed;
  cout.precision(10);
  cout << answer << "\n";
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
