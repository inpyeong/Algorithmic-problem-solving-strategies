#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N;

int order(const vector<int>& russian, const vector<int> korean) {
  int wins = 0;
  multiset<int> ratings(korean.begin(), korean.end());
  for(int rus = 0; rus < N; ++rus) {
    if(*ratings.rbegin() < russian[rus])
      ratings.erase(ratings.begin());
    else {
      ratings.erase(ratings.lower_bound(russian[rus]));
      wins++;
    }
  }
  return wins;
}

void solve() {
  cin >> N;
  vector<int> russian, korean;
  int rating;
  for(int i = 0; i < N; ++i) {
    cin >> rating;
    russian.push_back(rating);
  }
  for(int i = 0; i < N; ++i) {
    cin >> rating;
    korean.push_back(rating);
  }
  cout << order(russian, korean) << "\n";
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
