#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321, MAX_N = 2000;
int N, M;

struct DisJointSet {
  vector<int> parent, rank;
  DisJointSet(int N): parent(N), rank(N, 1) {
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

int kruskalMinUpperBound(const vector<pair<int, pair<int, int> > >& edges, const vector<int>& weights, int low) {
  DisJointSet sets(N);
  for(int i = 0; i < edges.size(); ++i) {
    if(edges[i].first < weights[low]) continue;
    sets.merge(edges[i].second.first, edges[i].second.second);
    if(sets.find(0) == sets.find(N-1)) 
      return edges[i].first;
  }
  return INF;
}

void solve() {
  cin >> N >> M;
  vector<pair<int, int> > adj[MAX_N];
  vector<int> weights;
  for(int i = 0; i < M; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back(make_pair(b, c));
    adj[b].push_back(make_pair(a, c));
    weights.push_back(c);
  }

  vector<pair<int, pair<int, int> > > edges;
  for(int u = 0; u < N; ++u)
    for(int i = 0; i < adj[u].size(); ++i) {
      int v = adj[u][i].first, cost = adj[u][i].second;
      edges.push_back(make_pair(cost, make_pair(u, v)));
    }
  sort(weights.begin(), weights.end());
  sort(edges.begin(), edges.end());

  int answer = INF;
  for(int i = 0; i < weights.size(); ++i)
    answer = min(answer, kruskalMinUpperBound(edges, weights, i) - weights[i]);
  cout << answer << "\n";
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
