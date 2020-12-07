#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, D, P, T;
double cache[51][101];

double memoized(const vector<vector<int> >& adj, const vector<int>& deg, int here, int days) {
  if(days == 0) return (here == P ? 1.0 : 0.0);

  double& ret = cache[here][days];
  if(ret > -0.5) return ret;

  ret = 0.0;
  for(int there = 0; there < N; ++there)
    if(adj[here][there])
      ret += memoized(adj, deg, there, days-1) / deg[there];
  return ret;
}

void solve() {
  memset(cache, -1.0, sizeof(cache));
  cin >> N >> D >> P;
  vector<vector<int> > adj(N, vector<int>(N, 0));
  vector<int> deg(N, 0);
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j) {
      cin >> adj[i][j];
      if(adj[i][j]) deg[i]++;
    }

  cin >> T;
  vector<double> answer;
  for(int i = 0; i < T; ++i) {
    int town; cin >> town;
    answer.push_back(memoized(adj, deg, town, D));
  }

  cout << fixed;
  cout.precision(8);

  for(int i = 0; i < T; ++i)
    cout << answer[i] << " ";
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
