#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int G, H, cnt;
vector<vector<int> > adj;
vector<bool> isCutVertex;
vector<int> discovered;

void makeGraph() {
  adj = vector<vector<int> >(G, vector<int>(G, 0));
  isCutVertex = vector<bool>(G, false);
  discovered = vector<int>(G, -1);
  cnt = 0;

  for(int i = 0; i < H; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u][v]++;
    adj[v][u]++;
  }
}

// 역방향 간선을 통해 이동할 수 있는 정점의 최소 접근순서를 반환한다.
int findCutVertex(int here, bool isRoot) {
  int ret = discovered[here] = cnt++;
  int children = 0;
  for(int there = 0; there < adj[here].size(); ++there) {
    if(adj[here][there]) {
      if(discovered[there] != -1) {
        children++;
        ret = min(ret, findCutVertex(there, false));
      } 
      ret = min(ret, discovered[there]);
    }
  }
  if(ret >= discovered[here]) {
    isCutVertex[here] = true;
  }
  if(isRoot) isCutVertex[here] = (children >= 2);
  return ret;
}

void solve() {
  cin >> G >> H;
  makeGraph();
  for(int i = 0; i < G; ++i)
    if(discovered[i] == -1) findCutVertex(i, true);
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
