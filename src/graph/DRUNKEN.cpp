#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int V, E;
vector<vector<int> > adj;
int delay[500];
int W[500][500];

int main() {
  cin >> V >> E;
  adj = vector<vector<int> >(V, vector<int>(V, INF));
  for(int i = 0; i < V; ++i)
    cin >> delay[i];
  for(int i = 0; i < E; ++i) {
    int u, v, cost;
    cin >> u >> v >> cost;
    adj[u-1][v-1] = adj[v-1][u-1] = cost;
  }

  for(int i = 0; i < V; ++i)
    for(int j = 0; j < V; ++j) {
      if(i == j) {
        adj[i][j] = 0;
        W[i][j] = 0;
      }
      else
        W[i][j] = adj[i][j];
    }

  vector<pair<int, int> > order;
  for(int i = 0; i < V; ++i) 
    order.push_back(make_pair(delay[i], i));
  sort(order.begin(), order.end());

  for(int k = 0; k < V; ++k) {
    int w = order[k].second;
    for(int i = 0; i < V; ++i)
      for(int j = 0; j < V; ++j) {
        adj[i][j] = min(adj[i][j], adj[i][w] + adj[w][j]);
        W[i][j] = min(W[i][j], adj[i][w] + delay[w] + adj[w][j]);
      }
  }

  int t;
  cin >> t;
  while(t--) {
    int u, v;
    cin >> u >> v;
    cout << W[u-1][v-1] << "\n";
  }
}
