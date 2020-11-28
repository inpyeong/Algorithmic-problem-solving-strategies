#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX_V = 100, MAX_W = 1000, INF = 987654321;
int V, W;
vector<pair<int, int> > adj[MAX_V];
bool reachable[MAX_V][MAX_V];

int bellmanFord(int src, int target) {
  vector<int> upper(V, INF);
  upper[src] = 0;

  for(int iter = 0; iter < V-1; ++iter)
    for(int here = 0; here < V; ++here)
      for(int i = 0; i < adj[here].size(); ++i) {
        int there = adj[here][i].first;
        int cost = adj[here][i].second;
        upper[there] = min(upper[there], upper[here] + cost);
      }
      

  for(int here = 0; here < V; ++here)
    for(int i = 0; i < adj[here].size(); ++i) {
      int there = adj[here][i].first;
      int cost = adj[here][i].second;
      if(upper[there] > upper[here] + cost)
        if(reachable[src][here] && reachable[here][target])
          return -INF;
    }
  return upper[target];
}

string solve() {
  cin >> V >> W;
  for(int i = 0; i < W; ++i) {
    int a, b, d;
    cin >> a >> b >> d;
    adj[a].push_back(make_pair(b, d));
    reachable[a][b] = true;
  }
  int minDist = bellmanFord(0, 1);
  for(int i = 0; i < V; ++i) 
    for(int j = 0; j < adj[i].size(); ++j) 
      adj[i][j].second *= -1;
  int maxDist = -bellmanFord(0, 1); 

  if(minDist == -INF && maxDist == INF)
    return "UNREACHABLE";

  string pre = minDist == -INF ? "INFINITY" : to_string(minDist);
  string post = maxDist == INF ? "INFINITY" : to_string(maxDist);
  return pre + " " + post;
}

int main() {
  int t;
  cin >> t;
  while(t--) cout << solve() << "\n";
}
