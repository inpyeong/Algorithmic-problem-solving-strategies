#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 10000;
int N, e[MAX_N], m[MAX_N];

int heat() {
  vector<pair<int, int> > order;
  for (int i = 0; i < N; ++i)
    order.push_back(make_pair(-e[i], i));
  sort(order.begin(), order.end());
  int ret = 0, beginEat = 0;
  for (int i = 0; i < N; ++i) {
    int box = order[i].second;
    beginEat += m[box];
    ret = max(ret, beginEat + e[box]);
  }
  return ret;
}

void solve() {
  cin >> N;
  for (int i = 0; i < N; ++i)
    cin >> m[i];
  for (int i = 0; i < N; ++i)
    cin >> e[i];
  cout << heat() << "\n";
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
