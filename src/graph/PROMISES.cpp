#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int V, M, N;
vector<vector<int> > adj;

void floyd() {
  for(int k = 0; k < V; ++k)
    for(int i = 0; i < V; ++i)
      for(int j = 0; j < V; ++j)
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

bool update(int u, int v, int cost) {
  if(adj[u][v] <= cost) return false;
  for(int i = 0; i < V; ++i)
    for(int j = 0; j < V; ++j)
      adj[i][j] = min(adj[i][j], 
                      min(adj[i][u] + cost + adj[v][j],
                          adj[i][v] + cost + adj[u][j]));
  return true;
}

void solve() {
  cin >> V >> M >> N;
  adj = vector<vector<int> >(V, vector<int>(V, INF));
  for(int i = 0; i < V; ++i)
    adj[i][i] = 0;

  int u, v, cost;
  for(int i = 0; i < M; ++i) {
    cin >> u >> v >> cost;
    adj[u][v] = adj[v][u] = cost;
  }
  floyd();
  
  int ret = 0;
  for(int i = 0; i < N; ++i) {
    cin >> u >> v >> cost;
    if(!update(u, v, cost)) ret++;
  }
  cout << ret << "\n";
}

int main() {
  int t;
  cin >> t;
  while(t--)
    solve();
}
