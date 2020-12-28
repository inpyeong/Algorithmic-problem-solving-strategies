#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX_M = 50;

int n, m;
int answer;
bool used[50];

bool isGood(vector<pair<string, bool> >& friends, const vector<vector<string> >& foods) {
  for(int i = 0; i < m; ++i) {
    if(used[i]) {
      for(int j = 0; j < foods[i].size(); ++j) {
        for(int k = 0; k < friends.size(); ++k)
          if(friends[k].first == foods[i][j]) friends[k].second = true;
      }
    }
  }
  bool ret = true;
  for(int i = 0; i < friends.size(); ++i) 
    if(!friends[i].second) ret = false;
  return ret;
}

void search(vector<pair<string, bool> >& friends, const vector<vector<string> >& foods, int cnt) {
  // 기저사례
  if(cnt > foods.size()) return;

  if(isGood(friends, foods)) {
    answer = min(answer, cnt);
    return;
  }
  
  for(int i = 0; i < foods.size(); ++i) {
    if(!used[i]) {
      used[i] = true;
      search(friends, foods, ++cnt);
      used[i] = false;
    }
  }
}

void solve() {
  cin >> n >> m;
  answer = MAX_M;
  for(int i = 0; i < m; ++i)
    used[i] = false;
  vector<pair<string, bool> > friends(n, make_pair("", false));
  vector<vector<string> > foods(m);
  for(int i = 0; i < n; ++i)
    cin >> friends[i].first;
  for(int i = 0; i < m; ++i) {
    int numOfFriends; cin >> numOfFriends;
    for(int i = 0; i < numOfFriends; ++i) {
      string name; cin >> name;
      foods[i].push_back(name);
    }
  }
  search(friends, foods, 0);
  cout << answer << "\n";
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
