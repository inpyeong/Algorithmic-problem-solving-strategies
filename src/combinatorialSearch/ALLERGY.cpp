#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n, m;
// canEat[i]: i번 친구가 먹을 수 있는 음식의 집합
// eaters[i]: i번 음식을 먹을 수 있는 친구들의 집합
vector<int> canEat[50], eaters[50];
int best;

void clear() {
  for(int i = 0; i < n; ++i)
    canEat[i].clear();
  for(int i = 0; i < m; ++i)
    eaters[i].clear();
}

void search(vector<int>& edible, int chosen) {
  // 가지치기
  if(chosen >= best) return;
  // 아직 먹을 음식이 없는 첫 번째 친구
  int first = 0;
  while(first < n && edible[first] > 0) ++first;
  if(first == n) { best = chosen; return; }

  for(int i = 0; i < canEat[first].size(); ++i) {
    int food = canEat[first][i];
    for(int j = 0; j < eaters[food].size(); ++j)
      edible[eaters[food][j]]++;
    search(edible, chosen+1);
    for(int j = 0; j < eaters[food].size(); ++j)
      edible[eaters[food][j]]--;
  }
}

void solve() {
  cin >> n >> m;
  map<string, int> index;
  for(int i = 0; i < n; ++i) {
    string name; cin >> name;
    index[name] = i;
  }
  for(int i = 0; i < m; ++i) {
    int numOfPeople; cin >> numOfPeople;
    for(int j = 0; j < numOfPeople; ++j) {
      string name; cin >> name;
      eaters[i].push_back(index[name]);
      canEat[index[name]].push_back(i);
    }
  }
  vector<int> edible(n, 0);
  best = m;
  search(edible, 0);
  cout << best << "\n";
  clear();
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
